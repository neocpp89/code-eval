#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <complex>
#include <numeric>

template <typename T>
void dft(
    std::vector<std::complex<T> > &result, size_t write_offset,
    const std::vector<std::complex<T> > &x, size_t read_offset,
    size_t N, size_t s,
    const std::vector<std::complex<T> > &twiddles)
{
    if (N == 1) {
        result[write_offset] = x[read_offset];
    } else {
        dft(result, write_offset, x, read_offset, N/2, 2*s, twiddles);
        dft(result, write_offset + N/2, x, read_offset+s, N/2, 2*s, twiddles);
        for (size_t k = 0; k < N/2 - 1; k++) {
            //std::complex<T> rou = std::exp(std::complex<T>(0, 2*M_PI*k/N)) * result[write_offset+k+N/2];
            std::complex<T> rou = twiddles[k * s] * result[write_offset+k+N/2];
            std::complex<T> t = result[write_offset+k];
            result[write_offset+k] = t + rou;
            result[write_offset+k+ N/2] = t - rou;
        }
    }
    return;
}

void linear_regression(const std::vector<int> &v, double &alpha, double &beta)
{
    const double x_avg = (v.size() + 1) / 2;
    double beta_n = 0;
    double beta_d = 0;
    double y_avg = v[0];
    for (int i = 1; i < v.size(); i++) {
        y_avg += (v[i] - y_avg) / i;
    }
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

        double slope;
        double dc;
        linear_regression(v, dc, slope);
        if (!std::isfinite(slope)) {
            std::cout << "error in slope!\n";
            return 1;
        }
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] - slope*i;
        }
        double dcr = v[0];
        double idcr = 1;
        while (idcr < v.size()) {
            dcr += (v[idcr] - dcr) / idcr;
            idcr++;
        }

        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] - dcr;
        }
        for (int s = 0; v.size() < 2048; s++) {
            v.push_back(v[s+1]);
        }


        typedef double complex_type;

        std::vector<std::complex<complex_type> > result(4096);
        std::vector<std::complex<complex_type> > signal(4096);
        std::vector<std::complex<complex_type> > twiddles(4096);
        for (size_t i = 0; i < twiddles.size(); i++) {
            twiddles[i] = std::exp(std::complex<complex_type>(0, 2*M_PI*i/twiddles.size()));
        }
        for (size_t i = 0; i < v.size(); i++) {
            signal[i] = std::complex<complex_type>(v[i], 0);
            signal[i + 2048] = std::complex<complex_type>(v[i], 0);
        }
        dft(result, 0, signal, 0, 4096, 1, twiddles);
        complex_type maxn = 0;
        size_t mf = 0;
        for (size_t i = 30; i < 440; i++) {
            complex_type s = std::norm(result[i]);
            if (s > maxn) {
                maxn = s;
                mf = i;
            }
        }
        if (mf == 0) {
            std::cout << line << '\n';
        }
        size_t freq = mf*20000/4096;
        if (freq % 10 >= 5) {
            freq = (1 + (freq/10)) * 10;
        } else {
            freq = (freq / 10) * 10;
        }
        std::cout << freq << '\n';
    }

    return 0;
}

