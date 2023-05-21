#pragma once
#include <string>
#include <utility>
#include <iostream>

#include "Currency.h"
#include "SharedPtrManager.h"

class Account : public SharedPtrManager<Currency> {
public:
    Account(std::string name, std::shared_ptr<Currency> currency) : SharedPtrManager(std::move(currency)), Name(std::move(name)), Amount(0) {}
    virtual ~Account() = default;

    virtual Account* Clone() const = 0;

    virtual void Deposit(unsigned long long value) = 0;
    virtual void Withdraw(unsigned long long value) = 0;
    std::string GetName();
    bool operator==(const Account& account) const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account);

protected:
    std::string Name;
    unsigned long long Amount;
};