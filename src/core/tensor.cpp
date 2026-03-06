#include "cpplearn/core/tensor.hpp"

namespace cpplearn::core
{
    Tensor::Tensor() = default;
    Tensor::Tensor(const std::vector<size_t> &dims) : shape_(Shape(dims)), data_(shape_.nsize()) {}

    const Shape &Tensor::shape() const
    {
        return shape_;
    }

    float &Tensor::at(const std::vector<size_t> &index)
    {
        size_t offset = shape_.offset(index);
        if (offset >= data_.size())
            throw std::out_of_range("Tensor index out of range");
        return data_[offset];
    }

    const float &Tensor::at(const std::vector<size_t> &index) const
    {
        size_t offset = shape_.offset(index);
        if (offset >= data_.size())
            throw std::out_of_range("Tensor index out of range");
        return data_[offset];
    }
}