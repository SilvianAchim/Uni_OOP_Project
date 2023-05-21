#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(std::string name, std::shared_ptr<Currency> currency) : Account(std::move(name), std::move(currency)) {}
    CheckingAccount* Clone() const override {
        return new CheckingAccount(*this);
    }

    void Deposit(unsigned long long value) override;
    void Withdraw(unsigned long long value) override;

    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &checkingAccount);
};