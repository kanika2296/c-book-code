#include "elementContainer.h"
class Para :public elementContainer
{
private:
    string content;
public:
    Para(string content = "default") : content(content) {}
    void setContent(string c)
    {
        this->content = c;
    }
    string getPara()
    {
        return this->content;
    }
    void print()
    {
        cout << content << "\n";

    }
};