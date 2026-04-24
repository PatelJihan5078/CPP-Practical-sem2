#include <iostream>
using namespace std;

class Rectangle {
private:
    float length, width;

public:
    void setData() {
        cout << "Enter Length and Width: ";
        cin >> length >> width;
    }

    void update() {
        cout << "Update Length and Width: ";
        cin >> length >> width;
    }

    float area() {
        return length * width;
    }

    float perimeter() {
        return 2 * (length + width);
    }

    void display() {
        cout << "Length: " << length << " Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r[10];
    int n = 0, choice;

    do {
        cout << "\n1.Add Rectangle\n2.Update Rectangle\n3.Display All\n4.Exit\n";
        cin >> choice;

        if (choice == 1) {
            r[n].setData();
            n++;
        }
        else if (choice == 2) {
            int i;
            cout << "Enter Rectangle Index: ";
            cin >> i;
            if (i < n) r[i].update();
        }
        else if (choice == 3) {
            for (int i = 0; i < n; i++) {
                cout << "\nRectangle " << i + 1 << endl;
                r[i].display();
            }
        }

    } while (choice != 4);

    return 0;
}