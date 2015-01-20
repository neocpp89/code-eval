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

inline bool valid_index(size_t i, size_t j, size_t n, size_t m)
{
    return (i < n && j < m);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return 0;
    }
    std::ifstream f(argv[1]); // first argument is the test file

    while (true) {
        std::string ns;
        std::getline(f, ns);
        if (f.fail()) {
            break;
        }

        const int n = atoi(ns.c_str());
        const size_t dims[] = {n, n};
        std::vector<int> adata(n*n);
        Slice<int, 2> array2d(adata, dims);

        for (size_t i = 0; i < n; i++) {
            std::string row;
            std::getline(f, row);
            size_t n1 = 0;
            size_t n2 = row.find_first_of(',');
            for (size_t j = 0; j < n; j++) {
                array2d[i][j] = atoi(row.substr(n1, n2-n1).c_str());
                n1 = n2+1;
                n2 = row.substr(n1).find_first_of(',') + n1;
            }
        }

        for (int i = 1; i < n; i++) {
            array2d[i][0] += array2d[i-1][0];
            array2d[0][i] += array2d[0][i-1];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                array2d[i][j] += std::min(array2d[i-1][j], array2d[i][j-1]);
            }
        }

        std::cout << array2d[n-1][n-1] << '\n';
    }

    return 0;
}

