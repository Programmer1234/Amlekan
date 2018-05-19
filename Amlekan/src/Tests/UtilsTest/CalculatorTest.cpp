#include "../BaseTest/BaseTest.h"

#include "Calculator.h"

class CalculatorTest : public BaseTest { };


TEST_F(CalculatorTest, FactorialSanity) {
	EXPECT_EQ(Utils::Calculator::factorial(1), 1);
	EXPECT_EQ(Utils::Calculator::factorial(2), 2);
	EXPECT_EQ(Utils::Calculator::factorial(3), 6);
	EXPECT_EQ(Utils::Calculator::factorial(4), 24);
	EXPECT_EQ(Utils::Calculator::factorial(6), 720);
}

TEST_F(CalculatorTest, FactorialWrong) {
	EXPECT_NE(Utils::Calculator::factorial(7), 3);
}

TEST_F(CalculatorTest, NegativeNumber) {
	EXPECT_THROW(Utils::Calculator::factorial(-2),std::runtime_error);
}


TEST_F(CalculatorTest, Zero) {
	EXPECT_THROW(Utils::Calculator::factorial(0), std::runtime_error);
}

/*
	Make Test fail
TEST_F(CalculatorTest, FactorialFail) {
	EXPECT_EQ(Utils::Calculator::factorial(6), 72);
}
*/