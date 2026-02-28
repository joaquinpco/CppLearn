#include "cpplearn/core/shape.hpp"
#include <vector>
#include <numeric>
#include <stdexcept>

namespace cpplearn::core
{
    Shape::Shape() = default;
    Shape::Shape(const std::vector<size_t> &dims) : dims_(dims)
    {
        compute_strides();
    }

    size_t Shape::ndim() const
    {
        return dims_.size();
    }

    size_t Shape::nsize() const
    {
        return std::accumulate(dims_.begin(), dims_.end(), size_t(1), std::multiplies<>());
    }

    const std::vector<size_t> &Shape::dims() const
    {
        return dims_;
    }

    const std::vector<size_t> &Shape::strides() const
    {
        return strides_;
    }

    void Shape::compute_strides()
    {
        strides_.resize(dims_.size());
        if (dims_.empty())
            return;

        strides_[dims_.size() - 1] = 1;
        for (int i = dims_.size() - 2; i >= 0; --i)
        {
            strides_[i] = strides_[i + 1] * dims_[i + 1];
        }
    }
}