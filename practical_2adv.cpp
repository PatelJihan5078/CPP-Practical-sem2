#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct book
{
    int BookID;
    string title;
    string author;
    int copies,tcopies;
};

void addboooks(book b[], int n, int &count)
{
    for (int i = count; i < count + n; i++)
    {
        cout << "Enter the book ID " << i + 1 << ": ";
        cin >> b[i].BookID;
        cout << "Enter the book title " << i + 1 << ": ";
        cin >> b[i].title;
        cout << "Enter the author name " << i + 1 << ": ";
        cin >> b[i].author;
        cout << "Enter Copies: ";
        cin >> b[i].copies;
        b[i].tcopies=b[i].copies;
    }
    count += n;
}

int main()
{
    book b[30];
    int n;
    int count = 0,choice;
    do
    {  cout << "\n--- Library Management (C++) ---";
        cout << "\n1. Add Book";
        cout << "\n2. Issue Book";
        cout << "\n3. Return Book";
        cout << "\n4. Display Books";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the no. of books you want to enter: ";
            cin >> n;
            addboooks(b, n, count);
            cout << "Books Added Successfully!\n";
        }

        else if (choice == 2)
        {
            int id, found = 0;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            for (int i = 0; i < count; i++)
            {
                if (b[i].BookID == id)
                {
                    found = 1;
                    if (b[i].copies > 0)
                    {
                        b[i].copies--;
                        cout << "Book Issued Successfully!\n";
                    }
                    else
                    {
                        cout << "No Copies Available!\n";
                    }
                    break;
                }
            }
            if (found == 0)
                cout << "Book Not Found!\n";
        }

        else if (choice == 3)
        {
            int id, found = 0;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            for (int i = 0; i < count; i++)
            {
                if (b[i].BookID == id)
                {
                    if(b[i].copies<b[i].tcopies){
                    b[i].copies++;
                    found = 1;
                    cout << "Book Returned Successfully!\n";
                    break;
                    }
                }
            }
            if (found == 0)
                cout << "That book was not issued!\n";
        }
        else if (choice == 4)
        {
            cout << "\nTotal Books: " << count << endl;
            for (int i = 0; i < count; i++)
            {
                cout << "\nID: " << b[i].BookID;
                cout << "\nTitle: " << b[i].title;
                cout << "\nAuthor: " << b[i].author;
                cout << "\nCopies: " << b[i].copies << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting Program...\n";
        }
        else
        {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
