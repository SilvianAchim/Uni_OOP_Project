#include <utility>

#include "../Headers/BankAccount.h"

std::vector<Account>::iterator BankAccount::GetAccountIterator(const Account& account)
{
    auto accounts_iterator = std::find(_accounts.begin(), _accounts.end(), account);
    return accounts_iterator;
}

Account BankAccount::CreateNewAccount(const std::string& accountName, const Currency& currency)
{
    _accounts.emplace_back(accountName, currency);
    return *prev(_accounts.end());
}

std::vector<Account> BankAccount::GetAccounts()
{
    return _accounts;
}

void BankAccount::DepositToAnAccount(const Account& account, const unsigned long long& amount)
{
    const auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != _accounts.end())
    {
        accounts_iterator->Deposit(amount);
    }
}

void BankAccount::WithdrawFromAnAccount(const Account& account, const unsigned long long& amount)
{
    const auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != _accounts.end())
    {
        accounts_iterator->Withdraw(amount);
    }
}

bool BankAccount::operator==(const BankAccount& bankAccount) const
{
    return Person(bankAccount.Owner) == Owner;
}

void BankAccount::DeleteAccount(const Account& account)
{
    const auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != _accounts.end())
    {
        _accounts.erase(accounts_iterator);
    }
}

void BankAccount::ChangeAccountName(const Account& account, std::string newName)
{
    const auto accounts_iterator = GetAccountIterator(account);
    if(accounts_iterator != _accounts.end())
    {
        accounts_iterator->Name = std::move(newName);
    }
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount)
{
    os << "Owner's name: " << bankAccount.Owner.Name << "\n";
    return os;
}
