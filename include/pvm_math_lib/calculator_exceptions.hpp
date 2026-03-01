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

} // namespace exceptions
} // namespace pvm_math_lib
