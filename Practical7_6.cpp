#include <iostream>
using namespace std;

class Wallet {
private:
    int walletID;
    string userName;
    double balance;

public:
    Wallet(int id, string name, double bal) {
        walletID = id;
        userName = name;
        balance = bal;
    }

    void loadMoney(double amount) {
        balance += amount;
        cout << "Money Loaded Successfully\n";
    }

    void transferMoney(Wallet &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance\n";
        } else {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer Successful\n";
        }
    }

    void display() {
        cout << "Wallet ID: " << walletID << endl;
        cout << "User Name: " << userName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Wallet w1(101, "Prince", 1000);
    Wallet w2(102, "Dwij", 500);

    w1.loadMoney(200);
    w1.transferMoney(w2, 300);

    w1.display();
    cout << endl;
    w2.display();

    return 0;
}