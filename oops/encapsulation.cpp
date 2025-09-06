#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    string password;

    bool authenticate(const string& inputPassword) const {
        return inputPassword == password;
    }

public:
    BankAccount(string name, double initialBalance, string pwd)
        : accountHolder(name), balance(initialBalance), password(pwd) {}

    string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance(const string& pwd) const {
        if (authenticate(pwd)) return balance;
        else {
            cout << "Access Denied: Invalid Password\n";
            return -1;
        }
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount, const string& pwd) {
        if (!authenticate(pwd)) {
            cout << "Access Denied: Invalid Password\n";
            return;
        }
        if (amount <= balance) balance -= amount;
        else cout << "Insufficient Funds\n";
    }
};

int main() {
    BankAccount acc("Aliyan", 1000.0, "secure123");

    acc.deposit(500);
    acc.withdraw(200, "secure123");

    cout << "Balance: " << acc.getBalance("secure123") << endl;

    return 0;
}

