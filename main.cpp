#include "Headers/Bank.h"

int main()
{
    const auto achim_silvian = Person("Achim Silvian", 19);

    auto ing = Bank("ING", "INGBROBUXXX");

    auto silvian_account = BankAccount(achim_silvian);
    ing.AddBankAccount(silvian_account);

    const auto cont_economii = silvian_account.CreateNewAccount("Economii", Currency("US Dollar", '$'));
    const auto cont_curent = silvian_account.CreateNewAccount("Cont curent", Currency("Euro", 'e'));

    silvian_account.DepositToAnAccount(cont_curent, 1000);
    silvian_account.WithdrawFromAnAccount(cont_curent, 500);

    silvian_account.ChangeAccountName(cont_curent, "newAccount");
    silvian_account.DepositToAnAccount(cont_economii, 10000);
    silvian_account.DeleteAccount(cont_economii);

    const auto my_account = ing.GetAPersonsAccount(achim_silvian);

    ing.DeleteBankAccount(my_account);

    return 0;
}
