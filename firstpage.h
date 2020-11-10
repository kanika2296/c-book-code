
class FirstPage 
{
private:
    string bookname;
    string author;
    string title = "Cover Page";
public:
    FirstPage(string bookname = "default", string author = "default") : bookname(bookname), author(author) {}
    void print()
    {
        cout << "------------------------------------------------------------------------------------------------------------- \n";
        cout << this->bookname;
        cout << "\n By \n";
        cout << this->author << "\n";
        cout << "------------------------------------------------------------------------------------------------------------- \n";
    }
    string getTitle()
    {
        return this->title;
    }
};