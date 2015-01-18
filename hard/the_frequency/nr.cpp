#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <complex>
#include <numeric>

template <typename T>
void four1(T &data, unsigned long nn)
{
    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;
 
    // reverse-binary reindexing
    n = nn<<1;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            std::swap(data[j-1], data[i-1]);
            std::swap(data[j], data[i]);
        }
        m = nn;
        while (m>=2 && j>m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    };
 
    // here begins the Danielson-Lanczos section
    mmax=2;
    while (n>mmax) {
        istep = mmax<<1;
        theta = -(2*M_PI/mmax);
        wtemp = std::sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = std::sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m=1; m < mmax; m += 2) {
            for (i=m; i <= n; i += istep) {
                j=i+mmax;
                tempr = wr*data[j-1] - wi*data[j];
                tempi = wr * data[j] + wi*data[j-1];
 
                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] += tempr;
                data[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }
}

void dft(std::vector<std::complex<double> > &result, size_t write_offset, const std::vector<std::complex<double> > &x, size_t read_offset, size_t N, size_t s)
{
    if (N == 1) {
        result[write_offset] = x[read_offset];
    } else {
        dft(result, write_offset, x, read_offset, N/2, 2*s);
        dft(result, write_offset + N/2, x, read_offset+s, N/2, 2*s);
        for (size_t k = 0; k < N/2 - 1; k++) {
            std::complex<double> rou = std::exp(std::complex<double>(0, 2*M_PI*k/N)) * result[write_offset+k+N/2];
            std::complex<double> t = result[write_offset+k];
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

double autocorrelate(const std::vector<int> &v, int offset)
{
    size_t stop = v.size() - offset;
    double sum = 0;
    /*
    for (int i = 0; i < stop; i++) {
        sum += v[i]*v[i+offset];
    }
    for (int i = 0; i < offset; i++) {
        sum += v[stop+i]*v[i];
    }
    */
    for (int i = 0; i < v.size(); i++) {
        int idx = (i + offset) % v.size();
        sum += v[i] * v[idx];
    }
    return sum;
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
        //std::cout << line << '\n';
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
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] - slope*i;
        }
        double dcr = v[0];
        double idcr = 1;
        while (idcr < v.size()) {
            dcr += (v[idcr] - dcr) / idcr;
            idcr++;
        }
        // std::cerr << dcr << '\n';
        for (int i = 0; i < v.size(); i++) {
            v[i] = v[i] - dcr;
        }
        for (int s = 0; v.size() < 2048; s++) {
            v.push_back(v[s+1]);
        }

        std::vector<double> dsig(4096);
        for (size_t i = 0; i < 2000; i++) {
            dsig[2*i] = v[i];
        }

        four1(dsig, 2000);
        double maxn = 0;
        size_t mf = 0;
        for (size_t i = 15; i < 201; i++) {
            double s = dsig[2*i] * dsig[2*i] + dsig[2*i+1] * dsig[2*i+1];
            if (s > maxn) {
                maxn = s;
                mf = i;
            }
        }
        std::cout << 10*mf << '\n';

        /*
        if (v.size() > 0) {
            std::cout << v[0];
        }
        for (size_t i = 1; i < v.size(); i++) {
            std::cout << ',' << v[i];
        }
        */
    }

    return 0;
}

