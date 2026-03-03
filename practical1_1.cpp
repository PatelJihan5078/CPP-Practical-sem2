#include <iostream>
using namespace std;
class Wallet
{
    string name;
    int walletID;
    int balance;

public:
    void loadWallet()
    {
        cout << "Enter User name: ";
        getline(cin, name);
        cout << "Enter walletID: ";
        cin >> walletID;
        cout << "Enter Current Balance: ";
        cin >> balance;
        cin.ignore(); 
    }
    void loadMoney(float amt){
        balance=balance+amt;
    }
    void withdrawMoney(int withdrawAmt){
        if(withdrawAmt<balance)
        {
            balance=balance-withdrawAmt;
        }
        else
        {
            cout<<"Insufficient Balance";
        }

    }

     void display(){
        cout<<"Name is: "<<name<<endl<<"Wallet ID is: "<<walletID<<endl;
        cout<<"Balance is: "<<balance<<endl;
    }
    void transfer(Wallet &w2,double transferAmt)
    {
        if(transferAmt<=0)
        cout<<"Invalid Entry";
        else if(transferAmt>balance)
        cout<<"Insufficient Balance";
        else{
        balance=balance -transferAmt;
        w2.balance=w2.balance+transferAmt;}
    }
};
/*void Wallet::loadWallet()
{
    cout << "Enter User name: ";
    getline(cin, name);
    cout << "Enter walletID: ";
    cin >> walletID;
    cout << "Enter Current Balance: ";
    cin >> balance;
}
void Wallet::displayWallet()
{
    cout << "User name is: ";
    cout << name << endl;
    cout << "WalletID of the wallet is: ";
    cout << walletID << endl;
}   
void Wallet::displayMoney()
{
    cout << "Current balance of the wallet is: ";
    cout << balance << endl;
}*/

int main()
{
    Wallet w1;
    Wallet w2;
    int amt;
    cout << endl<< "Enter Wallet 1 details:-" << endl;
    w1.loadWallet();
    cout << endl<< "Details of Wallet 1 is:-" << endl;
    w1.display();
    cout << endl<< "Enter Wallet 2 details:-" << endl;
    w2.loadWallet();
    cout << endl<< "Details of Wallet 2 is:-" << endl;
    w2.display();
    cout<<endl<<endl<<"Enter Amount to be loaded in Wallet 1:-"<<endl;
    cin>>amt;
    w1.loadMoney(amt);
    w1.display();
    cout<<endl<<endl<<"Enter Withdrawing Amount from Wallet 1:-"<<endl;
    cin>>amt;
    w1.withdrawMoney(amt);
    w1.display();
    cout<<endl<<endl<<"Enter Transferring Amount from Wallet 1 to Wallet 2"<<endl;
    cin>>amt;
    w1.transfer(w2,amt);
    cout<<endl<<endl<<"w2 Updated Details is below:-"<< endl;
    w2.display();
    return 0;
}