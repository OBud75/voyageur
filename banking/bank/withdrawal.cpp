#include "withdrawal.h"
#include <iostream>

Card::Card(int card_number) : _card_number(card_number){

}


int GoldCard::max_withdrawal() const{
    return 500;
}

int GoldCard::max_credit() const{
    return 100;
}

int BlackCard::max_withdrawal() const{
    return 1000;
}

int BlackCard::max_credit() const{
    return 500;
}

//
//class PlatiniumCard : public Card {
//    public:
//        int max_withdrawal() const override;
//        int max_credit() const override;
//};

//
//template<typename Card>
//Withdrawal<Card>::Withdrawal(Card &card) : creditcard(card) {
//}
//
//template<typename Card>
//int Withdrawal<Card>::operator()(int amount) {
//    if (amount <= creditcard.max_withdrawal()){
//        return amount;
//    }
//    else {
//        std::cout << "Amount exceeds the authorized withdrawal" << std::endl;
//        return -1;
//    }
//}
