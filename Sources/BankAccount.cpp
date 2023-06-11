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

    logger.LogSuccess("Deposited to " + account->GetName() + "  " + std::to_string(amount));
}

void BankAccount::Withdraw(const unsigned long long int &amount) {
    account->Withdraw(amount);
    logger.LogSuccess("Withdrew from " + account->GetName() + "  " + std::to_string(amount));
}

void BankAccount::ChangeAccountName(const std::string& newName) {
    if(account == nullptr){
        throw NonexistentAccount("Tried to change an nonexistent account's name!");
    }
    account->ChangeName(newName);
    logger.LogSuccess("Changed account name to " + newName);
}

void BankAccount::CreateAccount(AccountType accountType, const Currency &currency) {
    if (account != nullptr) {
        throw AccountAlreadyExists("Tried to create an account, even tho an account already exists!");
    }

    if (accountType == AccountType::CheckingAccount) {
        account = AccountFactory::GetCheckingAccount(currency);
    }
    if (accountType == AccountType::SavingsAccount) {
        account = AccountFactory::GetSavingsAccount(currency);
    }
}

void BankAccount::DeleteAccount() {
    account.reset();
    logger.LogInformation("Deleting bank account");
}

