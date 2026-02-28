#ifndef CPPLEARN_HPP_INCLUDED
#define CPPLEARN_HPP_INCLUDED

#include <vector>
#include <numeric>
#include <stdexcept>

namespace cpplearn::core
{
    class Shape
    {
    public:
        Shape();
        explicit Shape(const std::vector<size_t> &dims);
        size_t ndim() const;
        size_t nsize() const;

        const std::vector<size_t> &dims() const;
        const std::vector<size_t> &strides() const;

        size_t offset(const std::vector<size_t> &indices) const;

    private:
        std::vector<size_t> dims_;
        std::vector<size_t> strides_;

        /*
         * Number of bytes for next element and number of elements for jump to next row
         * 4 Bytes => int 32, thats means 4*1 for moving in the same row and 4*C for moving in
         * the next row, being C, columns numbers for each row
         */
        void compute_strides();
    };
}

#endif