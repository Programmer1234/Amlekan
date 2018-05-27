#include <iostream>
#include <string>

#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING 1

#include "gmock/gmock.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}