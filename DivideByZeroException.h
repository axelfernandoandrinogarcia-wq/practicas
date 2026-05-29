#include <stdexcept>

class DivideByZeroException : public std::runtime_error {
public:

    DivideByZeroException()
        : std::runtime_error{"intentó dividir por cero"} {}
};
