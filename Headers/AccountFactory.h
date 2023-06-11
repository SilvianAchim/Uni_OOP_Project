#ifndef OOP_ACCOUNTFACTORY_H
#define OOP_ACCOUNTFACTORY_H
#include "Account.h"

class AccountFactory {
public:
     static std::shared_ptr<Account> GetCheckingAccount(const Currency& currency);
     static std::shared_ptr<Account> GetSavingsAccount(const Currency& currency);
     static std::shared_ptr<Account> GetStudentAccount(const Currency& currency);
};


#endif //OOP_ACCOUNTFACTORY_H
