#pragma once
#include <vector>

#include "Account.h"
#include "Person.h"
#include "../Enums/AccountType.h"

class BankAccount {
public:
    void ChangeAccountName(const std::string& newName);
    void Deposit(const unsigned long long &amount);
    void Withdraw(const unsigned long long &amount);

    void CreateAccount(AccountType accountType, const std::shared_ptr<Currency>& currency);
    void DeleteAccount();

    bool operator==(const BankAccount &bankAccount) const;

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &bankAccount);

    explicit BankAccount(const Person &person) : Owner(person) {}
    BankAccount(const BankAccount &other) : Owner(other.Owner), account(other.account) {}
    ~BankAccount() { std::cout << "Bank destructor!" << std::endl; }
    BankAccount& operator=(const BankAccount& other){
        Owner = other.Owner;
        account = other.account;
        return *this;
    }

private:
    Person Owner;
    std::shared_ptr<Account> account;
};