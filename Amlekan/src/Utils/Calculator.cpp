#include <exception>
#include <stdexcept>

#include "Calculator.h"

namespace Utils {

namespace Calculator {

int factorial(int n) {
	if (0 >= n) {
		throw std::runtime_error("Bad input");
	}
	else if (1 == n) {
		return n;
	}
	else {
		return n * factorial(n - 1);
	}
}

} // namespace Math

} // namespace Utils