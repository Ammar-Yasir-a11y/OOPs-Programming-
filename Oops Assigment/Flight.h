#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>

using namespace std;

class Flight {
protected:
    string flightNum;
    string origin;
    string destination;
    string dateTime; // Format: YYYY-MM-DD
    int totalSeats;
    int availableSeats;
    double revenue;
    string flightType; // "Domestic", "International", or "Charter"

public:
    Flight(string fn, string orig, string dest, string dt, int seats, string type);
    virtual ~Flight() {}

    string getFlightNum() const;
    string getOrigin() const;
    string getDestination() const;
    string getDateTime() const;
    int getAvailableSeats() const;
    int getTotalSeats() const;
    double getRevenue() const;
    string getFlightType() const;

    void bookSeat();
    void releaseSeat();
    void addRevenue(double amount);

    // Pure Virtual Functions
    virtual double calculateBaseFare() const = 0;
    virtual void displayDetails() const = 0;

    // Operator Overloading for display output streaming
    friend ostream& operator<<(ostream& os, const Flight& flight);
};

class DomesticFlight : public Flight {
public:
    DomesticFlight(string fn, string orig, string dest, string dt, int seats);
    double calculateBaseFare() const override;
    void displayDetails() const override;
};

class InternationalFlight : public Flight {
private:
    string visaRequirements;
public:
    InternationalFlight(string fn, string orig, string dest, string dt, int seats, string visa);
    string getVisaRequirements() const;
    double calculateBaseFare() const override;
    void displayDetails() const override;
};

class CharterFlight : public Flight {
private:
    string contractHolder;
public:
    CharterFlight(string fn, string orig, string dest, string dt, int seats, string holder);
    string getContractHolder() const;
    double calculateBaseFare() const override;
    void displayDetails() const override;
};

#endif
