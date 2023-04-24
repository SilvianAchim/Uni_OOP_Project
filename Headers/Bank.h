#pragma once
#include <utility>
#include <vector>
#include "Error.h"

#include "BankAccount.h"

class Bank {
public:
    std::string Name;
    std::string SwiftCode;

    Bank(std::string name, std::string swiftCode) : Name(std::move(name)), SwiftCode(std::move(swiftCode)) {}

    void AddBankAccount(const BankAccount& bankAccount);
    void DeleteBankAccount(const BankAccount& bankAccount);
    BankAccount GetAPersonsAccount(const Person& person);

    friend std::ostream& operator<<(std::ostream& os, const Bank& bank);

private:
    std::vector<BankAccount> _bankAccounts;
};