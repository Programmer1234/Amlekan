#include "Calculator.h"

namespace Utils {

namespace Calculator {

int factorial(int n) {
	if (1 == n) {
		return n;
	}
	else {
		return n * factorial(n - 1);
	}
}

} // namespace Math

} // namespace Utils