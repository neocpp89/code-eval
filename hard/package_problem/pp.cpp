#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <set>

std::ostream &operator<<(std::ostream &os, std::set<int> &s)
{
    for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
        os << *it << ',';
    }
    return os;
}

float calculate_weight(std::set<int> &s, const std::vector<std::pair<float, float> > &items)
{
    float w = 0;
    std::set<int>::iterator it = s.begin();
    while (it != s.end()) {
        w += items[*it].first;
        it++;
    }
    return w;
}

void find_best_set(std::set<int> &s, const std::vector<std::pair<float, float> > &items, float capacity, float &price)
{
    if (capacity <= 0) {
        price = 0;
        return;
    }
    float best = price;
    std::set<int> sbest = s;
    for (size_t i = 0; i < items.size(); i++) {
        if (s.count(i) == 0) {
            std::set<int> sc = s;
            float pc = price + items[i].second;
            float cc = capacity - items[i].first;
            if (cc > 0) {
                sc.insert(i);
                find_best_set(sc, items, cc, pc);
                if (pc > best) {
                    best = pc;
                    sbest = sc;
                }
                if (pc == best && calculate_weight(sc, items) < calculate_weight(sbest, items)) {
                    sbest = sc;
                }
            }
        }
    }
    price = best;
    s = sbest;
    return;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    int lines = 0;
    while (true) {
        int weight;
        f >> weight;
        std::string c;
        f >> c; //discard colon
        std::string line;
        std::getline(f, line);
        if (f.fail()) {
            break;
        }
        std::istringstream iss(line);
        std::vector<std::pair<float, float> > items;
        while (true) {
            std::string item;
            iss >> item;
            if (iss.fail()) {
                break;
            }
            size_t c1 = item.find_first_of(',');
            size_t c2 = item.find_last_of(',');
            // std::cout <<item.substr(c1+1,c2-c1-1)<< '\n';
            float weight = atof(item.substr(c1+1,c2-c1-1).c_str());
            float price = atof(item.substr(c2+2).c_str());
            items.push_back(std::make_pair(weight, price));
            // std::cout << "w=" << items.back().first << " p=" << items.back().second << '\n';
        }
        std::set<int> best;
        float best_price = 0;
        find_best_set(best, items, weight, best_price);
        size_t num_shipped = std::distance(best.begin(), best.end());
        if (num_shipped == 0) {
            std::cout << "-";
        } else if (num_shipped == 1) {
            std::cout << (1+*(best.begin()));
        } else {
            std::set<int>::iterator it = best.begin();
            std::cout << (1+*it);
            it++;
            for(; it != best.end(); it++) {
                std::cout << ',' << (1+*it);
            }
        }
        std::cout << '\n';
    }
    return 0;
}
