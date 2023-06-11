#include "../Headers/AccountFactory.h"
#include "../Headers/SavingsAccount.h"
#include "../Headers/CheckingAccount.h"
#include "../Headers/StudentAccount.h"

std::shared_ptr<Account> AccountFactory::GetCheckingAccount(const Currency& currency) {
    return std::make_shared<CheckingAccount>("GetCheckingAccount", currency);
}

std::shared_ptr<Account> AccountFactory::GetSavingsAccount(const Currency& currency) {
    return std::make_shared<SavingsAccount>("GetCheckingAccount", currency);
}

std::shared_ptr<Account> AccountFactory::GetStudentAccount(const Currency &currency) {
    return std::make_shared<StudentAccount>("StudentAccount", currency);
}
