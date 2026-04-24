#include <iostream>
using namespace std;

class Item {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "Default";
        price = 0;
        quantity = 0;
    }

    Item(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void addStock(int q) {
        if (q > 0) {
            quantity += q;
            cout << "Stock Added\n";
        }
    }

    void sellItem(int q) {
        if (q > quantity) {
            cout << "Not Enough Stock\n";
        } else if (q <= 0) {
            cout << "Invalid Quantity\n";
        } else {
            quantity -= q;
            cout << "Item Sold\n";
        }
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << endl;
    }
};

int main() {
    Item i1;  
    Item i2(101, "Pen", 10.5, 50);
    Item i3(102, "Book", 50, 20);

    i2.addStock(30);
    i2.sellItem(40);

    i3.sellItem(25);  
    i3.addStock(10);

    i1.display();
    i2.display();
    i3.display();

    return 0;
}