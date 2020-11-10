#include "page.h"

class Chapters : public TOC
{
private:
    string name;
    int chpNo = 0;
    int startPg;
    std::vector<Page*> pg;
public:
    Chapters(string name = "Chapter", int chpNo = 1, int startPg=1) : name(name), chpNo(chpNo + 1) , startPg(startPg) {
        
    }
    Page* addPage(string title)
    {
        pg.push_back(new Page(title,startPg++));
        return pg[pg.size() - 1];
    }
    string getTitle()
    {
        return this->name;
    }
    int getNo()
    {
        return this->chpNo;
    }
    void print()
    {
        cout << "------------------------------------------------------------------------------------------------------------- \n"; 
        cout << chpNo << ". " << name << "\n";
        cout << "***********************\n";
        for (int i = 0; i < pg.size(); i++)
        {
            pg[i]->print();
        }
        cout << "\n------------------------------------------------------------------------------------------------------------- \n";
       
    }
    Page* returnPageObj(int n)
    {
        return pg[n];
    }
    int getPages()
    {
        return this->pg.size();
    }

};