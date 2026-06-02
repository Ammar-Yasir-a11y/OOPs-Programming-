#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <iostream>

using namespace std;

class Passenger {
protected:
    string id;
    string name;
    string type; // "Economy", "Business", or "FirstClass"
public:
    Passenger(string id, string name, string type);
    virtual ~Passenger() {}

    string getId() const;
    string getName() const;
    string getType() const;

    // Pure virtual functions for polymorphism
    virtual double getBaggageAllowance() const = 0;
    virtual double getLoyaltyMultiplier() const = 0;
    virtual double getRefundPercentage() const = 0;
    
    virtual void display() const;
};

class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string id, string name);
    double getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
};

class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string id, string name);
    double getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
};

class FirstClassPassenger : public Passenger {
public:
    FirstClassPassenger(string id, string name);
    double getBaggageAllowance() const override;
    double getLoyaltyMultiplier() const override;
    double getRefundPercentage() const override;
};

#endif
