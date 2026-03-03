#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

Book library[100];
int countBooks = 0;

// Add new book
void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> library[countBooks].id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, library[countBooks].title);

    cout << "Enter Author Name: ";
    getline(cin, library[countBooks].author);

    cout << "Enter Number of Copies: ";
    cin >> library[countBooks].copies;

    countBooks++;
    cout << "Book added successfully!\n";
}

// Issue book
void issueBook() {
    int id;
    cout << "\nEnter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            if (library[i].copies > 0) {
                library[i].copies--;
                cout << "Book issued successfully!\n";
            } else {
                cout << "No copies available.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return book
void returnBook() {
    int id;
    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            library[i].copies++;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Display all books
void displayBooks() {
    if (countBooks == 0) {
        cout << "\nNo books in library.\n";
        return;
    }

    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << library[i].id
             << " | Title: " << library[i].title
             << " | Author: " << library[i].author
             << " | Copies: " << library[i].copies << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                    addBook(); 
                    break;
            case 2:
                    issueBook();
                    break;
            case 3: 
                    returnBook(); 
                    break;
            case 4: 
            displayBooks(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}