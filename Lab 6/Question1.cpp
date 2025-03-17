#include<iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    int balance;
    bool isFrozen;

public:
    BankAccount(string accountNum, int initialBalance)
        : accountNumber(accountNum), balance(initialBalance), isFrozen(false) {}

    virtual void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {
        if (balance - amount < 0) {
            cout << "Insufficient funds for withdrawal." << endl;
            return;
        }
        balance -= amount;
        cout << "New balance: " << balance << endl;
    }

    void freeze() {
        isFrozen = true;
    }

    void unfreeze() {
        isFrozen = false;
    }

    int getBalance() const {
        return balance;
    }
};

class SavingAccount : public BankAccount {
protected:
    float monthlyInterest;

public:
    SavingAccount(string accountNum, int initialBalance, float interestRate)
        : BankAccount(accountNum, initialBalance), monthlyInterest(interestRate) {}

    void setMonthlyInterest(float newInterestRate) {
        monthlyInterest = newInterestRate;
    }

    float getMonthlyInterest() const {
        return monthlyInterest;
    }
};

class CheckingAccount : public BankAccount {
protected:
    int overdraftLimit;

public:
    CheckingAccount(string accountNum, int initialBalance, int limit)
        : BankAccount(accountNum, initialBalance), overdraftLimit(limit) {}

    void setOverdraftLimit(int newLimit) {
        overdraftLimit = newLimit;
    }

    int getOverdraftLimit() const {
        return overdraftLimit;
    }
};

class BusinessAccount : public BankAccount {
protected:
    int corporateTax;

public:
    BusinessAccount(string accountNum, int initialBalance, int taxRate)
        : BankAccount(accountNum, initialBalance), corporateTax(taxRate) {}

    void deposit(int amount) override {
        int adjustedDeposit = amount - corporateTax;
        if (balance + adjustedDeposit < 0) {
            balance = 0;
            cout << "Balance is too low after tax deduction. Account set to zero." << endl;
        } else {
            balance += adjustedDeposit;
        }
    }

    void setCorporateTax(int newTaxRate) {
        corporateTax = newTaxRate;
    }
};

class Customer {
public:
    void deposit(BankAccount &account, int amount) {
        account.deposit(amount);
        cout << "Deposited " << amount << " to account. New balance: " << account.getBalance() << endl;
    }

    void withdraw(BankAccount &account, int amount) {
        account.withdraw(amount);
    }
};

class Teller : public Customer {
public:
    void freezeAccount(BankAccount &account) {
        account.freeze();
        cout << "Account frozen." << endl;
    }

    void unfreezeAccount(BankAccount &account) {
        account.unfreeze();
        cout << "Account unfrozen." << endl;
    }
};

class Manager : public Teller {
public:
    void changeOverdraftLimit(CheckingAccount &account, int newLimit) {
        account.setOverdraftLimit(newLimit);
        cout << "Overdraft limit updated to: " << newLimit << endl;
    }

    void changeCorporateTax(BusinessAccount &account, int newTaxRate) {
        account.setCorporateTax(newTaxRate);
        cout << "Corporate tax rate updated to: " << newTaxRate << "%" << endl;
    }

    void changeMonthlyInterest(SavingAccount &account, float newInterestRate) {
        account.setMonthlyInterest(newInterestRate);
        cout << "Monthly interest rate updated to: " << newInterestRate << "%" << endl;
    }
};

int main() {
    SavingAccount savings("S123", 1000, 5.0);
    CheckingAccount checking("C456", 500, 200);
    BusinessAccount business("B789", 5000, 10);

    Manager manager;
    Teller teller;
    Customer customer;

    customer.deposit(savings, 200);
    teller.freezeAccount(checking);
    manager.changeOverdraftLimit(checking, 500);
    customer.withdraw(business, 1000);
    teller.unfreezeAccount(checking);
    cout << "Checking account balance after unfreezing: " << checking.getBalance() << endl;

    return 0;
}

