#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string name, const Currency& currency) : Account(std::move(name), std::move(currency)) {}
    std::shared_ptr<Account> Clone() const override;
    void Deposit(unsigned long long value) override;
    void Withdraw(unsigned long long value) override;

    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &checkingAccount);
};