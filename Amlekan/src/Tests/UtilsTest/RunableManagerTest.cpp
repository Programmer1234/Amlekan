#include <iostream>
#include <stdexcept>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../BaseTest/BaseTest.h"
#include "IRunable.h"
#include "RunableManager.h"
#include <Windows.h>

class RunableManagerTest : public BaseTest { };

TEST_F(RunableManagerTest, CtorNotThrow) {
	RunableManager runableManager;
}


class MockRunable : public IRunable {

public:
	MOCK_METHOD0(run, void());
	MOCK_METHOD0(runOnce, void());
	MOCK_METHOD0(runAsync, void());
	MOCK_METHOD0(waitUntilStopped, void());
	MOCK_METHOD0(stop, void());
	MOCK_METHOD0(isRunning, bool());
};


TEST_F(RunableManagerTest, RunAll) {
	RunableManager runableManager;
	
	MockRunable mockRunable1;
	MockRunable mockRunable2;
	MockRunable mockRunable3;

	IRunable* mockRunablePtr1 = reinterpret_cast<IRunable*>(&mockRunable1);
	IRunable* mockRunablePtr2 = reinterpret_cast<IRunable*>(&mockRunable2);
	IRunable* mockRunablePtr3 = reinterpret_cast<IRunable*>(&mockRunable3);
	
	EXPECT_CALL(mockRunable1, run()).Times(3);
	EXPECT_CALL(mockRunable2, run()).Times(2);
	EXPECT_CALL(mockRunable3, run()).Times(1);

	runableManager.push(mockRunablePtr1);
	runableManager.runAll();
	
	
	runableManager.push(mockRunablePtr2);
	runableManager.runAll();
	

	runableManager.push(mockRunablePtr3);
	runableManager.runAll();
}