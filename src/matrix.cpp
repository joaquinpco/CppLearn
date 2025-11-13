#include "cpplearn/matrix.hpp"

namespace cpplearn
{
    Matrix::Matrix(size_t rows, size_t columns, double value) : rows_(rows), columns_(columns), data_(rows * columns, value) {}

    Matrix Matrix::operator+(const Matrix &B) const
    {
        if (rows_ != B.rows_ || columns_ != B.columns_)
            throw std::invalid_argument("Matrix dimensions must match for addition");

        Matrix result(rows_, columns_);
        for (size_t i = 0; i < data_.size(); ++i)
            result.data_[i] = data_[i] + B.data_[i];
        return result;
    }

    double &Matrix::operator()(size_t r, size_t c)
    {
        if (r >= rows_ || c >= columns_)
            throw std::out_of_range("Matrix index out of range");
        return data_[r * columns_ + c];
    }

    double Matrix::operator()(size_t r, size_t c) const
    {
        if (r >= rows_ || c >= columns_)
            throw std::out_of_range("Matrix index out of range");
        return data_[r * columns_ + c];
    }

    Matrix Matrix::operator*(const Matrix &B) const
    {
        if (columns_ != B.rows_)
            throw std::invalid_argument("Invalid matrix dimensions for multiplication");

        Matrix result(rows_, B.columns_);
        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < B.columns_; ++j)
                for (size_t k = 0; k < columns_; ++k)
                    result(i, j) += (*this)(i, k) * B(k, j);

        return result;
    }

    void Matrix::show() const
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            for (size_t j = 0; j < columns_; ++j)
                std::cout << (*this)(i, j) << " ";
            std::cout << "\n";
        }
    }
}