#include "../Headers/Account.h"

bool Account::operator==(const Account& account) const {
    return account.Name == Name;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account name: " << account.Name << " Account ammount: " << account.Amount << "\n";
    return os;
}

void Account::ChangeName(const std::string& newName) {
    Name = newName;
}

std::string Account::GetName() {
    return Name;
}
