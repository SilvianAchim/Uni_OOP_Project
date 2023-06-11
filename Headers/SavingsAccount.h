#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(std::string name, const Currency& currency) : Account(std::move(name), currency) {}
    std::shared_ptr<Account> Clone() const override;

    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &savingsAccount);

    void Deposit(unsigned long long value) override;
    void Withdraw(unsigned long long value) override;
};