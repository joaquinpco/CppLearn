#include "cpplearn/core/shape.hpp"
#include <gtest/gtest.h>

using namespace cpplearn::core;

TEST(ShapeTest, ConstructorWorks)
{
    Shape s({2, 3, 4});
    EXPECT_EQ(s.ndim(), 3);
    EXPECT_EQ(s.nsize(), 24);
    EXPECT_EQ(s.dims(), std::vector<size_t>({2, 3, 4}));
    EXPECT_EQ(s.strides(), std::vector<size_t>({12, 4, 1}));
}