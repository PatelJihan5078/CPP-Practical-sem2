#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = " ";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
    }

    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double monthlyRate = annualInterestRate / (12 * 100);
        double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }

    void displayLoanDetails() {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: ₹" << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: ₹" << calculateEMI() << endl;
    }
};

int main() {
    int id, tenure;
    string name;
    double amount, rate;

    cout << "Enter Loan ID: ";
    cin >> id;

    cin.ignore();
    cout << "Enter Applicant Name: ";
    getline(cin, name);

    cout << "Enter Loan Amount: ";
    cin >> amount;

    cout << "Enter Annual Interest Rate: ";
    cin >> rate;

    cout << "Enter Loan Tenure (months): ";
    cin >> tenure;

    Loan loan1(id, name, amount, rate, tenure);
    loan1.displayLoanDetails();

    return 0;
}