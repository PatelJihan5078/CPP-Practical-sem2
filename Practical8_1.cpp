#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    float basic;
    float bonus;

public:
    Employee(string n, float b, float bo = 1000) {
        name = n;
        basic = b;
        bonus = bo;
    }

    inline float total() {
        return basic + bonus;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << total() << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee* e = new Employee[n];

    string name;
    float basic, bonus;
    int choice;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Basic Salary: ";
        cin >> basic;

        cout << "Custom bonus? (1=Yes, 0=No): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Bonus: ";
            cin >> bonus;
            e[i] = Employee(name, basic, bonus);
        } else {
            e[i] = Employee(name, basic);
        }
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < n; i++) {
        e[i].show();
    }

    delete[] e;

    return 0;
}