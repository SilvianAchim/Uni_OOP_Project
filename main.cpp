#include "Headers/Bank.h"
#include "Headers/BankAccount.h"
#include "Headers/Currency.h"
#include "Headers/Error.h"
#include "Headers/Person.h"

int main() {
    try {
        Person person("John Doe", 18);
        std::shared_ptr<Currency> currency = std::make_shared<Currency>("USD", '$');

        Bank bank("Bank of America", "BOFAUS3N");
        BankAccount bankAccount(person);
        bank.AddBankAccount(bankAccount);

        Account* savingsAccount = bankAccount.CreateNewAccount("John's Savings", currency, true);
        bankAccount.DepositToAnAccount(*savingsAccount, 1000);
        bankAccount.WithdrawFromAnAccount(*savingsAccount, 500);

        Account* checkingAccount = bankAccount.CreateNewAccount("John's Checking", currency, false);
        bankAccount.DepositToAnAccount(*checkingAccount, 2000);
        bankAccount.WithdrawFromAnAccount(*checkingAccount, 1000);

        BankAccount retrievedBankAccount = bank.GetAPersonsAccount(person);
        bankAccount.ChangeAccountName(*savingsAccount, "John's Updated Savings");
        bankAccount.DeleteAccount(*savingsAccount);

        bankAccount.WithdrawFromAnAccount(*checkingAccount, 5000);

        bank.DeleteBankAccount(bankAccount);
    } catch (const BankAccountError& e) {
        std::cerr << "BankAccountError: " << e.what() << std::endl;
    } catch (const BaseError& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}