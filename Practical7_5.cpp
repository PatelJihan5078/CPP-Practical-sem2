#include <iostream>
using namespace std;

class Book {
private:
    int id;
    string title, author;
    int copies;

public:
    void addBook() {
        cout << "Enter ID, Title, Author, Copies:\n";
        cin >> id >> title >> author >> copies;
    }

    void issueBook() {
        if (copies > 0) {
            copies--;
            cout << "Book Issued\n";
        } else {
            cout << "No Copies Available\n";
        }
    }

    void returnBook() {
        copies++;
        cout << "Book Returned\n";
    }

    void display() {
        cout << id << " " << title << " " << author << " " << copies << endl;
    }
};

int main() {
    Book b[10];
    int n = 0, choice;

    do {
        cout << "\n1.Add Book\n2.Issue Book\n3.Return Book\n4.Display Books\n5.Exit\n";
        cin >> choice;

        if (choice == 1) {
            b[n].addBook();
            n++;
        }
        else if (choice == 2) {
            int i;
            cout << "Enter Book Index: ";
            cin >> i;
            if (i < n) b[i].issueBook();
        }
        else if (choice == 3) {
            int i;
            cout << "Enter Book Index: ";
            cin >> i;
            if (i < n) b[i].returnBook();
        }
        else if (choice == 4) {
            cout << "Total Books: " << n << endl;
            for (int i = 0; i < n; i++) {
                b[i].display();
            }
        }

    } while (choice != 5);

    return 0;
}