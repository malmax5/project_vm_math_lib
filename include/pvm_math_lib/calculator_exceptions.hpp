#pragma once

#include <stdexcept>
#include <string>

namespace pvm_math_lib::calculator_exceptions
{

class CalculatorExceptionBase : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CalculatorExceptionOverflow : public CalculatorExceptionBase
{
public:
    CalculatorExceptionOverflow()
        : CalculatorExceptionBase("Math Error: Mathematical overflow occured.")
    {

    }

    explicit CalculatorExceptionOverflow(const std::string& msg)
        : CalculatorExceptionBase("Math Error: " + msg)
    {

    }
};

class CalculatorExceptionDivideByZero : public CalculatorExceptionBase
{
public:
    CalculatorExceptionDivideByZero()
        : CalculatorExceptionBase("Math Error: Division by zero is undefined.")
    {

    }

    explicit CalculatorExceptionDivideByZero(const std::string& msg)
        : CalculatorExceptionBase("Math Error: " + msg)
    {

    }
};

class CalculatorExceptionInvalidOperands : public CalculatorExceptionBase
{
public:
    CalculatorExceptionInvalidOperands()
        : CalculatorExceptionBase("Math Error: Invalid operands for this operation.")
    {

    }

    explicit CalculatorExceptionInvalidOperands(const std::string& msg)
        : CalculatorExceptionBase("Math Error: " + msg)
    {

    }
};

} // namespace pvm_math_lib::calculator_exceptions
