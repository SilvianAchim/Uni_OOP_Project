#pragma once
#include <vector>

#include "Account.h"
#include "Person.h"

class BankAccount
{
public:
    Person Owner;

    explicit BankAccount(const Person& person): Owner(person) {}

    std::vector<Account> GetAccounts();

    Account CreateNewAccount(const std::string& accountName, const Currency& currency);
    void DeleteAccount(const Account& account);
    void ChangeAccountName(const Account& account, std::string newName);
    void DepositToAnAccount(const Account& account, const unsigned long long& amount);
    void WithdrawFromAnAccount(const Account& account, const unsigned long long& amount);

    bool operator==(const BankAccount& bankAccount) const;

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount);

private:
    std::vector<Account> _accounts;

    std::vector<Account>::iterator GetAccountIterator(const Account& account);
};

