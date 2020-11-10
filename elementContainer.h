#include "printContainer.h"
class elementContainer : public printContainer
{
private:
	std::vector<printContainer*> ele;
public:
	void add(printContainer* e)
	{
		ele.push_back(e);
	}
	void print()
	{
		for (int i = 0; i < ele.size(); i++)
		{
			ele[i]->print();
		}
	}
};