#pragma once

#include "calculator_exceptions.hpp"

namespace pvm_math_lib
{

class ICalculator
{
public:
    virtual ~ICalculator() = default;

    virtual long long add(long long first, long long second) const = 0;
    virtual long long sub(long long first, long long second) const = 0;
    virtual long long mul(long long first, long long second) const = 0;
    virtual long long div(long long first, long long second) const = 0;

    virtual long long pow(long long num, long long exp) const = 0;
    virtual long long factorial(long long n) const = 0;
};

class Calculator : public ICalculator
{
public:
    virtual ~Calculator() = default;

    long long add(long long first, long long second) const override
    {
        long long result;

        if (__builtin_add_overflow(first, second, &result)) 
        {
            throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in add");
        }

        return result;
    }

    long long sub(long long first, long long second) const override
    {
        long long result;

        if (__builtin_sub_overflow(first, second, &result))
        {
            throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in sub");
        }

        return result;
    }

    long long mul(long long first, long long second) const override
    {
        long long result;

        if (__builtin_mul_overflow(first, second, &result))
        {
            throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in mul");
        }

        return result;
    }

    long long div(long long first, long long second) const override
    {
        if (second == 0)
        {
            throw calculator_exceptions::CalculatorExceptionDivideByZero("Divide by zero");
        }

        long long result = first / second;

        return result;
    }

    long long pow(long long num, long long exp) const override
    {
        if (exp < 0)
        {
            throw calculator_exceptions::CalculatorExceptionInvalidOperands("Power of number by negative exponent");
        }

        long long result;

        if (exp == 0)
        {
            result = 1;
            return result;
        }

        long long resultTmp = 1;

        while (exp)
        {
            if (exp & 1 && __builtin_mul_overflow(resultTmp, num, &resultTmp))
            {
                throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in power");
            }

            if (__builtin_mul_overflow(num, num, &num))
            {
                throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in power");
            }

            exp >>= 1;
        }

        result = resultTmp;

        return result;
    }

    long long factorial(long long n) const override
    {
        if (n < 0)
        {
            throw calculator_exceptions::CalculatorExceptionInvalidOperands("Factorial of negative number");
        }
        else if (n == 0 || n == 1)
        {
            return 1;
        }

        long long prev = factorial(n - 1);
        long long result;

        if (__builtin_mul_overflow(n, prev, &result))
        {
            throw calculator_exceptions::CalculatorExceptionOverflow("Overflow in factorial");
        }

        return result;
    }
};

}