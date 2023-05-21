#pragma once
#include <string>
#include <utility>
#include <iostream>
#include <memory>

#include "Currency.h"

class Account  {
public:
    Account(std::string name, const std::shared_ptr<Currency>& currency_) : Name(std::move(name)), Amount(0), currency(currency_) {}
    virtual ~Account() = default;

    virtual Account* Clone() const = 0;

    std::string GetName();

    virtual void Deposit(unsigned long long value) = 0;
    virtual void Withdraw(unsigned long long value) = 0;
    virtual void ChangeName(const std::string& newName);

    bool operator==(const Account& account) const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    std::string Name;
    unsigned long long Amount;
    std::shared_ptr<Currency> currency;
};