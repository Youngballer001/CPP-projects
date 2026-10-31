#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNo, double initialBalance) {
        accountNumber = accNo;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    // Deposit: adds amount to balance
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: KES " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw: prevents overdraft
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal denied." << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: KES " << amount << endl;
        return true;
    }

    // Getters (read-only access to private data)
    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    // Display account summary
    void display() const {
        cout << "Account No : " << accountNumber << endl;
        cout << "Balance    : KES " << balance << endl;
    }
};

// ── Driver / main ────────────────────────────────────────────
int main() {
    BankAccount acc("KCB-00123", 5000.00);

    acc.display();
    cout << "-------------------" << endl;

    acc.deposit(2000.00);
    acc.withdraw(1500.00);
    acc.withdraw(7000.00);   // should be denied (overdraft)
    acc.withdraw(-200.00);   // should be denied (invalid)

    cout << "-------------------" << endl;
    acc.display();

    return 0;
}