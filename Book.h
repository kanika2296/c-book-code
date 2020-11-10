#include "firstpage.h"
#include "endpage.h"
#include "chapters.h"

class Book
{
private:
    string author;
    string title;
    int price;
    FirstPage firstpg;
    EndPage endpg;
    TOC t;
    std::vector<Chapters*> chapter;
public:
    Book(string title = "default", string author = "default", int price = 0) :
        title(title), author(author), price(price) {
        t = TOC();
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    int getPrice()
    {
        return this->price;
    }
    string getAuthor()
    {
        return this->author;
    }
    string getTitle()
    {
        return this->title;
    }
    Chapters* addChapters(string c)
    {
        int n = chapter.size() - 1;
        int pgStart = getChpaterPages(n);
        chapter.push_back(new Chapters(c, chapter.size(),++pgStart));
        return chapter[chapter.size() - 1];
    }
    void addCoverPage()
    {
        firstpg = FirstPage(this->title, this->author);
    }
    void addEndPage()
    {
        endpg = EndPage(this->price);
    }
    void print()
    {
        firstpg.print();
        for (int i = 0; i < chapter.size(); i++)
        {
            chapter[i]->print();
        }
        endpg.print();
    }
    void printChapterList()
    {
        for (int i = 0; i < chapter.size(); i++)
        {
            cout << i + 1 <<"\t"<< chapter[i]->getTitle() << "\n";
        }
    }
    void printChapter(int n)
    {
        if (n < chapter.size())
            chapter[n]->print();
        else
            cout << "Chapter " << n+1 << " doesnot exists \n";
    }
    int getChpaterPages(int n)
    {
        if (n == -1)
            return 0;
        return chapter[n]->getPages();
    }
    int totalPages()
    {
        int sum = 0;
        for (int i = 0; i < chapter.size(); i++)
        {
            sum +=chapter[i]->getPages();
        }
        t.setNumberofChp(chapter.size(), sum);
        return sum;
    }
    void createIndex()
    {   
        int p = totalPages();
        for(int i=0;i<chapter.size();i++)
        {  
            t.add(0, chapter[i]); // add chapter to toc 
            for (int j = 0; j < chapter[i]->getPages(); j++)
            {
                t.add(1, chapter[i]->returnPageObj(j));
            }
        }
    }
    void getToc()
    {
        createIndex();
        t.print();
    }
    void printPage(int n)
    {
        cout << "------------------------------------------------------------------------------------------------------------- \n";
        t.printPageNo(n);
    }
    void printFirstPage()
    {
        firstpg.print();
    }
    void printEndPage()
    {
        endpg.print();
    }
};