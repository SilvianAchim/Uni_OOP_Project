#include <memory>
#include "Headers/Bank.h"
#include "Headers/BankAccount.h"
#include "Headers/Currency.h"
#include "Headers/Error.h"
#include "Headers/Person.h"

int main() {
    try {
        Person person("John Doe", 18);
        std::shared_ptr<Currency> dollar = std::make_shared<Currency>("USD", '$');

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

    } catch (const AccountAlreadyExists& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const NonexistentAccount& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}