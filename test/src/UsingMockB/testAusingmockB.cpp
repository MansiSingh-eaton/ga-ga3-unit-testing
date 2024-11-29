#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/SourceA.hpp"
#include "../test/mocks/UsingMockB/SourceBMock.hpp"

TEST(SourceATest, SumTest) {
    MockSourceB mockB;
    SourceB::SetInstance(&mockB);

    EXPECT_CALL(mockB, doubleValueB(2)).WillOnce(testing::Return(4));
    EXPECT_CALL(mockB, doubleValueB(3)).WillOnce(testing::Return(6));

    SourceA a;
    EXPECT_EQ(a.sum(2, 3), 10);
}

TEST(SourceATest, MultiplyTest) {
    SourceA a;

    EXPECT_EQ(a.multiply(2, 3), 6);
    EXPECT_EQ(a.multiply(-2, 3), -6);
    EXPECT_EQ(a.multiply(0, 3), 0);
    EXPECT_EQ(a.multiply(INT_MAX, 1), INT_MAX);
    EXPECT_EQ(a.multiply(INT_MIN, 1), INT_MIN);
}

TEST(SourceATest, DivideTest) {
    SourceA a;

    EXPECT_EQ(a.divide(6, 3), 2.0);
    EXPECT_EQ(a.divide(-6, 3), -2.0);
    EXPECT_THROW(a.divide(1, 0), std::invalid_argument);
    EXPECT_EQ(a.divide(INT_MAX, 1), static_cast<double>(INT_MAX));
    EXPECT_EQ(a.divide(INT_MIN, 1), static_cast<double>(INT_MIN));
}

TEST(SourceATest, UseHelperFunctionTest) {
	MockSourceB mockB;
    SourceB::SetInstance(&mockB);

    EXPECT_CALL(mockB, doubleValueB(3)).WillOnce(testing::Return(6));
    EXPECT_CALL(mockB, doubleValueB(-3)).WillOnce(testing::Return(-6));
    EXPECT_CALL(mockB, doubleValueB(0)).WillOnce(testing::Return(0));

    SourceA a;
    EXPECT_EQ(a.UsedFunctionB(3), 6);
    EXPECT_EQ(a.UsedFunctionB(-3), -6);
    EXPECT_EQ(a.UsedFunctionB(0), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}