#include "../Headers/Bank.h"

void Bank::AddBankAccount(const BankAccount& bankAccount) {
    BankAccounts.push_back(bankAccount);
}

void Bank::DeleteBankAccount(const BankAccount& bankAccount) {
    const auto bank_accounts_iterator = std::find(BankAccounts.begin(), BankAccounts.end(), bankAccount);
    if (bank_accounts_iterator != BankAccounts.end()) {
        BankAccounts.erase(bank_accounts_iterator);
    }
}

BankAccount Bank::GetAPersonsAccount(const Person& person) {
    const auto bank_accounts_iterator = std::find_if(BankAccounts.begin(), BankAccounts.end(), [&person](const BankAccount& bankAccount) {
        return bankAccount.Owner == person;
    });

    if (bank_accounts_iterator == BankAccounts.end()) {
        throw BankAccountError("Bank account not found for the given person");
    }

    return *bank_accounts_iterator;
}

std::ostream& operator<<(std::ostream& os, const Bank& bank) {
    os << "Bank name: " << bank.Name << ", Swift Code: " << bank.SwiftCode << "\n";
    return os;
}