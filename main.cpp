#include <iostream>
#include <set>
using namespace std;
/* Name: Miguel Angel Prado
 * Date: 02/09/2026
 * Purpose: Implement a BankAccount class to simulate basic banking operations for multiple accounts.
 * Assignment: Lab Activities: Objects and Classes I
 */

class BankAccount {
    public:
        BankAccount();
        BankAccount(const string& number, const string& name, double bal);
        void SetName(const string& name);
        string GetNumber() const;
        string GetName() const;
        double GetBal() const;
        void deposit(double amount);
        void withdraw(double amount);

    private:
        string accountNumber;
        string accountHolderName;
        double balance;
};
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = -1.0;
}
BankAccount::BankAccount(const string& number, const string& name, double bal) {
    accountNumber = number;
    accountHolderName = name;
    balance = bal;
}
void BankAccount::SetName(const string& name) {
    accountHolderName = name;
}
string BankAccount::GetNumber() const {
    return accountNumber;
}
string BankAccount::GetName() const {
    return accountHolderName;
}
double BankAccount::GetBal() const {
    return balance;
}
void BankAccount::deposit(double amount) {
    balance += amount;
}
void BankAccount::withdraw(double amount) {
    balance -= amount;
}

int main() {
    vector<BankAccount> accounts;
    int choice;
    do {
        cout << "Select an option: " << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. View Account Info" << endl;
        cout << "5. Quit" << endl;

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, try again" << endl;
        }
        switch (choice) {
            case 1: {
                string number;
                string name;
                cout << "1. Create Account: " << endl << "Enter account number: " << endl;
                cin >> number;
                cout << "1. Create Account: " << endl << "Account number: " << number << endl << "Enter account holder name: " << endl;
                cin.ignore();
                getline(cin, name); // had some trouble getting menu to take name input, cin.ignore() fixed it as getline was taking in whitespace before it could ask for input
                BankAccount tempAccount(number, name, 0);
                accounts.push_back(tempAccount);
                cout << "Account created successfully" << endl;
                break;
            }
            case 2: {
                string number;
                double bal;
                int tempIndex;
                int x = -1;
                int y = 0;
                string tempNum;
                do {
                    cout << "2. Deposit: " << endl << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                    for (int i = 0; i < accounts.size(); i++) {
                        if (accounts.at(i).GetNumber() == number) {
                            tempNum = accounts.at(i).GetNumber();
                            tempIndex = i;
                            x = 1;
                            break;
                        }
                    }
                    if (x == -1) {
                        cout << "Account number not found, try again" << endl;
                    }
                } while (x != 1);
                while (y == 0) {

                    cout << "2. Deposit: " << endl << "Account number: " << tempNum << endl;
                    cout << "Enter deposit amount: " << endl;
                    cin >> bal;
                    cin.clear();
                    cin.ignore();
                    if (!cin.fail() && bal > 0) {
                        accounts.at(tempIndex).deposit(bal);
                        cout << "Deposit successful" << endl;
                        y = 1;
                    }
                    else {
                        cout << "Invalid input, try again" << endl;
                    }
                }
                break;
            }
            case 3: {
                double bal;
                string number;
                int tempIndex;
                int x = -1;
                int y = 0;
                string tempNum;
                do {
                    cout << "3. Withdraw: " << endl << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                    for (int i = 0; i < accounts.size(); i++) {
                        if (accounts.at(i).GetNumber() == number) {
                            x = 1;
                            tempNum = accounts.at(i).GetNumber();
                            tempIndex = i;
                            break;
                        }
                    }
                    if (x == -1) {
                        cout << "Account number not found, try again" << endl;
                    }
                } while (x == -1);
                while (y == 0) {
                    cout << "3. Withdraw: " << endl << "Account number: " << tempNum << endl;
                    cout << "Enter withdraw amount: " << endl;
                    cin >> bal;
                    cin.clear();
                    cin.ignore();
                    if (((!cin.fail()) && (bal > 0)) && (bal <= accounts.at(tempIndex).GetBal())) {
                        accounts.at(tempIndex).withdraw(bal);
                        cout << "Withdraw of $" << bal <<" successful" << endl;
                        y = 1;
                    }
                    else if (bal <= 0) {
                        cout << "Invalid input, try again" << endl;
                    }
                    else {
                        cout << "Insufficient funds, try again" << endl;
                    }
                }
                break;
            }
            case 4: {
                string number;
                int x = -1;
                int tempIndex;
                do {
                    cout << "4. View Account Info: " << endl << "Enter account number: " << endl;
                    cin >> number;
                    cin.clear();
                    cin.ignore();
                    for (int i = 0; i < accounts.size(); i++) {
                        if (accounts.at(i).GetNumber() == number) {
                            x = 1;
                            tempIndex = i;
                            break;
                        }
                    }
                    if (x == -1) {
                        cout << "Account number not found, try again" << endl;
                    }
                } while (x != 1);
                cout << "Account Info: " << endl;
                cout << "Account Number: " << accounts.at(tempIndex).GetNumber() << endl;
                cout << "Account Holder's Name: " << accounts.at(tempIndex).GetName() << endl;
                cout << "Account Balance: $" << accounts.at(tempIndex).GetBal() << endl;

                break;
            }
            case 5: {
                cout << "5. Quit:" << endl << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid input, try again" << endl;
            }
        }
    } while (choice != 5);
    return 0;
}