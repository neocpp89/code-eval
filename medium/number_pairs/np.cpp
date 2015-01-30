#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
//#include <utility>

bool binary_search(std::vector<int> &v, int num)
{
    size_t low = 0;
    size_t high = v.size()-1;
    if (v[low] > num || v[high] < num) {
        return false;
    }
    while (low <= high) {
        size_t mid = (high - low) / 2 + low;
        if (v[mid] > num) {
            high = mid-1;
        } else if (v[mid] < num) {
            low = mid+1;
        } else {
            //v[mid] == num
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
        size_t s = line.find(';');
        std::string ss = line.substr(0, s);
        int n = atoi(line.substr(s+1).c_str());
        std::vector<int> A;
        while (true) {
            int idx = ss.find(',');
            if (idx == std::string::npos) {
                break;
            }
            int a = atoi(ss.substr(0, idx).c_str());
            A.push_back(a);
            ss = ss.substr(idx+1);
        }
        int a = atoi(ss.c_str());
        A.push_back(a);
        //std::vector<std::pair<int,int> > pairs;
        int count = 0;
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i] > n/2) {
                break;
            }
            if (2 * A[i] == n) {
                break;
            }
            bool found = binary_search(A, n - A[i]);
            if (found) {
                if (count != 0) {
                    std::cout << ';';
                }
                std::cout << A[i] << ',' << n - A[i];
                count++;
            }
        }
        if (count == 0) {
            std::cout << "NULL";
        }
        std::cout << '\n';
    }
    return 0;
}

