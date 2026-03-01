#pragma once

namespace pvm_math_lib
{
namespace calculator_exceptions
{

#include <stdexcept>
#include <string>

class CalculatorExceptionBase : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

class CalculatorExceptionOverflow : public CalculatorExceptionBase
{
public:
    CalculatorExceptionOverflow()
        : CalculatorExceptionBase("Calculator Error: Mathematical overflow occured.")
    {

    }

    explicit CalculatorExceptionOverflow(const std::string& msg)
        : CalculatorExceptionBase(msg)
    {

    }
};

class CalculatorExceptionDivideByZero : public CalculatorExceptionBase
{
public:
    CalculatorExceptionDivideByZero()
        : CalculatorExceptionBase("Calculator Error: Division by zero is undefined.")
    {

    }

    explicit CalculatorExceptionDivideByZero(const std::string& msg)
        : CalculatorExceptionBase(msg)
    {

    }
};

} // namespace calculator_exceptions
} // namespace pvm_math_lib
