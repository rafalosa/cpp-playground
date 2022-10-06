#include <iostream>
#include "somelib.hpp"

#include <gtest/gtest.h>

TEST(MultiplyTests, NonZeroFloatsTest){

    const auto expected = 36.55;

    const auto result = math::multiply(4.3, 8.5);

    ASSERT_EQ(expected, result);
}

TEST(MultiplyTests, ZeroFloatsTest){

    const auto expected = 0.0;

    const auto result = math::multiply(0.0, 0.0);

    ASSERT_EQ(expected, result);
}

TEST(MultiplyTests, NonZeroAndZeroFloatsTest){

    const auto expected = 0.0;

    const auto result = math::multiply(4.3, 0.0);

    ASSERT_EQ(expected, result);
}

int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}   