#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <iostream>

class Card {
    private:
        int _card_number;
    public:
        virtual int max_withdrawal() const = 0;
        virtual int max_credit() const = 0;
        Card(int);
};

class GoldCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        GoldCard(int card_number) : Card(card_number){};
};

class PlatiniumCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        PlatiniumCard(int card_number) : Card(card_number){};
};

class BlackCard : public Card {
    public:
        int max_withdrawal() const override;
        int max_credit() const override;
        BlackCard(int card_number) : Card(card_number){};
};



template<typename Card>
class Withdrawal {
    // "retirer de l'argent" n'a pas à changer si
    // les règles spécifiques à une carte changent.
    private:
        Card &creditcard;

    public:
        Withdrawal(Card &card);
        int operator()(int amount);
};

template<typename Card>
Withdrawal<Card>::Withdrawal(Card &card) : creditcard(card) {
}

template<typename Card>
int Withdrawal<Card>::operator()(int amount) {
    if (amount <= creditcard.max_withdrawal()){
        return amount;
    }
    else {
        std::cout << "Amount exceeds the authorized withdrawal" << std::endl;
        return -1;
    }
}


#endif // WITHDRAWAL_H
