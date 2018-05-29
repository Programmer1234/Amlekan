#pragma once

#include <thread>
#include <memory>
#include "BasicDefs.h"
#include "IRunable.h"

/*
typedef enum RunableState_e
{
	RUNABLE_RUNNING,
	RUNABLE_STOPPED,
} RunableState;
*/

typedef std::unique_ptr<std::thread> ThreadUPtr;

class MyRunable : IRunable
{
public:

	explicit MyRunable(FuncVoidNoParams func);

	virtual ~MyRunable();

	void runOnce();

	void run();

	void runAsync();

	void waitUntilStopped();

	void stop();

	bool isRunning();

private:
	ThreadUPtr						m_threadAsyncRunner;
	bool							m_hasAlreadyRun;
	FuncVoidNoParams				m_func;
};