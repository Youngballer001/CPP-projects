#include <iostream>
#include <iomanip>
using namespace std;

class Wallet
{
private:
    double balance;
    double history[5];   // Stores up to 5 transaction amounts
    int transactionCount;

public:
    // Constructor
    Wallet(double initialBalance = 0.0)
    {
        balance = initialBalance;
        transactionCount = 0;

        for (int i = 0; i < 5; i++)
        {
            history[i] = 0;
        }
    }

    // Spend money and log the transaction
    void spend(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount. Please enter a positive value." << endl;
            return;
        }

        if (amount > balance)
        {
            cout << "Transaction failed! Insufficient balance." << endl;
            return;
        }

        balance -= amount;

        // Log transaction if history is not full
        if (transactionCount < 5)
        {
            history[transactionCount] = amount;
            transactionCount++;
        }
        else
        {
            cout << "Transaction history is full. New transaction not logged." << endl;
        }

        cout << "Transaction successful. Amount spent: " << amount << endl;
        cout << "Remaining Balance: " << balance << endl;
    }

    // Display current balance
    void displayBalance()
    {
        cout << fixed << setprecision(2);
        cout << "Current Wallet Balance: " << balance << endl;
    }

    // Print transaction history
    void printHistory()
    {
        cout << "\nTransaction History:" << endl;

        if (transactionCount == 0)
        {
            cout << "No transactions recorded." << endl;
            return;
        }

        for (int i = 0; i < transactionCount; i++)
        {
            cout << "Transaction " << i + 1 << ": Spent " << history[i] << endl;
        }
    }
};

int main()
{
    double initialBalance;
    int n;
    double amount;

    // User input for initial balance
    cout << "Enter initial wallet balance: ";
    cin >> initialBalance;

    Wallet myWallet(initialBalance);

    cout << "How many spending transactions do you want to perform (Maximum 5)? ";
    cin >> n;

    if (n > 5)
    {
        cout << "Only the first 5 transactions can be stored in history." << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter amount to spend: ";
        cin >> amount;
        myWallet.spend(amount);
    }

    cout << endl;
    myWallet.displayBalance();
    myWallet.printHistory();

    return 0;
}