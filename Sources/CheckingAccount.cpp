#include "../Headers/CheckingAccount.h"

std::ostream &operator<<(std::ostream &os, const CheckingAccount &checkingAccount) {
    os << "Checking Account, Name: " << checkingAccount.Name << " Amount: " << checkingAccount.Amount << std::endl;
    return os;
}
