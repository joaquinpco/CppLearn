#pragma once

#include "cpplearn/core/shape.hpp"
#include <vector>

namespace cpplearn::core
{
    class Tensor
    {
    public:
        Tensor();

        /// @brief Constructs a Tensor with the specified dimensions.
        /// @param dims A vector of dimensions for each axis.
        explicit Tensor(const std::vector<size_t> &dims);

        const Shape &shape() const;

        /// @brief Accesses the element at the specified indices.
        /// @param index A vector of indices for each dimension.
        /// @return Reference to the element.
        float &at(const std::vector<size_t> &index);
        const float &at(const std::vector<size_t> &index) const;

    private:
        Shape shape_;
        std::vector<float> data_;
    };
}