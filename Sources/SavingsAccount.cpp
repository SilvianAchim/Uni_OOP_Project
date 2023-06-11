#include "../Headers/SavingsAccount.h"

void SavingsAccount::Deposit(unsigned long long value) {
    Amount += value;
}

void SavingsAccount::Withdraw(unsigned long long value) {
    if (value >= Amount) {
        Amount -= value;
    }
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &savingsAccount) {
    os << "Savings Account, Name: " << savingsAccount.Name << " Amount: " << savingsAccount.Amount << std::endl;
    return os;
}

std::shared_ptr<Account> SavingsAccount::Clone() const {
    return std::make_shared<SavingsAccount>(*this);
}
