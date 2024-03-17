#ifndef WITHDRAWAL_TPP
#define WITHDRAWAL_TPP

#include "withdrawal.h"


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

#endif // WITHDRAWAL_TPP
