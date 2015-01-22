#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <stack>
#include <algorithm>

template <typename T>
T evaluate_prefix_expression_stack(std::string line)
{
    std::stack<std::string> tokens;
    std::istringstream iss(line);
    std::stack<T> nums;
    while (true) {
        std::string s;
        iss >> s;
        if (iss.fail()) {
            break;
        }
        tokens.push(s);
    }
    while (tokens.size() != 0) {
        std::string s = tokens.top();
        tokens.pop();
        char c = s[0];
        if (c == '*' || c == '+' || c == '-' || c == '/') {
            T a = nums.top();
            nums.pop();
            T b = nums.top();
            nums.pop();
            if (c == '+') {
                nums.push(a + b);
            } else if (c == '-') {
                nums.push(a - b);
            } else if (c == '*') {
                nums.push(a * b);
            } else if (c == '/') {
                nums.push(a / b);
            } else {
                throw std::runtime_error("No known operator.");
            }
        } else {
            nums.push(atoi(s.c_str()));
        }
    }
    if (nums.size() != 1) {
        throw std::runtime_error("Wrong stack size.");
    }
    return nums.top();
}

template <typename T>
T evaluate_prefix_expression(std::istream &is)
{
    std::string s;
    T r;
    is >> s;
    if (is.fail()) {
        throw std::runtime_error("No chars in stream.");
    }
    if (s[0] == '*') {
        T a = evaluate_prefix_expression<T>(is);
        T b = evaluate_prefix_expression<T>(is);
        r = a * b;
    } else if (s[0] == '+') {
        T a = evaluate_prefix_expression<T>(is);
        T b = evaluate_prefix_expression<T>(is);
        r = a + b;
    } else if (s[0] == '-') {
        T a = evaluate_prefix_expression<T>(is);
        T b = evaluate_prefix_expression<T>(is);
        r = a - b;
    } else if (s[0] == '/') {
        T a = evaluate_prefix_expression<T>(is);
        T b = evaluate_prefix_expression<T>(is);
        r = a / b;
    } else {
        r = atoi(s.c_str());
    }
    return r;
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
        // std::istringstream iss(line);
        if (f.fail()) {
            break;
        }
        // std::cout << evaluate_prefix_expression<size_t>(iss) << '|';
        double r = evaluate_prefix_expression_stack<double>(line);
        int result = static_cast<int>(r);
        if (r - result >= 0.5) {
            result++;
        }
        std::cout << result << '\n';
    }

    return 0;
}

