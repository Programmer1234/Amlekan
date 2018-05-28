#include <iostream>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../BaseTest/BaseTest.h"
#include "MyRunable.h"

#include <Windows.h>7


void callable() {
	std::cout << "called" << std::endl;
}

class MyRunableTest : public BaseTest { };

TEST_F(MyRunableTest, CtorNotThrow) {
	MyRunable runable(callable);
}

TEST_F(MyRunableTest, RunSanity) {
	MyRunable runable(callable);
	runable.run();
}

TEST_F(MyRunableTest, RunOnceSanity) {
	MyRunable runable(callable);
	runable.runOnce();
}

TEST_F(MyRunableTest, RunOnceCalledTwice) {
	MyRunable runable(callable);
	runable.runOnce();
	EXPECT_THROW(runable.runOnce(), std::runtime_error);
}

TEST_F(MyRunableTest, RunOnceCalledTwiceAfterRuns) {
	MyRunable runable(callable);
	runable.run();
	EXPECT_NO_THROW(runable.runOnce());
	EXPECT_THROW(runable.runOnce(), std::runtime_error);
}

TEST_F(MyRunableTest, RunOnceRunRunOnceThrow) {
	MyRunable runable(callable);
	EXPECT_NO_THROW(runable.runOnce());
	EXPECT_NO_THROW(runable.run());
	EXPECT_THROW(runable.runOnce(), std::runtime_error);
}

TEST_F(MyRunableTest, IsRunningSanity) {
	MyRunable runable(callable);
	EXPECT_FALSE(runable.isRunning());
	runable.run();
	EXPECT_FALSE(runable.isRunning());
	runable.runAsync();
	EXPECT_TRUE(runable.isRunning());
	runable.waitUntilStopped();
	EXPECT_FALSE(runable.isRunning());
	runable.runAsync();
	EXPECT_TRUE(runable.isRunning());
	runable.stop();
	EXPECT_FALSE(runable.isRunning());
}

TEST_F(MyRunableTest, XFailRunAsyncRunOnce) {
	MyRunable runable(callable);
	runable.runAsync();
	EXPECT_THROW(runable.runOnce(), std::runtime_error);
}

TEST_F(MyRunableTest, AnotherMistake) {
	MyRunable runable(callable);
	runable.runAsync();
	Sleep(500);
	ASSERT_FALSE(runable.isRunning());
}