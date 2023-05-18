#pragma once
#include <string>
#include <utility>
#include <iostream>

#include "Currency.h"
#include "PointerAttribute.h"

class Account : public PointerAttribute<Currency> {
public:
    Account(std::string name, std::shared_ptr<Currency> currency) : PointerAttribute(std::move(currency)), Name(std::move(name)), Amount(0) {}
    virtual ~Account() = default;

    virtual Account* Clone() const = 0;

    virtual void Deposit(unsigned long long value);
    virtual void Withdraw(unsigned long long value);
    std::string GetName();
    bool operator==(const Account& account) const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    std::string Name;
    unsigned long long Amount;
};