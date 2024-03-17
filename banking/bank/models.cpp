#include "models.h"

using namespace std;

Bank::Bank(std::string name){
    std::cout << "Create Bank: " << name << std::endl;
    _name = name;
};

std::string Bank::getBankName(){
    return _name;
}


Account::Account(Client& _client, double _amount, Bank& _bank) : bank(_bank), client(_client){
    try {
        check_cash(_client, _amount);
        std::cout << "New account for bank " << _bank.getBankName() << " for client " << _client.getName() << " Balance (" << _amount << ")" << std::endl;
        amount = _amount;
        client.remove_cash(_amount);
    } catch (const notEnoughCash& e){
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        std::cout << "Not enough cash, try again when you're richer. " <<std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
    }

}

void Account::check_cash(Client& _client, double _amount){
    if (client.get_cash() < _amount){
        throw notEnoughCash();
    }
}

void Account::add_amount(double _amount){
    try {
        check_cash(client, _amount);
        amount += _amount;
        client.remove_cash(_amount);
        std::cout << "Your account balance is : " << amount << std::endl;
    } catch (const notEnoughCash& e){
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
        std::cout << "Not enough cash, go ask for a raise ! " <<std::endl;
        std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<  std::endl;
    }
}

void Account::remove_amount(double _amount){
    amount -= _amount;
    client.add_cash(_amount);
    std::cout << "Your account balance is : " << amount << std::endl;
}

void Account::add_card(Card *card){
    My_cards.push_back(card);
}

void Account::display_details(){
    std::cout << "===================================" <<  std::endl;
    std::cout << "  Account in bank " << bank.getBankName() << std::endl;
    std::cout << "  Client name is " << client.getName() << std::endl;
    std::cout << "  Account balance is " << this->amount << " euros." << std::endl;
    std::cout << "  Client has " << client.get_cash() << " euros in cash." << std::endl;
    std::cout << "===================================" <<  std::endl;
    }

//class Advisor: public User {
//    private:
//        Bank &bank;
//};

Client::Client(std::string name, double cash){
    std::cout << "Create Client: " << name << " (" << cash << ")" << std::endl;
    _name = name;
    _cash = cash;
}

std::string Client::getName(){
    return _name;
}

double Client::get_cash(){
    return _cash;
}

void Client::add_cash(double amount){
    _cash += amount;
    std::cout << _name << " has " << _cash << " in cash." << std::endl;
}

void Client::remove_cash(double amount){
    _cash -= amount;
    std::cout << _name << " has " << _cash << " in cash." << std::endl;
}


ATM::ATM(Bank& bank) : bank(bank){
    cash = 0;
}

void ATM::cash_refill(double amount){
    cash += amount;
}

double ATM::check_cash(){
    return cash;
}


