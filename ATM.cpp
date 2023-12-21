#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    /**
     * Get the current balance of the bank account.
     * @return The current balance.
     */
    double getBalance() {
        return balance;
    }

    /**
     * Deposit money into the bank account.
     * @param amount The amount to deposit.
     */
    void deposit(double amount) {
        balance += amount;
    }

    /**
     * Withdraw money from the bank account.
     * @param amount The amount to withdraw.
     * @return True if the withdrawal is successful, false otherwise.
     */
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Get a valid amount from the user.
 * @return The valid amount entered by the user.
 */
double getValidAmount() {
    string input;
    double amount;
    while (true) {
        getline(cin, input);
        stringstream ss(input);
        char extra;
        if (!(ss >> amount) || amount < 0 || (amount * 100) != int(amount * 100) || ss >> extra) {
            cout << "Invalid input. Please enter a positive number with up to two decimal places: ";
        } else {
            break;
        }
    }
    return amount;
}

int main() {
    BankAccount account;
    int choice;

    while (true) {
        cout << fixed << setprecision(2);
        cout << "Current balance: $" << account.getBalance() << "\n";
        cout << "1. Deposit money\n";
        cout << "2. Withdraw money\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Deposit money
                cout << "Enter amount to deposit: ";
                account.deposit(getValidAmount());
                break;
            case 2: // Withdraw money
                cout << "Enter amount to withdraw: ";
                if (!account.withdraw(getValidAmount())) {
                    cout << "Insufficient balance.\n";
                }
                break;
            case 3: // Exit the program
                cout << "Thank you for using our ATM. Goodbye!\n";
                return 0;
            default: // Invalid choice
                cout << "Invalid choice. Please choose between 1-3.\n";
                break;
        }
    }

    return 0;
}