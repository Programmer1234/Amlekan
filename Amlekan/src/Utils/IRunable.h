#pragma once

/*
*/
class IRunable {

public:

	virtual void runOnce() = 0;

	virtual void run() = 0;

	virtual void runAsync() = 0;

	virtual void waitUntilStopped() = 0;

	virtual void stop() = 0;

	virtual bool isRunning() = 0;

};