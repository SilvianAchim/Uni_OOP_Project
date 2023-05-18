#pragma once
#include <vector>

#include "Account.h"
#include "Person.h"

class BankAccount {
public:
    Person Owner;

    Account * CreateNewAccount(const std::string &accountName, const std::shared_ptr<Currency> &currency, bool isSavings);

    void DeleteAccount(const Account &account);

    void ChangeAccountName(const Account &account, std::string newName);

    void DepositToAnAccount(const Account &account, const unsigned long long &amount);

    void WithdrawFromAnAccount(const Account &account, const unsigned long long &amount);

    bool operator==(const BankAccount &bankAccount) const;

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &bankAccount);

    explicit BankAccount(const Person &person) : Owner(person) {}
    BankAccount(const BankAccount &other) : Owner(other.Owner), Accounts(other.Accounts) {}
    ~BankAccount() { std::cout << "Bank destructor!" << std::endl; }
    BankAccount& operator=(const BankAccount& other){
        Owner = other.Owner;
        Accounts = other.Accounts;
        return *this;
    }

private:
    std::vector<std::shared_ptr<Account>> Accounts;
    typename std::vector<std::shared_ptr<Account>>::iterator GetAccountIterator(const Account &account);
};