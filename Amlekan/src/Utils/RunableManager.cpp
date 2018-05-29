#include "RunableManager.h"

RunableManager::RunableManager()
{ }

RunableManager::~RunableManager()
{ }

void RunableManager::push(IRunable* runable)
{
	m_runableList.push_back(runable);
}

IRunable* RunableManager::pop()
{
	IRunable* runable = m_runableList.back();
	m_runableList.pop_back();
	return runable;
}

void RunableManager::runAll()
{
	// Iterate all and run them
	for (auto it = m_runableList.cbegin(); it != m_runableList.cend(); ++it) {
		(*it)->run();
	}
}

size_t RunableManager::size()
{
	return m_runableList.size();
}

