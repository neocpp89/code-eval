#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

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
        Slice(T *data_, const size_t *numel_) : data(data_), numel(numel_[0]) {  
return; }
        Slice(std::vector<T> &v_) : data(&(v_[0])), numel(v_.size()) { return; }
        Slice(T *data_, const size_t numel_) : data(data_), numel(numel_) { return; }
        inline T &operator[](const size_t idx) { return data[idx]; }
        inline const T &operator[](const size_t idx) const { return data[idx]; }

};

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
        std::istringstream iss(line);
        std::vector<char> cs;
        while (true) { 
            char x;
            iss >> x;
            if (iss.fail()) {
                break;
            }
            cs.push_back(x);
        }
        const size_t n = sqrt(cs.size());
        const size_t dims[] = {n, n};
        Slice<char, 2> as(&(cs[0]), dims);
        /*
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                std::cout << as[i][j] << ' ';
            }
            std::cout << '\n';
        }
        */
        for (size_t j = 0; j < n; j++) {
            for (size_t i = 0; i < n; i++) {
                std::cout << as[n-i-1][j] << ' ';
            }
            // std::cout << '\n';
        }
        std::cout << '\n';
    }

    return 0;
}

