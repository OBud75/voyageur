#include <iostream>

#include "models.h"
#include "withdrawal.h"

using namespace std;

int main()
{
    Bank creditDuNord("Credit du Nord");
    Bank creditDuSud("Credit du Sud");

    ATM ATMNord(creditDuNord);
    ATM ATMSud(creditDuSud);

    Client bob("Bob", 5000);

    Account bob_account(bob, 100, creditDuNord);
    bob_account.add_amount(500);

    GoldCard bob_gold(bob_account, 123456);
    BlackCard bob_black(bob_account, 444333);

    bob_account.display_details();

    Withdrawal bob_withdraw1(*&bob_gold);
    Withdrawal bob_withdraw2(*&bob_black);

    bob_withdraw1(50);
    bob_withdraw2(1001);

    bob_account.display_details();

    //test avec une autre cliente

    Client alice("alice", 200);

    Account alice_account(alice, 250, creditDuSud); //Fail
    Account alice_account2(alice, 100, creditDuSud);

    PlatiniumCard alice_card(alice_account2, 123564);
    alice_account2.add_amount(150); //Fail
    alice_account2.add_amount(100);

    alice_account2.display_details();

    Withdrawal<Card> alice_withdraw(*&alice_card);

    alice_withdraw(50, ATMNord); // Fail
    alice_withdraw(50);
    ATMSud.cash_refill(10000);
    alice_withdraw(50, ATMSud);

    alice_account2.display_details();

    return 0;
}

