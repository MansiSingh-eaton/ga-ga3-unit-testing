#include <gtest/gtest.h>
#include "../src/SourceA.hpp"
#include "../src/SourceB.hpp"

TEST(SourceATest, SumTest) {
    SourceA a;
	std::cout << "SUM\n";
    ASSERT_EQ(a.sum(2, 3), 10);
    ASSERT_EQ(a.sum(-2, 3), 2);
    ASSERT_EQ(a.sum(0, 0), 0);
    ASSERT_EQ(a.sum(2, -3), -2);
    ASSERT_EQ(a.sum(INT_MAX, 0), 2 * INT_MAX);
    ASSERT_EQ(a.sum(INT_MIN, 0), 2 * INT_MIN);
}

TEST(SourceATest, MultiplyTest) {
    SourceA a;
	std::cout << "Multiply\n";
    ASSERT_EQ(a.multiply(2, 3), 6);
    ASSERT_EQ(a.multiply(-2, 3), -6);
    ASSERT_EQ(a.multiply(0, 3), 0);
    ASSERT_EQ(a.multiply(INT_MAX, 1), INT_MAX);
    ASSERT_EQ(a.multiply(INT_MIN, 1), INT_MIN);
}

TEST(SourceATest, DivideTest) {
    SourceA a;
	std::cout << "Divide\n";
    ASSERT_EQ(a.divide(6, 3), 2.0);
    ASSERT_EQ(a.divide(-6, 3), -2.0);
    ASSERT_THROW(a.divide(1, 0), std::invalid_argument);
    ASSERT_EQ(a.divide(INT_MAX, 1), static_cast<double>(INT_MAX));
    ASSERT_EQ(a.divide(INT_MIN, 1), static_cast<double>(INT_MIN));
}

TEST(SourceATest, UseHelperFunctionTest) {
    SourceA a;
	std::cout << "SourceBfunction\n";
    ASSERT_EQ(a.UsedFunctionB(3), 6);
    ASSERT_EQ(a.UsedFunctionB(-3), -6);
    ASSERT_EQ(a.UsedFunctionB(0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
