#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(std::string name, std::shared_ptr<Currency> currency) : Account(std::move(name), std::move(currency)) {}
    SavingsAccount* Clone() const override {
        return new SavingsAccount(*this);
    }

    void Deposit(unsigned long long value) override;
    void Withdraw(unsigned long long value) override;
};