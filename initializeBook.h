#include "createBook.h"

class InitializeBook
{
	private:

	public:
		InitializeBook()
		{
			string cnt = "y";
			while (cnt == "y")
			{
				cout << " Selcect an option : \n1. Print Book - Clean Code\n2. Print Table of contents\n3. Print by Chapter number\n4. Print by page number\n5. Browse Book\n";
				int option;
				CreateBook book;
				cin >> option;
				switch (option)
				{
				case 1:
					book.print();
					break;
				case 2: book.printIndex();
					break;
				case 3: book.printBookChapter();
					break;
				case 4: book.printIndex();
					book.printPage();
					break;
				case 5:  book.printIndex();
					book.Browse();
					break;
				default: break;
				}
				cout << "Do you want to continue, Yes [y] or No [n] :\n";
				cin >> cnt;
			}
		}

};