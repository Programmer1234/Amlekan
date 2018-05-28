#include <memory>
#include <vector>
#include <IRunable.h>

class RunableManager {

public:

	explicit RunableManager();

	virtual ~RunableManager();

	void push(std::shared_ptr<IRunable> runable);

	std::shared_ptr<IRunable> pop();

	void runAll();

	size_t size();

private:

	std::vector<std::shared_ptr<IRunable>> m_runableList; 

};