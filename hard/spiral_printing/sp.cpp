#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

// Fully generic version
template <typename T, size_t dim>
class Slice
{
    private:
        T *data;
        const size_t *dims;

    public:
        Slice(T *data_, const size_t *dims_) : data(data_), dims(dims_) { return; }
        Slice(std::vector<T> &v_, const size_t *dims_) : data(&(v_[0])), dims(dims_) { return; }
        inline Slice<T, dim-1> operator[](const size_t idx)
        {
            const size_t *sdims = &dims[1];

            size_t offset = idx;
            for (size_t i = 1; i < dim; i++) {
                offset *= dims[i];
            }

            return Slice<T, dim-1>(data + offset, sdims);
        }

};

// Specialization for "lowest level", similar to a vector.
template<typename T>
class Slice<T, 1>
{
    private:
        T *data;
        const size_t numel;

    public:
        Slice(T *data_, const size_t *numel_) : data(data_), numel(numel_[0]) { return; }
        Slice(std::vector<T> &v_) : data(&(v_[0])), numel(v_.size()) { return; } 
        Slice(T *data_, const size_t numel_) : data(data_), numel(numel_) { return; }
        inline T &operator[](const size_t idx) { return data[idx]; }
        inline const T &operator[](const size_t idx) const { return data[idx]; } 

};

void spiral_print(Slice<std::string, 2> &array, size_t n, size_t m)
{
    int step = 0;
    size_t hstart = 0;
    size_t hstop = m;
    size_t vstart = 0;
    size_t vstop = n;

    while (hstart < hstop && vstart < vstop) {
        switch (step % 4) {
            case 0:
                for (size_t j = hstart; j < hstop; j++) {
                    std::cout << array[vstart][j] << ' ';
                }
                vstart++;
                break;
            case 1:
                for (size_t i = vstart; i < vstop; i++) {
                    std::cout << array[i][hstop-1] << ' ';
                }
                hstop--;
                break;
            case 2:
                for (size_t j = hstop; j > hstart; j--) {
                    std::cout << array[vstop-1][j-1] << ' ';
                }
                vstop--;
                break;
            case 3:
                for (size_t i = vstop; i > vstart; i--) {
                    std::cout << array[i-1][hstart] << ' ';
                }
                hstart++;
                break;
        }
        step++;
    }

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
        int n = std::atoi(line.substr(0,s1).c_str());
        int m = std::atoi(line.substr(s1+1,s2).c_str());
        std::string as = line.substr(s2+1);

        std::istringstream iss(as);
        std::vector<std::string> array;
        for (size_t i = 0; i < n*m; i++) {
            std::string x;
            iss >> x;
            array.push_back(x);
        }
        const size_t dims[] = {n, m};
        Slice<std::string, 2> array2d(array, dims);
        /*
        std::cout << n << ' ' << m << '\n';
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                std::cout << array2d[i][j] << ' ';
            }
            std::cout << '\n';
        }
        */
        spiral_print(array2d, n, m);
        std::cout << '\n';
    }

    return 0;
}

