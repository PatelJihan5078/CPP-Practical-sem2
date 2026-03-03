#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan
{
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    // Default Constructor
    Loan()
    {
        loanID = 0;
        applicantName = "Default Applicant";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
    }

    // Parameterized Constructor
    Loan(int id, string name, double amount, double rate, int tenure)
    {
        loanID = id;
        applicantName = name;

        if (amount > 0)
            loanAmount = amount;
        else
            loanAmount = 0;

        if (rate > 0)
            annualInterestRate = rate;
        else
            annualInterestRate = 0;

        if (tenure > 0)
            tenureMonths = tenure;
        else
            tenureMonths = 0;
    }

    // Function to calculate EMI
    double calculateEMI()
    {
        double monthlyRate = annualInterestRate / (12 * 100);
        double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }

    // Function to display loan details
    void display()
    {
        cout << "\nLoan ID: " << loanID;
        cout << "\nApplicant Name: " << applicantName;
        cout << "\nLoan Amount: " << loanAmount;
        cout << "\nAnnual Interest Rate: " << annualInterestRate << "%";
        cout << "\nTenure (Months): " << tenureMonths;
        cout << "\nMonthly EMI: " << calculateEMI();
        cout << "\n----------------------------------\n";
    }

    // Getter for EMI (for comparison)
    double getEMI()
    {
        return calculateEMI();
    }
};

int main()
{
    Loan loans[10];
    int n;

    cout << "Enter number of loan accounts: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id, tenure;
        string name;
        double amount, rate;

        cout << "\nEnter details for Loan " << i + 1 << endl;

        cout << "Loan ID: ";
        cin >> id;
        cin.ignore();

        cout << "Applicant Name: ";
        getline(cin, name);

        cout << "Loan Amount: ";
        cin >> amount;

        cout << "Annual Interest Rate (%): ";
        cin >> rate;

        cout << "Tenure (Months): ";
        cin >> tenure;

        loans[i] = Loan(id, name, amount, rate, tenure);
    }

    cout << "\n--- Loan Details ---\n";
    for (int i = 0; i < n; i++)
    {
        loans[i].display();
    }

    // Find highest EMI
    double maxEMI = loans[0].getEMI();
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (loans[i].getEMI() > maxEMI)
        {
            maxEMI = loans[i].getEMI();
            index = i;
        }
    }

    cout << "\nLoan with Highest EMI:\n";
    loans[index].display();

    return 0;
}