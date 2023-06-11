#include "../Headers/StudentAccount.h"

std::shared_ptr<Account> StudentAccount::Clone() const {
    return std::make_shared<StudentAccount>(*this);
}

std::ostream &operator<<(std::ostream &os, const StudentAccount &studentAccount) {
    os << "Student Account, Name: " << studentAccount.Name << " Amount: " << studentAccount.Amount << std::endl;
    return os;
}

void StudentAccount::Deposit(unsigned long long int value) {
    Amount += value;
}

void StudentAccount::Withdraw(unsigned long long int value) {
    if (value >= Amount) {
        Amount -= value;
    }
}
