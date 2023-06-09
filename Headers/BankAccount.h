#pragma once
#include <vector>
#include <algorithm>

#include "Account.h"
#include "Person.h"
#include "../Enums/AccountType.h"
#include "Logger.h"
#include "AccountFactory.h"

class BankAccount {
public:
    void ChangeAccountName(const std::string& newName);
    void Deposit(const unsigned long long &amount);
    void Withdraw(const unsigned long long &amount);

    void CreateAccount(AccountType accountType, const Currency& currency);
    void DeleteAccount();

    bool operator==(const BankAccount &bankAccount) const;

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &bankAccount);

    explicit BankAccount(const Person &person) : Owner(person) {}
    BankAccount(BankAccount const &other) : Owner(other.Owner) {
        if (other.account) {
            account = other.account->Clone();
        } else {
            account = nullptr;
        }
    }
    ~BankAccount() { std::cout << "Bank destructor!" << std::endl; }
    BankAccount& operator=(BankAccount other){
        swap(other);
        return *this;
    }

private:
    Person Owner;
    std::shared_ptr<Account> account;
    Logger<BankAccount> logger;

    void swap(BankAccount& other) noexcept{
        std::swap(Owner, other.Owner);
        std::swap(account, other.account);
    }
};