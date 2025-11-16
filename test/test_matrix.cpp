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

TEST(MatrixTest, MultiplicationWorks)
{
    Matrix A(2, 3, {1, 2, 3, 4, 5, 6});

    Matrix B(3, 2, {7, 8, 9, 10, 11, 12});

    Matrix C = A * B;

    ASSERT_EQ(C.getRows(), 2);
    ASSERT_EQ(C.getColumns(), 2);

    EXPECT_DOUBLE_EQ(C(0, 0), 1 * 7 + 2 * 9 + 3 * 11);
    EXPECT_DOUBLE_EQ(C(0, 1), 1 * 8 + 2 * 10 + 3 * 12);
    EXPECT_DOUBLE_EQ(C(1, 0), 4 * 7 + 5 * 9 + 6 * 11);
    EXPECT_DOUBLE_EQ(C(1, 1), 4 * 8 + 5 * 10 + 6 * 12);
}

TEST(MatrixTest, TransposeWorks)
{
    Matrix A(2, 2, {1, 2, 3, 4});

    Matrix AT = A.T();

    EXPECT_EQ(AT.getRows(), 2);
    EXPECT_EQ(AT.getColumns(), 2);

    EXPECT_DOUBLE_EQ(AT(0, 0), 1);
    EXPECT_DOUBLE_EQ(AT(1, 0), 2);
    EXPECT_DOUBLE_EQ(AT(0, 1), 3);
    EXPECT_DOUBLE_EQ(AT(1, 1), 4);
}