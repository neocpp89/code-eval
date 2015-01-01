#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    std::string line;
    int iter = 0;
    while (true) {
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        if (line.size() == 0) {
            continue;
        }
        if (iter != 0) {
            std::cout << '\n';
        }
        std::stringstream ss(line);
        std::stack<std::string> s;
        while (true) {
            std::string word;
            ss >> word;
            if (ss.fail()) {
                break;
            }
            if (word.size() == 0) {
                continue;
            }
            s.push(word);
        }
        while (s.size() > 1) {
            std::cout << s.top() << ' ';
            s.pop();
        }
        if (s.size() == 1) {
            std::cout << s.top();
            s.pop();
        }
        iter++;
    }

    return 0;
}

