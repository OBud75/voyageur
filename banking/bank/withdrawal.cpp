#include "withdrawal.h"

Card::Card(Account &_account, int card_number) : account(_account), _card_number(card_number){
    _account.add_card(this);
}

Account &Card::get_account(){
    return account;
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

int PlatiniumCard::max_withdrawal() const{
    return 2500;
}

int PlatiniumCard::max_credit() const{
    return 1000;
}

