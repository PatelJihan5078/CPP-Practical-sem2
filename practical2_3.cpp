#include <iostream>
using namespace std;

class customer
{
    string name;
    int ID;
    int balance;
public:
    customer()
    {
        name = "Default Name";
        ID = 0;
        balance = 0;
    }

    void getdata()
    {
        cout << "Enter the name of the member: ";
        cin >> name;
        cout << "Enter the ID of member: ";
        cin >> ID;
        cout << "Enter the balance of member: ";
        cin >> balance;
    }
    void showdata()
    {
        cout << "the name of the member: " << name << endl;
        cout << "the ID of member: " << ID << endl;
        cout << "the balance of member: " << balance << endl;
    }
    void transferdata(int amount, customer &receiver)
    {
        if (amount <= 0)
        {
            cout << "Amount invalid!!" << endl;
            return;
        }

        if (balance >= amount)
        {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transfer successful." << endl;
        }
        else
        {
            cout << "Transfer unsuccessful: insufficient funds." << endl;
        }
    }
};

int main()
{
    int i, n = 0, choice, b, d;
    int amount;
    customer c[10];
    do
    {
        cout << "1.Enter new data" << endl;
        cout << "2.Show data" << endl;
        cout << "3.Transfer data" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            cout << "Enter the no. of customer you want to enter: ";
            cin >> n;
            for (i = 1; i <= n; i++)
            {
                c[i].getdata();
            }
            break;
        case 2:
            for (i = 1; i <= n; i++)
            {
                cout << "Customer index " << i << ":" << endl;
                c[i].showdata();
            }
            break;
        case 3:
            if (n == 0)
            {
                cout << "No customers available. Add customers first." << endl;
                break;
            }
            cout << "Enter amount you want to send: ";
            cin >> amount;
            cout << "Enter the sender and receiver indices (1-" << (n) << "): ";
            cin >> b >> d;
            if (b < 0 || b > n || d < 0 || d > n)
            {
                cout << "Invalid customer index." << endl;
                break;
            }
            c[b].transferdata(amount, c[d]);
            break;
        case 4:
            cout << "Exiting.." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}