
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "BaseTest.h"

TEST_F(BaseTest, MethodBarDoesAbc) {
	EXPECT_EQ(0, 0);
}

// Tests that Base does Xyz.
TEST_F(BaseTest, DoesXyz) {
	// Exercises the Xyz feature of Foo.
}