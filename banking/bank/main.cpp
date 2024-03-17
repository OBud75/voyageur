#include <iostream>

#include "models.h"
#include "withdrawal.h"

using namespace std;

int main()
{
    Bank creditDuNord("Credit du Nord");
    Bank creditDuSud("Credit du Sud");
    creditDuNord.getBankName();
    creditDuSud.getBankName();

//    Class *ATMNord = new ATM(creditDuNord);
//    Class *ATMSud = new ATM(creditDuSud);

    Client bob("Bob", 5000);

    Account bob_account(bob, 100, creditDuNord);
    bob_account.add_amount(500);


    GoldCard bob_gold(123456);
    Card* ptr_gold = &bob_gold;
    bob_account.add_card(ptr_gold);
    //    bob_card1.add_amount(100);
    BlackCard bob_black(444333);
    Card* ptr_black = &bob_black;
    bob_account.add_card(ptr_black);
//    bob_card2.add_amount(200);
    bob_account.display_details();

    Withdrawal<Card> bob_withdraw1(*ptr_gold);
    Withdrawal<Card> bob_withdraw2(*ptr_black);

    bob_account.get_cash(50)

    bob_withdraw1(50);
    bob_withdraw2(1001);

    bob_account.display_details();
//
//    Client alice("alice", 100);
//
//    Account alice_account(alice, 150, creditDuSud); //Fail
//    alice_account(alice, 100, CreditDuSud);
//
//    PlatinumCard alice_card(123564);
//    alice_card->add_amount(150); //Fail
//    alice_card->add_amount(100);
//
//    alice_account->display_details();
//
//    Withdrawal<Card> alice_withdraw(alice_card);
//
//    alice_withdraw(50, ATMNord); // Fail
//    alice_withdraw(50);
//    alice_withdraw(50, ATMSud);
//    alice_withdraw(50); //Fail
//
//    alice_account->display_details();

    return 0;
}

.//ToDO crer une fonction pour retirer des sous
