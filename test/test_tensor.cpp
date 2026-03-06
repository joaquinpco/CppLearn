#include "cpplearn/core/tensor.hpp"
#include <gtest/gtest.h>

using namespace cpplearn::core;

TEST(TensorTest, CreationWorks)
{
    Tensor t({2, 3, 4});
    EXPECT_EQ(t.shape().dims(), std::vector<size_t>({2, 3, 4}));
    EXPECT_EQ(t.shape().nsize(), 24);
}

TEST(TensorTest, ElementAccessWorks)
{
    Tensor t({2, 3, 4});
    t.at({0, 0, 0}) = 1.0f;
    t.at({1, 2, 3}) = 2.0f;

    EXPECT_FLOAT_EQ(t.at({0, 0, 0}), 1.0f);
    EXPECT_FLOAT_EQ(t.at({1, 2, 3}), 2.0f);
}

TEST(TensorTest, OutOfRangeAccessThrows)
{
    Tensor t({2, 3, 4});
    EXPECT_THROW(t.at({2, 0, 0}), std::out_of_range);
    EXPECT_THROW(t.at({0, 3, 0}), std::out_of_range);
    EXPECT_THROW(t.at({0, 0, 4}), std::out_of_range);
}