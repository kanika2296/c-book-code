#include "Book.h"

class CreateBook {
private:
    Book b;
public:
    CreateBook() {
        b.setTitle("Clean Code");
        b.setPrice(700);
        b.setAuthor("Robert C. Martin");
        b.addCoverPage();
        b.addEndPage();
        // adding two chapters
        Chapters* ch = b.addChapters("Clean Code ");
        ch->addPage("There will be code")->addPara("One might argue that a book about code is somehow behind the times—that code is no longer the issue  that we should be concerned about models and requirements instead. Indeed some have suggested that we are close to the end of code");
        Page* pg1 = ch->addPage("Bad Code");
        pg1->addFigure("This is figure", "This is caption");
        pg1->addPara("I know of one company that, in the late 80s, wrote a killer app.It was very popular, and lots of professionals bought and used it. ");
        pg1->addFigure("This is a figure", "CAPTION");
        Chapters* ch2 = b.addChapters("Meaningfull Names");
        ch2->addPage("Introduction")->addPara("Names are everywhere in software. We name our variables, our functions, our arguments,classes, and packages");
        ch2->addPage("Use Intension Revealing names")->addPara("This is a paragraph");

    }
   void printIndex()
   {
        b.getToc();
    }
    void print()
    {
        b.print();
    }
    void printBookChapter()
    {
        b.printChapterList();
        cout << "Enter the chapter number (int) : \n";
        int number;
        cin >> number;
        b.printChapter(number - 1);
    }
    void printPage()
    {
        int number;
        cout << "Enter page number (int) :\n";
        cin >> number;
        b.printPage(number);
    }
    void Browse()
    {
        string cnt = "o";
        int n = 0;
        b.printFirstPage();
        cout << "\n \t \t Next [n] \t \t\n";
        cin >> cnt;
        while (cnt == "n" || cnt == "p")
        {
            if (cnt == "n")
            {
                n++;
            }
            else if (cnt == "p")
            {
                n--;
            }
            if(n == 0 && cnt == "p")
                b.printFirstPage();
            if (n > b.totalPages())
                b.printEndPage();
            else {
                b.printPage(n);
            }
            cout << "\n \t \t Next [n] | Previous [p] \t \t\n";
            cin >> cnt;
        }
    }
};