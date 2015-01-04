#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>


template <typename Real>
struct ps {
    Real x;
    Real y;
};

template <typename Real>
Real pdist(const struct ps<Real> &a, const struct ps<Real> &b)
{
    const Real dx = a.x - b.x;
    const Real dy = a.y - b.y;
    return hypot(dx, dy);
}

typedef struct ps<double> pt;

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    int num_points = 0;
    f >> num_points;
    while (num_points > 0) {
        std::vector<pt> points(num_points);
        for(int i = 0; i < num_points; i++) {
            f >> points[i].x;
            f >> points[i].y;
            if (f.fail()) {
                break;
            }
        }

        double min_ds = 10001;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                const double ds = pdist(points[i], points[j]);
                if (ds < min_ds) {
                    min_ds = ds;
                }
            }
        }

        if (min_ds >= 10000) {
            std::cout << "INFINITY";
        } else {
            std::cout << std::fixed << std::setprecision(4) << min_ds;
        }
        f >> num_points;
        if (num_points > 0) {
            std::cout << '\n';
        }
    }

    return 0;
}

