#pragma once

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

        size_t offset(const std::vector<size_t> &index) const;

    private:
        std::vector<size_t> dims_;
        std::vector<size_t> strides_;

        /*
         * Computes the strides for efficient element access in multi-dimensional arrays.
         * Strides represent the number of bytes to skip in memory when moving to the next
         * element along each dimension. For a 2D array (rows x columns):
         * - stride[0] = columns * element_size (bytes per row)
         * - stride[1] = element_size (bytes per element)
         * This enables efficient conversion from multi-dimensional indices to linear memory offsets.
         */
        void compute_strides();
    };
}