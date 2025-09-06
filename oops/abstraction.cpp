#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class PaymentProcessor {
public:
    virtual void authenticateUser(const string& userId) = 0;
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentProcessor() {} // Virtual destructor for safe polymorphism
};

// Derived class for Credit Card payments
class CreditCardProcessor : public PaymentProcessor {
public:
    void authenticateUser(const string& userId) override {
        cout << "Authenticating credit card user: " << userId << endl;
    }

    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
    }
};

// Derived class for PayPal payments
class PayPalProcessor : public PaymentProcessor {
public:
    void authenticateUser(const string& userId) override {
        cout << "Authenticating PayPal user: " << userId << endl;
    }

    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

// Client code using abstraction
void makeTransaction(PaymentProcessor* processor, const string& userId, double amount) {
    processor->authenticateUser(userId);
    processor->processPayment(amount);
}

int main() {
    CreditCardProcessor cc;
    PayPalProcessor pp;

    makeTransaction(&cc, "Aliyan123", 250.0);
    makeTransaction(&pp, "AliyanPay", 150.0);

    return 0;
}

