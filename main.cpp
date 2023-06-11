#include <memory>
#include "Headers/Bank.h"
#include "Headers/BankAccount.h"
#include "Headers/Currency.h"
#include "Headers/Error.h"
#include "Headers/Person.h"
#include "Headers/Dollar.h"
#include "Headers/SavingsAccount.h"
#include "Headers/CheckingAccount.h"
#include "Headers/Logger.h"

int main() {
    Logger<void> logger{};

    try {
        Person person("John Doe", 18);
        auto& dollar = Dollar::GetDollar();

        Bank bank("Bank of America", "BOFAUS3N");

        BankAccount bankAccount(person);
        bank.AddBankAccount(bankAccount);

        bankAccount.CreateAccount(AccountType::SavingsAccount, dollar);
        bankAccount.Deposit(1000);
        bankAccount.Withdraw(500);
        bankAccount.ChangeAccountName("Main Savings");

        //bankAccount.CreateAccount(AccountType::CheckingAccount, dollar); // Uncomment for Exception

        std::cout<< bankAccount;

        BankAccount checkingBankAccount(person);
        bank.AddBankAccount(checkingBankAccount);
        checkingBankAccount.CreateAccount(AccountType::CheckingAccount, dollar);
        checkingBankAccount.Deposit(2000);
        checkingBankAccount.Withdraw(100);

        bank.RemoveBankAccount(bankAccount);

        //bankAccount.ChangeAccountName("New Main Savings"); // Uncomment for Exception

        bankAccount.CreateAccount(AccountType::CheckingAccount, dollar);
        std::cout<<bankAccount;

        //Dynamic_cast example:
        std::cout<<"Dynamic Cast: \n";
        auto* baseCurrency = new Currency("Dollar", '$');
        std::cout<< *baseCurrency;
        auto* dollarCurrency = dynamic_cast<Dollar*>(baseCurrency);
        std::cout << dollarCurrency->GetEuroConversionRate() << std::endl;

        delete dollarCurrency;
        delete baseCurrency;

    } catch (const AccountAlreadyExists& e) {
        logger.LogError(e.what());
    } catch (const NonexistentAccount& e) {
        logger.LogError(e.what());
    }

    return 0;
}