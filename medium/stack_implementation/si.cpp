#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

template <typename T>
class Stack
{
    private:
        std::vector<T> data;
    public:
        void push(T &item)
        {
            data.insert(data.end(), item);
            return;
        }

        T pop()
        {
            T r = data.back();
            if (data.size() > 0) {
                data.erase(data.end() - 1);
            }
            return r;
        }

        size_t size() { return data.size(); }
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }
    std::ifstream f(argv[1]);
    while (true) {
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        Stack<int> s;
        while (true) {
            int x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            s.push(x);
        }
        std::cout << s.pop();
        s.pop();
        while (s.size() > 0) {
            std::cout << ' ' << s.pop();
            s.pop();
        }
        std::cout << '\n';
    }
    return 0;
}

