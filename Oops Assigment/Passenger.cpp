#include "Passenger.h"

using namespace std;

Passenger::Passenger(string id, string name, string type) : id(id), name(name), type(type) {}
string Passenger::getId() const { return id; }
string Passenger::getName() const { return name; }
string Passenger::getType() const { return type; }

void Passenger::display() const {
    cout << "ID: " << id << " | Name: " << name << " | Class: " << type;
}

// Economy Class Implementation
EconomyPassenger::EconomyPassenger(string id, string name) : Passenger(id, name, "Economy") {}
double EconomyPassenger::getBaggageAllowance() const { return 20.0; } // 20 kg limit
double EconomyPassenger::getLoyaltyMultiplier() const { return 1.0; }
double EconomyPassenger::getRefundPercentage() const { return 50.0; } // 50% base refund

// Business Class Implementation
BusinessPassenger::BusinessPassenger(string id, string name) : Passenger(id, name, "Business") {}
double BusinessPassenger::getBaggageAllowance() const { return 40.0; } // 40 kg limit
double BusinessPassenger::getLoyaltyMultiplier() const { return 1.5; }
double BusinessPassenger::getRefundPercentage() const { return 75.0; } // 75% base refund

// First Class Implementation
FirstClassPassenger::FirstClassPassenger(string id, string name) : Passenger(id, name, "FirstClass") {}
double FirstClassPassenger::getBaggageAllowance() const { return 50.0; } // 50 kg limit
double FirstClassPassenger::getLoyaltyMultiplier() const { return 2.0; }
double FirstClassPassenger::getRefundPercentage() const { return 90.0; } // 90% base refund
