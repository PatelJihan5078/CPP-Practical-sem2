#include <iostream>
using namespace std;

class Shape {
protected:
    float r;
public:
    void setR(float x) {
        r = x;
    }
};

class Circle : public Shape {
public:
    float area() {
        return 3.14 * r * r;
    }
};

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    Circle c[10];

    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        c[i].setR(x);
    }

    for (int i = 0; i < n; i++) {
        cout << "Area: " << c[i].area() << endl;
    }

    return 0;
}