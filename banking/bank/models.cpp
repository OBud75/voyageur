#include "models.h"

using namespace std;

Bank::Bank(std::string name){
    std::cout << "Create Bank: " << name << std::endl;
    _name = name;
};

std::string Bank::getBankName(){
    return _name;
}

//Advisor::Advisor(std::string name, Bank &banque){
//    &bank = &banque;
//    _name = name;
//};

Account::Account(Client& _client, double _amount, Bank& _bank) : bank(_bank), client(_client){
    //std::cout << "New account for bank " << _bank.getBankName() << " for client " << _client.getName() << " Balance (" << _amount << ")" << std::endl;
    amount = _amount;
    client.remove_cash(_amount);
}

void Account::add_amount(double _amount){
    amount += _amount;
    //std::cout << "Your account balance is : " << amount << std::endl;
}

void Account::add_card(Card* card){
    My_cards.push_back(card);
}

void Account::get_cash(double amount_requested){
    amount -= amount_requested;
    client.add_cash(amount_requested);
}

void Account::display_details(){
    std::cout << "Account in bank " << bank.getBankName() << std::endl;
    std::cout << "Client name is " << client.getName() << std::endl;
    std::cout << "Account balance is " << amount << " euros." << std::endl;

    //std::cout << "Account in bank " << _bank.getBankName() << std::endl;
    }

//class Advisor: public User {
//    private:
//        Bank &bank;
//};

Client::Client(std::string name, double cash){
    _name = name;
    _cash = cash;
}

std::string Client::getName(){
    return _name;
}

void Client::add_cash(double amount){
    _cash += amount;
    std::cout << _name << " has " << _cash << " in cash." << std::endl;
}

void Client::remove_cash(double amount){
    _cash -= amount;
    std::cout << _name << " has " << _cash << " in cash." << std::endl;
}

//class ATM {
//    private:
//        Bank &bank;
//        Location &location;
//
//    public:
//        explicit ATM();
//
//};

