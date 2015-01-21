#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

template <typename Iter>
int num_seq_repeats(Iter begin, Iter end, std::vector<unsigned char> &to_search)
{
    size_t dist = std::distance(begin, end);
    int c = 0;
    for (size_t i = 0; i < (to_search.size() - dist); i++) {
        Iter b = begin;
        bool passed = true;
        for (size_t j = 0; j < dist; j++) {
            if (*b != to_search[i+j]) {
                passed = false;
                break;
            }
            b++;
        }
        if (passed) {
            c++;
        }
    }
    return c;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        size_t word_len;
        std::string dummy;
        unsigned char last_char;
        iss >> word_len;
        iss >> dummy;
        iss >> last_char;
        iss >> dummy;
        std::vector<unsigned char> seq;
        while (true) {
            int c;
            iss >> c;
            if (iss.fail()) {
                break;
            }
            seq.push_back(static_cast<unsigned char>(c));
        }

        std::map<unsigned char, int> m;
        for (size_t i = 0; i < seq.size(); i++) {
            m[seq[i]]++;
        }
        int mc = 0;
        unsigned char mch = 0;
        for (std::map<unsigned char, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second > mc) {
                mc = it->second;
                mch = it->first;
            }
        }
        
        char diff = mch - ' ';
        /*
        std::cout << '|' << static_cast<int>(diff) << "|\n";
        */
        /*
        for(std::vector<unsigned char>::iterator it = seq.begin(); it != (seq.end() - word_len); it++) {
            if(num_seq_repeats(it, it+word_len, seq) == 2) {
                diff = *(it+word_len-1) - last_char;
                break;
            }
        }
        */
        for(std::vector<unsigned char>::iterator it = seq.begin(); it != seq.end(); it++) {
            *it -= diff;
        }
        
        for(std::vector<unsigned char>::iterator it = seq.begin(); it != seq.end(); it++) {
            std::cout << *it;
        }
        std::cout << '\n';
    }

    return 0;
}

