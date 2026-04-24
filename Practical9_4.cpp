#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float m1, m2, m3;

public:
    Student() {
        roll = 0;
        name = "Test";
        m1 = m2 = m3 = 0;
    }

    Student(int r, string n, float a, float b, float c) {
        roll = r;
        name = n;
        m1 = a;
        m2 = b;
        m3 = c;
    }

    float average() {
        return (m1 + m2 + m3) / 3;
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << m1 << " " << m2 << " " << m3 << endl;
        cout << "Average: " << average() << endl;
        cout << endl;
    }
};

int main() {
    Student s1;  

    Student s2(1, "Prince", 80, 85, 90);
    Student s3(2, "Dwij", 70, 75, 80);

    s1.display();
    s2.display();
    s3.display();

    return 0;
}