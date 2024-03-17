#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>
#include <iostream>

class Card;
class Client;
class Account;


class Bank {
    private:
        std::string _name;
    public:
        Bank(std::string _name);
        std::string getBankName();
};


class Account {
    private:
        Bank &bank;
        Client &client;
        std::vector<Card*> My_cards;
        double amount;
    public:
        Account(Client&, double, Bank&);
        void add_amount(double);
        void remove_amount(double);
        void check_cash(Client&, double);
        void get_cash(double);
        void add_card(Card*);
        void display_details();
};


//class Advisor: public User {
//    private:
//        std::string _name;
//        Bank &bank;
//    public:
//        Advisor(std::string name, Bank& banque);
//};


class Client {
    private:
        //Advisor &advisor;
        std::string _name;
        double _cash;
    public:
        Client(std::string, double);
        std::string getName();
        double get_cash();
        void add_cash(double);
        void remove_cash(double);
};


class ATM {
    private:
        Bank &bank;
        double cash;
        //Location &location;

    public:
        explicit ATM(Bank&);
        void cash_refill(double);
        double check_cash();

};

class notEnoughCash : public std::exception {
public:
    virtual const char* what() const noexcept{
        return "Not enough cash";
    }
};

#endif // MODELS_H
