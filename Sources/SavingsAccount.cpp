#include "../Headers/SavingsAccount.h"

void SavingsAccount::Deposit(unsigned long long value) {
    Amount += value;
}

void SavingsAccount::Withdraw(unsigned long long value) {
    if (value >= Amount) {
        Amount -= value;
    }
}