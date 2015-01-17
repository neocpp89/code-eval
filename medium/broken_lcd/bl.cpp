#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

const int lcd_digits[] = {
    0xFC,
    0x60,
    0xDA,
    0xF2,
    0x66,
    0xB6,
    0xBC,
    0xE0,
    0xFE,
    0xF6
};

bool cmp(const std::string &a, const std::string &b)
{
    return (a.size() >= b.size());
}

int displayable(const std::vector<int> &lcd_state, const std::vector<int> &wanted_lcd_state)
{
    size_t maxi = (lcd_state.size() - wanted_lcd_state.size());
    for (size_t i = 0; i < maxi; i++) {
        bool passed = true;
        for (size_t j = 0; j < wanted_lcd_state.size(); j++) {
            if ((wanted_lcd_state[j] & lcd_state[i+j]) != wanted_lcd_state[j]) {
                // std::cout << "broke on: " << wanted_lcd_state[j] << " != " << lcd_state[i+j] << '\n';
                passed = false;
                break;
            }
        }
        if (passed) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    std::string line;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        size_t s = line.find_first_of(';');
        std::istringstream iss(line.substr(0,s));
        std::string todisplay = line.substr(s+1);
        std::vector<int> wanted_lcd_state;
        for (size_t i = 0; i < todisplay.size(); i++) {
            if (todisplay[i] == '.') {
                if (i == 0) {
                    wanted_lcd_state.push_back(0x01);
                } else {
                    wanted_lcd_state.back() |= 0x01;
                }
            } else {
                wanted_lcd_state.push_back(lcd_digits[todisplay[i] - '0']);
            }
            // std::cout << wanted_lcd_state.back() << '\n';
        }
        std::vector<int> lcd_state;
        while (true) {
            std::string x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            int digit = strtol(x.c_str(), NULL, 2);
            // std::cout << digit << '\n';
            lcd_state.push_back(digit);
        }
        std::cout << displayable(lcd_state, wanted_lcd_state) << '\n';
    }
    return 0;
}

