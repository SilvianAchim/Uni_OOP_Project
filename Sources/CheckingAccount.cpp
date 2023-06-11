#include "../Headers/CheckingAccount.h"

std::ostream &operator<<(std::ostream &os, const CheckingAccount &checkingAccount) {
    os << "Checking Account, Name: " << checkingAccount.Name << " Amount: " << checkingAccount.Amount << std::endl;
    return os;
}

void CheckingAccount::Deposit(unsigned long long int value) {
    Amount += value;
}

void CheckingAccount::Withdraw(unsigned long long int value) {
    if (value >= Amount) {
        Amount -= value;
    }
}

std::shared_ptr<Account> CheckingAccount::Clone() const {
    return std::make_shared<CheckingAccount>(*this);
}
