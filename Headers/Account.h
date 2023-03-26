#pragma once
#include <string>
#include <utility>

#include "Currency.h"

class Account
{
public:
    std::string Name;
    Currency Banknote;

    Account(std::string name, Currency currency) : Name(std::move(name)), Banknote(std::move(currency)), _amount(0) {}
    void Deposit(unsigned long long value);
    void Withdraw(unsigned long long value);

    bool operator==(const Account& account) const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);

private:
    unsigned long long _amount;
};

