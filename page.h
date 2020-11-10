#include "figure.h"
#include "toc.h"
class Page : public TOC, public elementContainer
{
    private:
        string title;
        int pgNo;
    public:
        
        Page(string title = "default",int pgN0=1) :title(title),pgNo(pgN0) {
        }
        void addPara(string content) {
            elementContainer::add(new Para(content));
        }
        void addFigure(string name, string caption) {
            elementContainer::add(new Figure(name,caption));
        }
        int getNo()
        {
            return this->pgNo;
        }
        void print()
        {
            
            cout << title <<  "\n\n";
            elementContainer::print();
            cout << "------------------------------end of page ----------------------------------- \n";
        }
        string getTitle()
        {
            return this->title;
        }
};
