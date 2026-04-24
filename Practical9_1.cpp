#include <iostream>
using namespace std;

class Account {
private:
    int accID;
    string name;
    double balance;

public:
    Account() {
        accID = 0;
        name = "Test";
        balance = 0;
    }

    Account(int id, string n, double bal = 0) {
        accID = id;
        name = n;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful\n";
        } else {
            cout << "Invalid Amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance\n";
        } else if (amount <= 0) {
            cout << "Invalid Amount\n";
        } else {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        }
    }

    void display() {
        cout << "Account ID: " << accID << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << endl;
    }
};

int main() {
    Account a1;  
    Account a2(101, "Prince", 1000);
    Account a3(102, "Dwij");

    a2.deposit(500);
    a2.withdraw(200);

    a3.deposit(300);
    a3.withdraw(500);  

    a1.display();
    a2.display();
    a3.display();

    return 0;
}