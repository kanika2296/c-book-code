class EndPage
{
private:
    int price;
    string note = "Thank You !!";
    string title = "End Page";
public:
    EndPage(int price = 0) : price(price) {}
    void print()
    {
        cout << "------------------------------------------------------------------------------------------------------------- \n";
        cout << "Buy this book for Rs: " << this->price;
        cout << "\n  \n";
        cout << note << "\n";
        cout << "------------------------------------------------------------------------------------------------------------- \n";
    }
    string getTitle()
    {
        return this->title;
    }
};
