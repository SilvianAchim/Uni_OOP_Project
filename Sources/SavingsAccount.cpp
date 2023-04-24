#include "../Headers/SavingsAccount.h"

void SavingsAccount::Deposit(unsigned long long value) {
    _amount += value;
}

void SavingsAccount::Withdraw(unsigned long long value) {
    if (value >= _amount) {
        _amount -= value;
    }
}