#pragma once
#include <string>
#include <utility>
#include <iostream>

#include "Currency.h"
#include "PointerAttribute.h"

class Account : public PointerAttribute<Currency> {
public:
    std::string Name;

    Account(std::string name, std::shared_ptr<Currency> currency) : PointerAttribute(std::move(currency)), Name(std::move(name)), _amount(0) {}
    virtual ~Account() = default;

    virtual Account* Clone() const = 0;

    virtual void Deposit(unsigned long long value);
    virtual void Withdraw(unsigned long long value);

    bool operator==(const Account& account) const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    unsigned long long _amount;
};