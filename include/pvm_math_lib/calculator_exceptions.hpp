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

class CalculatorExceptionInvalidOperands : public CalculatorExceptionBase
{
public:
    CalculatorExceptionInvalidOperands()
        : CalculatorExceptionBase("Calculator Error: Invalid operands for this operation.")
    {

    }

    explicit CalculatorExceptionInvalidOperands(const std::string& msg)
        : CalculatorExceptionBase(msg)
    {

    }
};

} // namespace pvm_math_lib::calculator_exceptions
