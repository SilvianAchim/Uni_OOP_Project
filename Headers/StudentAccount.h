#ifndef OOP_STUDENTACCOUNT_H
#define OOP_STUDENTACCOUNT_H


#include "Account.h"

class StudentAccount : public Account {
public:
    StudentAccount(std::string name, const Currency& currency) : Account(std::move(name), currency) {}
    std::shared_ptr<Account> Clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const StudentAccount &studentAccount);

    void Deposit(unsigned long long value) override;
    void Withdraw(unsigned long long value) override;
};


#endif //OOP_STUDENTACCOUNT_H
