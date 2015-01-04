#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

void linear_regression(const std::vector<int> &v, double &alpha, double &beta)
{
    const double x_avg = (v.size() + 1) / 2;
    double beta_n = 0;
    double beta_d = 0;
    double y_avg;
    for (int i = 0; i < v.size(); i++) {
        y_avg += v[i];
    }
    y_avg /= v.size();
    for (int i = 0; i < v.size(); i++) {
        const int x = i;
        const int y = v[i];
        beta_n += (x - x_avg) * (y - y_avg);
        beta_d += (x - x_avg) * (x - x_avg);
    }
    beta = beta_n / beta_d;
    alpha = y_avg;
    return;
}

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
        std::istringstream ss(line);
        std::vector<int> v;
        while (true) {
            int vv;
            ss >> vv;
            if (ss.fail()) {
                break;
            }
            v.push_back(vv);
        }

        if (iter != 0) {
            std::cout << '\n';
        }
        /*
        if (v.size() > 0) {
            std::cout << v[0];
        }
        for (size_t i = 1; i < v.size(); i++) {
            std::cout << '\n' << v[i];
        }
        */

        // std::cout << lin_slope(v) << '\n';

        double slope;
        double dc;
        linear_regression(v, dc, slope);
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] - slope*i - dc;
        }
        if (v.size() > 0) {
            std::cout << v[0];
        }
        for (size_t i = 1; i < v.size(); i++) {
            std::cout << ',' << v[i];
        }
        iter++;
    }

    return 0;
}

