#include<iostream>
using namespace std;

class emp {
private:
    string name;
    float salary;
    float bonus;

public:
    emp(string n, float s, float b = 1000) {
        name = n;
        salary = s;
        bonus = b;
    }

    inline float calculate() {
        return salary + bonus;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculate() << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    emp* employees = new emp[n];

    for (int i = 0; i < n; i++) {
        string name;
        float salary, bonus;
        int choice;

        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;

        cout << "1. Default Bonus\n2. Custom Bonus\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            employees[i] = new emp(name, salary);
        } else {
            cout << "Enter bonus: ";
            cin >> bonus;
            employees[i] = new emp(name, salary, bonus);
        }
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < n; i++) {
        employees[i]->display();
    }

    return 0;
}