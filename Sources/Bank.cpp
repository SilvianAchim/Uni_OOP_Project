#include "../Headers/Bank.h"

void Bank::AddBankAccount(const BankAccount& bankAccount) {
    BankAccounts.push_back(bankAccount);
}

void Bank::RemoveBankAccount(BankAccount& bankAccount) {
    const auto bank_accounts_iterator = std::find(BankAccounts.begin(), BankAccounts.end(), bankAccount);
    if (bank_accounts_iterator != BankAccounts.end()) {
        BankAccounts.erase(bank_accounts_iterator);
        bankAccount.DeleteAccount();
    }
}

std::ostream& operator<<(std::ostream& os, const Bank& bank) {
    os << "Bank name: " << bank.Name << ", Swift Code: " << bank.SwiftCode << "\n";
    return os;
}