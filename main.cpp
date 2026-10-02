#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Library
{
public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;
};

int main()
{

    Library lib[20];
    int input = 0;
    int count = 0;

    while (input != 5)
    {

        cout << "Enter 1 to input details like id, name, author, student, price, pages" << endl;
        cout << "Enter 2 to display all the details of the books" << endl;
        cout << "Enter 3 to search the book by id" << endl;
        cout << "Enter 4 to search the book by name" << endl;
        cout << "Enter 5 to exit" << endl;

        cin >> input;

        switch (input)
        {

        case 1:
        start:

            if (count >= 20)
            {
                cout << "Library is full!" << endl;
                break;
            }

            cout << "Enter the id of the book " << endl;
            cin >> lib[count].id;

            // FIX: remove leftover '\n' from input buffer
            cin.ignore();

            cout << "Enter the name of the book" << endl;
            cin.getline(lib[count].name, 100);

            cout << "Enter the author of the book " << endl;
            cin.getline(lib[count].author, 100);

            cout << "Enter the student name " << endl;
            cin.getline(lib[count].student, 100);

            cout << "Enter the price of the book" << endl;
            cin >> lib[count].price;

            cout << "Enter the number of pages in the book" << endl;
            cin >> lib[count].pages;

            count++;

            break;

        case 2:

            if (count == 0)
            {
                cout << "No books available." << endl;
                break;
            }

            for (int i = 0; i < count; i++)
            {

                cout << "\nBook Id: " << lib[i].id << endl;
                cout << "Book Name: " << lib[i].name << endl;
                cout << "Book Author: " << lib[i].author << endl;
                cout << "Book Student: " << lib[i].student << endl;
                cout << "Book Price: " << lib[i].price << endl;
                cout << "Book Pages: " << lib[i].pages << endl;
            }

            break;

        case 3:
        {

            int searchId;
            bool found = false;

            cout << "Enter the id of the book to search: ";
            cin >> searchId;

            for (int i = 0; i < count; i++)
            {

                if (lib[i].id == searchId)
                {

                    cout << "\nBook found!" << endl;
                    cout << "Book Id: " << lib[i].id << endl;
                    cout << "Book Name: " << lib[i].name << endl;
                    cout << "Book Author: " << lib[i].author << endl;
                    cout << "Book Student: " << lib[i].student << endl;
                    cout << "Book Price: " << lib[i].price << endl;
                    cout << "Book Pages: " << lib[i].pages << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book not found." << endl;
            }

            break;
        }

        case 4:
        {

            char searchName[100];
            bool found = false;

            cin.ignore();

            cout << "Enter the name of the book to search: ";
            cin.getline(searchName, 100);

            for (int i = 0; i < count; i++)
            {

                if (strcmp(lib[i].name, searchName) == 0)
                {

                    cout << "\nBook found!" << endl;
                    cout << "Book Id: " << lib[i].id << endl;
                    cout << "Book Name: " << lib[i].name << endl;
                    cout << "Book Author: " << lib[i].author << endl;
                    cout << "Book Student: " << lib[i].student << endl;
                    cout << "Book Price: " << lib[i].price << endl;
                    cout << "Book Pages: " << lib[i].pages << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Book not found." << endl;
            }

            break;
        }

        case 5:

            exit(0);

        default:

            cout << "You have entered wrong value, please type again" << endl;
            goto start;
        }
    }

    return 0;
}