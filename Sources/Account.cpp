#include "../Headers/Account.h"

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
