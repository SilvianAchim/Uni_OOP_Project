#include "../Headers/BankAccount.h"
#include "../Headers/SavingsAccount.h"
#include "../Headers/CheckingAccount.h"
#include "../Headers/Error.h"


bool BankAccount::operator==(const BankAccount& bankAccount) const {
    return bankAccount.Owner == Owner;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount) {
    os << "Bank account owner: " << bankAccount.Owner.GetName() << " Bank Account name: "
    << bankAccount.account->GetName() << "\n";
    return os;
}

void BankAccount::Deposit(const unsigned long long int &amount) {
    account->Deposit(amount);
}

void BankAccount::Withdraw(const unsigned long long int &amount) {
    account->Withdraw(amount);
}

void BankAccount::ChangeAccountName(const std::string& newName) {
    if(account == nullptr){
        throw NonexistentAccount("Tried to change an nonexistent account's name!");
    }
    account->ChangeName(newName);
}

void BankAccount::CreateAccount(AccountType accountType, const std::shared_ptr<Currency> &currency) {
    if(account.get() != nullptr ){
        throw AccountAlreadyExists("Tried to create an account, even tho an account already exists!");
    }

    if(accountType == AccountType::CheckingAccount){
        account = std::make_shared<CheckingAccount>("CheckingAccount", currency);
    }
    if(accountType == AccountType::SavingsAccount){
        account = std::make_shared<SavingsAccount>("SavingsAccount", currency);
    }
}

void BankAccount::DeleteAccount() {
    account.reset();
}

