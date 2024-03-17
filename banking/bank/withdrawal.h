#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>
#include "models.h"

class Account;
class ATM;

class Card {
    private:
        Account &account;
        int _card_number;
        int _current_credit;
    public:
        Card(Account&, int);
        virtual int max_withdrawal() const = 0;
        virtual int max_credit() const = 0;
        Account &get_account();
};

class GoldCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        GoldCard(Account &_account, int card_number) : Card(_account, card_number){};
};

class PlatiniumCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        PlatiniumCard(Account &_account, int card_number) : Card(_account, card_number){};
};

class BlackCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        BlackCard(Account &_account, int card_number) : Card(_account, card_number){};
};

template<typename Card>
class Withdrawal {
    // "retirer de l'argent" n'a pas à changer si
    // les règles spécifiques à une carte changent.
    private:
        Card &creditcard;

    public:
        Withdrawal(Card &);
        int operator()(int);
        int operator()(int, ATM&);
};

#include "withdrawal.tpp"

#endif // WITHDRAWAL_H
