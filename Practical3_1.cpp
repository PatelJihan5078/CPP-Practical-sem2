#include <iostream>
using namespace std;

class Employee
{
    int salary, bonus, tsalary;
    string name;

public:
    Employee()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "enter bonus: ";
        cin >> bonus;
    }
    inline int total()
    {
        tsalary = bonus + salary;
        return tsalary;
    }
    void display()
    {
        cout << name << endl;
        cout << "Total salary: ";
        cout << total();
    }
};

int main()
{
    Employee c;

    c.display();
    return 0;
}