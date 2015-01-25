#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file
    std::cout << std::fixed;
    std::cout << std::setprecision(3);

    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        std::vector<double> numbers;
        while (true) {
            double x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            numbers.push_back(x);
        }
        std::sort(numbers.begin(), numbers.end());
        if (numbers.size() > 0) {
            std::cout << numbers[0];
            for (size_t i = 1; i < numbers.size(); i++) {
                std::cout << ' ' << numbers[i];
            }
        }
        std::cout << '\n';
    }

    return 0;
}

