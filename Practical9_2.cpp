#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

void updatePoint(Point* p) {
    p->move(5, 5);
}

int main() {
    Point p(1, 2);

    cout << "Initial Point: ";
    p.display();

    p.move(2, 3).move(-1, 4);

    cout << "After chaining move: ";
    p.display();

    updatePoint(&p);

    cout << "After pointer update: ";
    p.display();

    return 0;
}