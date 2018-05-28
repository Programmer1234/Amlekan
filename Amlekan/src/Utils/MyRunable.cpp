#include <stdexcept>
#include <cassert>

#include "MyRunable.h"

MyRunable::MyRunable(FuncVoidNoParams func)
	: m_threadAsyncRunner()
	, m_hasAlreadyRun(false)
	, m_func(func)
{
	// Empty implementation
}

MyRunable::~MyRunable() 
{
	try {

	} CATCH_ALL()
}

void MyRunable::runOnce() {
	
	if (true == m_hasAlreadyRun) {
		throw std::runtime_error("Has already ran..");
	}

	// call the callable
	m_func();
	m_hasAlreadyRun = true;
}

void MyRunable::run() {

	// call the callable
	m_func();
}

void MyRunable::runAsync()
{
	if (isRunning()) {
		throw std::runtime_error("already running");
	}

	m_threadAsyncRunner = std::make_unique<std::thread>(m_func);
}

void MyRunable::waitUntilStopped()
{
	if (!isRunning()) {
		throw std::runtime_error("not running");
	}

	m_threadAsyncRunner->join();
	m_threadAsyncRunner.reset();
	m_hasAlreadyRun = true;

	assert(!m_threadAsyncRunner);
}

void MyRunable::stop()
{
	if (!isRunning()) {
		return;
	}
	else { // running
		waitUntilStopped();
	}
}

bool MyRunable::isRunning()
{
	return (m_threadAsyncRunner) ? true : false;
}
	