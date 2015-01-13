#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <numeric>

std::string dumb_substitute(const std::string &str, size_t start, size_t stop, const std::string &to)
{
    return str.substr(0, start) + to + str.substr(stop);
}

void mark_unmodifiable(std::vector<char> &modifiable, size_t start, size_t stop, const std::string to)
{
    std::vector<char> m;
    for (size_t i = 0; i < start; i++) {
        m.push_back(modifiable[i]);
    }
    for (size_t i = 0; i < to.size(); i++) {
        m.push_back(0);
    }
    for (size_t i = stop; i < modifiable.size(); i++) {
        m.push_back(modifiable[i]);
    }
    std::swap(modifiable, m);
    return;
}

std::string substitute(const std::string &str, const std::vector<std::pair<std::string, std::string> > &array)
{
    std::vector<char> modifiable(str.size(), 1);
    std::string ret = str;
    std::vector<std::pair<std::string, std::string> >::const_iterator it = array.begin();
    for (;it != array.end(); it++) {
        const std::string &fs = (*it).first;
        const std::string &rs = (*it).second;
        //std::cout << fs << ':' << rs << ' ';
        _start:
        for (size_t i = 0; i < (ret.size() - fs.size() + 1); i++) {
            bool replace = true;
            for (size_t j = 0; j < fs.size(); j++) {
                if (ret[i+j] != fs[j] || modifiable[i+j] != 1) {
                    replace = false;
                    break;
                }
            }
            if (replace) {
                ret = dumb_substitute(ret, i, i+fs.size(), rs);
                mark_unmodifiable(modifiable, i, i+fs.size(), rs);
                //std::cout << '[' << ret << "]\n";
                goto _start;
            }
        }
    }
    return ret;
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

        size_t s1 = line.find_first_of(';');
        size_t s2 = line.find_last_of(';');
        std::string original = line.substr(0,s1).c_str();
        std::string subs = line.substr(s2+1);

        std::istringstream iss(subs);
        std::vector<std::pair<std::string, std::string> > array;
        while(true) {
            std::string tofind;
            std::getline(iss, tofind, ',');
            std::string replacewith;
            std::getline(iss, replacewith, ',');
            if (iss.fail()) {
                break;
            }
            array.push_back(std::make_pair(tofind, replacewith));
        }
        /*
        std::cout << original << ' ';
        std::vector<char> modifiable(original.size(), 1);
        mark_unmodifiable(modifiable, 4, 4+3, "A");
        std::cout << dumb_substitute(original, 4, 4+3, "A") << '/';
        for (size_t i = 0; i < modifiable.size(); i++) {
            std::cout << (int)modifiable[i];
        }
        std::cout << '.';
        std::vector<std::pair<std::string, std::string> >::iterator it = array.begin();
        for (;it != array.end(); it++) {
            std::cout << (*it).first << ':' << (*it).second << ' ';
        }
        */
        std::cout << substitute(original, array);
        std::cout << '\n';
    }

    return 0;
}

