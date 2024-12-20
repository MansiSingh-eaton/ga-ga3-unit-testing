#include <gtest/gtest.h>
#define private public
#include "SourceB.hpp"
#undef private

TEST(SourceB_Test, DoubleValueTest) {
    SourceB b;
    ASSERT_EQ(b.doubleValueB(3), 6);
    ASSERT_EQ(b.doubleValueB(-3), -6);
    ASSERT_EQ(b.doubleValueB(0), 0);
}

TEST(SourceB_Test, TripleValueTest) {
    SourceB b;
    ASSERT_EQ(b.tripleValue(3), 9);
    ASSERT_EQ(b.tripleValue(-3), -9);
    ASSERT_EQ(b.tripleValue(0), 0);
}

TEST(SourceB_Test, IsPositiveTest) {
    SourceB b;
    ASSERT_TRUE(b.isPositive(3));
    ASSERT_FALSE(b.isPositive(-1));
    ASSERT_FALSE(b.isPositive(0));
}

TEST(SourceB_Test, FactorialTest) {
    SourceB b;
    ASSERT_EQ(b.factorial(5), 120);
    ASSERT_EQ(b.factorial(0), 1);
    ASSERT_THROW(b.factorial(-1), std::invalid_argument);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
