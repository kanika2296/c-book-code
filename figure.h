#include "para.h"
class Figure :public elementContainer
{
private:
    string fig;
    string caption;
public:
    Figure(string fig = "default", string caption = "default") : fig(fig), caption(caption) {}
    void setFig(string f)
    {
        this->fig = f;
    }
    void setCaption(string c)
    {
        this->caption = c;
    }
    string getfig()
    {
        return this->fig;
    }
    string getCaption()
    {
        return this->caption;
    }
    void print()
    {
        cout << fig << "\n";
        cout << caption << "\n";
    }
};