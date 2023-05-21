#pragma once
#include <utility>
#include <vector>
#include "Error.h"

#include "BankAccount.h"

class Bank {
public:
    Bank(std::string  name, std::string  swiftCode) : Name(std::move(name)), SwiftCode(std::move(swiftCode)) {}

    void AddBankAccount(const BankAccount& bankAccount);
    void RemoveBankAccount(BankAccount& bankAccount);

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank);

private:
    std::vector<BankAccount> BankAccounts;
    std::string Name;
    std::string SwiftCode;
};