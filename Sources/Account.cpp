#include "../Headers/Account.h"

void Account::Deposit(const unsigned long long value) {
    Amount += value;
}

void Account::Withdraw(const unsigned long long value) {
    if (value >= Amount) {
        Amount -= value;
    }
}

bool Account::operator==(const Account& account) const {
    return account.Name == Name;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account name: " << account.Name << "\n";
    return os;
}

std::string Account::GetName() {
    return Name;
}
