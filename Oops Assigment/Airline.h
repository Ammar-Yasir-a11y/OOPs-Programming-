#ifndef AIRLINE_H
#define AIRLINE_H

#include <vector>
#include <map>
#include <string>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"

using namespace std;

class Airline {
private:
    vector<Flight*> flights;
    map<string, Passenger*> passengers; // Satisfies the std::map requirement
    vector<Ticket*> tickets;

    void clearData();

public:
    Airline();
    ~Airline();

    // Flight management
    void addFlight(Flight* f);
    void removeFlight(string flightNum);
    void searchFlights(string query, int choice);
    void listFlights() const;

    // Passenger management
    void registerPassenger(Passenger* p);
    void removePassenger(string pId);
    void viewPassengerHistory(string pId) const;

    // Core transaction booking mechanics
    void bookTicket(string pId, string flightNum, string seatNum);
    void cancelTicket(string tId, int daysBeforeDeparture);

    // Summary calculation reports
    void generateReports(string todayDate) const;

    // Persistence file storage handlers
    void saveToFile(string filename) const;
    void loadFromFile(string filename);
};

#endif
