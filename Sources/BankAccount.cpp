#include "../Headers/BankAccount.h"
#include "../Headers/SavingsAccount.h"
#include "../Headers/CheckingAccount.h"

typename std::vector<std::shared_ptr<Account>>::iterator BankAccount::GetAccountIterator(const Account& account) {
    auto accounts_iterator = std::find_if(Accounts.begin(), Accounts.end(), [&account](const std::shared_ptr<Account>& accPtr) {
        return *accPtr == account;
    });
    return accounts_iterator;
}

Account* BankAccount::CreateNewAccount(const std::string& accountName, const std::shared_ptr<Currency>& currency, bool isSavings) {
    std::shared_ptr<Account> newAccount;
    if (isSavings) {
        newAccount = std::make_shared<SavingsAccount>(accountName, currency);
    } else {
        newAccount = std::make_shared<CheckingAccount>(accountName, currency);
    }
    Accounts.push_back(newAccount);
    return newAccount.get();
}

void BankAccount::DeleteAccount(const Account& account) {
    auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != Accounts.end()) {
        Accounts.erase(accounts_iterator);
    }
}

void BankAccount::ChangeAccountName(const Account& account, std::string newName) {
    auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != Accounts.end()) {
        (*accounts_iterator)->GetName() = std::move(newName);
    }
}

void BankAccount::DepositToAnAccount(const Account& account, const unsigned long long& amount) {
    auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != Accounts.end()) {
        (*accounts_iterator)->Deposit(amount);
    }
}

void BankAccount::WithdrawFromAnAccount(const Account& account, const unsigned long long& amount) {
    auto accounts_iterator = GetAccountIterator(account);
    if (accounts_iterator != Accounts.end()) {
        (*accounts_iterator)->Withdraw(amount);
    }
}

bool BankAccount::operator==(const BankAccount& bankAccount) const {
    return bankAccount.Owner == Owner;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount) {
    os << "Bank account owner: " << bankAccount.Owner.GetName() << "\n";
    return os;
}