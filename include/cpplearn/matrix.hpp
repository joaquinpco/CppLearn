#ifndef CPPLEARN_HPP_INCLUDED
#define CPPLEARN_HPP_INCLUDED

#include <vector>
#include <iostream>
#include <stdexcept>

namespace cpplearn
{

    class Matrix
    {
    private:
        std::vector<double> data_;
        size_t rows_;
        size_t columns_;

    public:
        Matrix(size_t rows, size_t columns, double value = 0.0);
        Matrix(size_t rows, size_t columns, const std::vector<double> &data);

        Matrix operator+(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;

        double &operator()(size_t r, size_t c);
        double operator()(size_t r, size_t c) const;

        size_t getColumns() const;
        size_t getRows() const;

        Matrix T() const;

        void show() const;
    };
}

#endif