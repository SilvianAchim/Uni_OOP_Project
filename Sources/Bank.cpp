#include "../Headers/Bank.h"

void Bank::AddBankAccount(const BankAccount& bankAccount)
{
    _bankAccounts.push_back(bankAccount);
}

void Bank::DeleteBankAccount(const BankAccount& bankAccount)
{
    const auto bank_accounts_iterator = std::find(_bankAccounts.begin(), _bankAccounts.end(), bankAccount);
    if (bank_accounts_iterator != _bankAccounts.end())
    {
        _bankAccounts.erase(bank_accounts_iterator);
    }
}

BankAccount Bank::GetAPersonsAccount(Person person)
{
    const auto bank_accounts_iterator = std::find_if(_bankAccounts.begin(), _bankAccounts.end(), [&person](const BankAccount& bankAccount)
    {
        return Person(bankAccount.Owner) == person;
    });

    return *bank_accounts_iterator;
}

std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
    os << "Bank name: " << bank.Name << ", Swift Code: " << bank.SwiftCode << "\n";
    return os;
}
