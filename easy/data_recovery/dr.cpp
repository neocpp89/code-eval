#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

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
        size_t sp = line.find_last_of(';');
        std::string words = line.substr(0, sp);
        std::istringstream iss(words);
        std::vector<std::string> ss;
        while (true) { 
            std::string x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            ss.push_back(x);
        }

        std::string inds = line.substr(sp+1);
        std::istringstream issp(inds);
        std::vector<size_t> ps;
        while (true) {
            int x;
            issp >> x;
            if (issp.fail()) {
                break;
            }
            ps.push_back(x-1);
        }
        size_t expect = (ss.size() - 1) * ss.size() / 2;
        int missing = expect - std::accumulate(ps.begin(), ps.end(), 0);
        ps.push_back(missing);

        std::vector<std::string> reconstructed(ps.size());
        for (size_t i = 0; i < ps.size(); i++) {
            reconstructed[ps[i]] = ss[i];
        }

        if (ps.size() > 0) {
            for (size_t i = 0; i < ps.size() - 1; i++) {
                std::cout << reconstructed[i] << ' ';
            }
            std::cout << reconstructed[ps.size()-1] << '\n';
        }
    }

    return 0;
}

