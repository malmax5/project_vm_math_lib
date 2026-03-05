#include "pvm_math_lib/calculator_math.hpp"
#include <gtest/gtest.h>
#include <limits>

using namespace pvm_math_lib;

class MathExceptionsTest : public ::testing::Test
{
  protected:
    Calculator calc;

    static constexpr long long maxLL = std::numeric_limits<long long>::max();
    static constexpr long long minLL = std::numeric_limits<long long>::min();
};

class MathBoundaryTest : public ::testing::Test
{
  protected:
    Calculator calc;
};

// --- MathExceptionsTest ---

TEST_F(MathExceptionsTest, AdditionOverflow)
{
    EXPECT_THROW(calc.add(maxLL, 1), calculator_exceptions::CalculatorExceptionOverflow);
    EXPECT_THROW(calc.add(minLL, -1), calculator_exceptions::CalculatorExceptionOverflow);
}

TEST_F(MathExceptionsTest, SubtractionOverflow)
{
    EXPECT_THROW(calc.sub(minLL, 1), calculator_exceptions::CalculatorExceptionOverflow);
    EXPECT_THROW(calc.sub(maxLL, -1), calculator_exceptions::CalculatorExceptionOverflow);
}

TEST_F(MathExceptionsTest, MultiplicationOverflow)
{
    EXPECT_THROW(calc.mul(maxLL, 2), calculator_exceptions::CalculatorExceptionOverflow);
    EXPECT_THROW(calc.mul(minLL, 2), calculator_exceptions::CalculatorExceptionOverflow);
}

TEST_F(MathExceptionsTest, PowerOverflow)
{
    EXPECT_THROW(calc.pow(2, 63), calculator_exceptions::CalculatorExceptionOverflow);
    EXPECT_THROW(calc.pow(maxLL / 2, 3), calculator_exceptions::CalculatorExceptionOverflow);
}

TEST_F(MathExceptionsTest, FactorialOverflow)
{
    EXPECT_THROW(calc.factorial(21), calculator_exceptions::CalculatorExceptionOverflow);
}

TEST_F(MathExceptionsTest, DivisionByZero)
{
    EXPECT_THROW(calc.div(100, 0), calculator_exceptions::CalculatorExceptionDivideByZero);
}

TEST_F(MathExceptionsTest, InvalidPowerExponent)
{
    EXPECT_THROW(calc.pow(10, -1), calculator_exceptions::CalculatorExceptionInvalidOperands);
}

TEST_F(MathExceptionsTest, InvalidFactorialArgument)
{
    EXPECT_THROW(calc.factorial(-5), calculator_exceptions::CalculatorExceptionInvalidOperands);
}

// --- MathBoundaryTest ---

TEST_F(MathBoundaryTest, PowerEdgeCases)
{
    EXPECT_EQ(calc.pow(10, 0), 1);
    EXPECT_EQ(calc.pow(0, 0), 1);
    EXPECT_EQ(calc.pow(0, 5), 0);
    EXPECT_EQ(calc.pow(1, 1000), 1);
}

TEST_F(MathBoundaryTest, FactorialEdgeCases)
{
    EXPECT_EQ(calc.factorial(0), 1);
    EXPECT_EQ(calc.factorial(1), 1);
    EXPECT_EQ(calc.factorial(20), 2432902008176640000LL);
}

TEST_F(MathBoundaryTest, DivisionBoundary)
{
    EXPECT_EQ(calc.div(10, 10), 1);
    EXPECT_EQ(calc.div(0, 5), 0);
}
