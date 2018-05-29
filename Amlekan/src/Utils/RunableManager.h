#pragma once

#include <memory>
#include <vector>
#include <IRunable.h>

class RunableManager {

public:

	explicit RunableManager();

	virtual ~RunableManager();

	void push(IRunable* runable);

	IRunable* pop();

	void runAll();

	size_t size();

private:

	std::vector<IRunable*> m_runableList; 

};