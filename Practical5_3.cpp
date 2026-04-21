#include <iostream>
#include <fstream>
using namespace std;

void add() {
    ofstream file("item.txt", ios::app);

    string name;
    int qty;
    float price;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    file << name << " " << qty << " " << price << endl;

    file.close();
}

void show() {
    ifstream file("item.txt");

    string name;
    int qty;
    float price;

    while (file >> name >> qty >> price) {
        cout << "Name: " << name << endl;
        cout << "Qty: " << qty << endl;
        cout << "Price: " << price << endl;
        cout << "----------------" << endl;
    }

    file.close();
}

void find() {
    ifstream file("item.txt");

    string name, s;
    int qty;
    float price;
    int found = 0;

    cout << "Enter name to search: ";
    cin >> s;

    while (file >> name >> qty >> price) {
        if (name == s) {
            cout << "Found:\n";
            cout << "Name: " << name << endl;
            cout << "Qty: " << qty << endl;
            cout << "Price: " << price << endl;
            found = 1;
        }
    }

    if (found == 0) {
        cout << "Not found\n";
    }

    file.close();
}

int main() {
    int ch;

    do {
        cout << "\n1.Add\n2.Show\n3.Search\n4.Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) add();
        else if (ch == 2) show();
        else if (ch == 3) find();

    } while (ch != 4);

    return 0;
}