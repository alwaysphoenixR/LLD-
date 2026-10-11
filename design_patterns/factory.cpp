// Step 1: Define the common interface

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() = default;
};

// Step 2: Create concrete implementations

class UPIPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "UPI payment: " << amount << '\n';
    }
};

class CardPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Card payment: " << amount << '\n';
    }
};

class NetBankingPayment : public Payment {
public:
    void pay(double amount) override {
        cout << "Net banking payment: " << amount << '\n';
    }
};

// Step 3: Create the factory

class PaymentFactory {
public:
    static unique_ptr<Payment> createPayment(
        const string& type
    ) {
        if (type == "UPI")
            return make_unique<UPIPayment>();

        if (type == "CARD")
            return make_unique<CardPayment>();

        if (type == "NETBANKING")
            return make_unique<NetBankingPayment>();

        throw invalid_argument("Unknown payment type");
    }
};
int main() {
    auto payment = PaymentFactory::createPayment("UPI");

    payment->pay(1500);
}