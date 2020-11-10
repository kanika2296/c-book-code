#include <iterator> 
#include <map> 
#include <string>
#include "tocContainer.h"
class TOC : public TOCContainer
{
private:
	int nChp = 0;
	int nPages = 0;
	std::map< int,pair<int,TOCContainer*>> lst;
	int m = 0;
public:
	TOC () {}
	void add(int n,TOCContainer* e)
	{
		lst.insert(std::make_pair(m++,make_pair(n,e)));
	}
	void setNumberofChp(int n,int m)
	{
		nChp = n;
		nPages = m;
	}
	void print()
	{
		cout << "TABLE OF CONTENTS \n";
		cout << "-----------------\n";
		cout << "Cover Page\n";
		for(auto it = lst.begin(); it != lst.end(); it++)
		{
			if(it->second.first == 0)
				cout << "Chapter "<< it->second.second->getTitle() <<"\n";
			else
				cout << "\t" << it->second.second->getNo() << " " << it->second.second->getTitle() << "\n";
		}
		cout << "End Page\n";
	}
	void printPageNo(int n)
	{
		if(n > abs(nPages))
			cout << "Page "<<n<<" doesnot exists \n";
		for (auto it = lst.begin(); it != lst.end(); it++)
		{
			if (it->second.first == 1)
				if (it->second.second->getNo() == n)
				{
					it->second.second->print();
					break;
				}
		}
		//cout 
	}
};