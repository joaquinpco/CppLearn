#include "cpplearn/matrix.hpp"
#include <gtest/gtest.h>

using namespace cpplearn;

TEST(MatrixTest, AdditionWorks)
{
    Matrix A(2, 2, 1.0);
    Matrix B(2, 2, 2.0);
    Matrix C = A + B;

    EXPECT_DOUBLE_EQ(C(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(C(1, 1), 3.0);
}