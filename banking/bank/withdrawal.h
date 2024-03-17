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

template<typename Card>
Withdrawal<Card>::Withdrawal(Card &card) : creditcard(card) {
}

template<typename Card>
int Withdrawal<Card>::operator()(int amount) {
    if (amount <= creditcard.max_withdrawal()){
        creditcard.get_account().remove_amount(amount);
        return amount;
    }
    else {
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        std::cout << "Amount exceeds the authorized withdrawal" << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        return -1;
    }
};

template<typename Card>
int Withdrawal<Card>::operator()(int amount, ATM& currentATM) {
    if (amount <= creditcard.max_withdrawal()){
        if (currentATM.check_cash() >= amount){
            creditcard.get_account().remove_amount(amount);
            return amount;
        }
        else{
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
            std::cout << "This ATM is currently out of order !" << std::endl;
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
            return -1;
        }
    }
    else {
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        std::cout << "Amount exceeds the authorized withdrawal" << std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        return -1;
    }
}

#endif // WITHDRAWAL_H
