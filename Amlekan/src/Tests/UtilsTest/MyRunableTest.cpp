#include <iostream>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"1

#include "../BaseTest/BaseTest.h"
#include "IRunable.h"
#include "RunableManager.h"
#include <Windows.h>

class MockRunable : public IRunable {
	
	MOCK_METHOD0(run, void());
	MOCK_METHOD0(runOnce, void());
	MOCK_METHOD0(runAsync, void());
	MOCK_METHOD0(waitUntilStopped, void());
	MOCK_METHOD0(stop, void());
	MOCK_METHOD0(isRunning, bool());
};

class RunableManagerTest : public BaseTest { };

TEST_F(RunableManagerTest, CtorNotThrow) {
	RunableManager runableManager();
}
