#include "Airline.h"
#include "SearchUtility.h"
#include "Exceptions.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

// C++98 compatible Functor for removeFlight
struct FlightNumberMatcher {
    string targetNum;
    FlightNumberMatcher(const string& num) : targetNum(num) {}
    bool operator()(Flight* f) const {
        if (f->getFlightNum() == targetNum) {
            delete f;
            return true;
        }
        return false;
    }
};

// C++98 compatible Functors for bookTicket and loadFromFile
struct FlightNumFinder {
    string targetNum;
    FlightNumFinder(const string& num) : targetNum(num) {}
    bool operator()(Flight* fl) const {
        return fl->getFlightNum() == targetNum;
    }
};

struct TicketFinder {
    string targetId;
    TicketFinder(const string& id) : targetId(id) {}
    bool operator()(Ticket* tk) const {
        return tk->getTicketId() == targetId;
    }
};

// C++98 compatible Functor for sorting revenue
struct RevenueComparator {
    bool operator()(Flight* a, Flight* b) const {
        return a->getRevenue() > b->getRevenue();
    }
};


Airline::Airline() {}
Airline::~Airline() { clearData(); }

void Airline::clearData() {
    for (size_t i = 0; i < flights.size(); i++) delete flights[i];
    
    // C++98 iterator loop for map
    for (map<string, Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        delete it->second;
    }
    
    for (size_t i = 0; i < tickets.size(); i++) delete tickets[i];
    
    flights.clear(); 
    passengers.clear(); 
    tickets.clear();
}

void Airline::addFlight(Flight* f) { flights.push_back(f); }

void Airline::removeFlight(string flightNum) {
    // Lambda ki jagah custom functor use kiya hai
    vector<Flight*>::iterator it = remove_if(flights.begin(), flights.end(), FlightNumberMatcher(flightNum));
    flights.erase(it, flights.end());
}

void Airline::listFlights() const {
    if (flights.empty()) { cout << "No flights available right now.\n"; return; }
    for (size_t i = 0; i < flights.size(); i++) { cout << *(flights[i]) << "\n"; }
}

void Airline::searchFlights(string query, int choice) {
    bool found = false;
    for (size_t i = 0; i < flights.size(); i++) {
        Flight* f = flights[i];
        if ((choice == 1 && f->getFlightNum() == query) ||
            (choice == 2 && (f->getOrigin() == query || f->getDestination() == query)) ||
            (choice == 3 && f->getDateTime() == query)) {
            cout << *f << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching records found for search string.\n";
}

void Airline::registerPassenger(Passenger* p) { 
    passengers[p->getId()] = p; 
}

void Airline::removePassenger(string pId) {
    map<string, Passenger*>::iterator it = passengers.find(pId);
    if (it != passengers.end()) {
        delete it->second;
        passengers.erase(it);
    }
}

void Airline::viewPassengerHistory(string pId) const {
    map<string, Passenger*>::const_iterator it = passengers.find(pId);
    if (it == passengers.end()) {
        cout << "Passenger record does not exist.\n";
        return;
    }
    cout << "--- Activity History For: " << it->second->getName() << " ---\n";
    bool tracked = false;
    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets[i]->getPassengerId() == pId) {
            cout << *(tickets[i]) << "\n";
            tracked = true;
        }
    }
    if (!tracked) cout << "No historical tickets logged for this passenger.\n";
}

void Airline::bookTicket(string pId, string flightNum, string seatNum) {
    map<string, Passenger*>::iterator pIt = passengers.find(pId);
    Flight* f = findItem(flights, FlightNumFinder(flightNum));

    if (pIt == passengers.end() || !f) {
        cout << "Error: Passenger ID or Flight profile code not recognized.\n";
        return;
    }

    if (f->getAvailableSeats() <= 0) {
        throw FlightFullException("Booking Blocked: Flight " + flightNum + " is completely full!");
    }

    // Check for existing booking on same flight
    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets[i]->getPassengerId() == pId && tickets[i]->getFlightNum() == flightNum && tickets[i]->getStatus() == "Booked") {
            cout << "Warning: Duplicate Booking. Passenger already holds an active seat on this flight.\n";
            return;
        }
    }

    f->bookSeat();
    double computedFare = f->calculateBaseFare();
    
    // C++98 compatible string conversion
    int tIdNum = tickets.size() + 2001;
    char buffer[50];
    sprintf(buffer, "TX-%d", tIdNum);
    string generatedTId(buffer);

    Ticket* newTicket = new Ticket(generatedTId, pId, flightNum, seatNum, computedFare);
    tickets.push_back(newTicket);
    f->addRevenue(computedFare);

    cout << "Booking successful! Ticket generated Details:\n" << *newTicket << "\n";
}

void Airline::cancelTicket(string tId, int daysBeforeDeparture) {
    Ticket* t = findItem(tickets, TicketFinder(tId));

    if (!t || t->getStatus() == "Cancelled") {
        throw InvalidCancellationException("Cancellation Error: Ticket tracking matching token invalid or already cancelled.");
    }

    Flight* f = findItem(flights, FlightNumFinder(t->getFlightNum()));
    map<string, Passenger*>::iterator pIt = passengers.find(t->getPassengerId());

    if (daysBeforeDeparture <= 0) {
        throw InvalidCancellationException("Cancellation Error: Cannot cancel on or after the day of departure.");
    }

    t->cancelTicket();
    if (f) f->releaseSeat();

    double baseRefundRate = (pIt != passengers.end()) ? pIt->second->getRefundPercentage() : 50.0;
    if (daysBeforeDeparture < 3) baseRefundRate -= 25.0; 
    if (baseRefundRate < 0) baseRefundRate = 0;

    double cashRefund = t->getFarePaid() * (baseRefundRate / 100.0);
    cout << "Ticket Cancelled. Refund disbursed: " << cashRefund << " PKR (" << baseRefundRate << "% Allowed).\n";
}

void Airline::generateReports(string todayDate) const {
    cout << "\n======================================================\n";
    cout << "           SYSTEM PERFORMANCE METRIC REPORTS          \n";
    cout << "======================================================\n";
    
    cout << "\n1. DEPARTURES FOR TARGET DATE (" << todayDate << "):\n";
    for (size_t i = 0; i < flights.size(); i++) {
        if (flights[i]->getDateTime() == todayDate) cout << *(flights[i]) << "\n";
    }

    cout << "\n2. CAPACITY OCCUPANCY RATIO PER FLIGHT:\n";
    for (size_t i = 0; i < flights.size(); i++) {
        Flight* f = flights[i];
        double occupancy = ((double)(f->getTotalSeats() - f->getAvailableSeats()) / f->getTotalSeats()) * 100.0;
        cout << "Flight " << f->getFlightNum() << " -> Utilization Rate: " << occupancy << "%\n";
    }

    cout << "\n3. TOP HIGHEST REVENUE RUNNING FLIGHTS:\n";
    vector<Flight*> rankingFlights = flights;
    
    // Sort meeting C++98 standard using functor
    sort(rankingFlights.begin(), rankingFlights.end(), RevenueComparator());

    int displayLimit = min((int)rankingFlights.size(), 5);
    for (int i = 0; i < displayLimit; i++) {
        cout << i + 1 << ". Flight: " << rankingFlights[i]->getFlightNum() 
             << " | Accumulated Value: " << rankingFlights[i]->getRevenue() << " PKR\n";
    }
}

void Airline::saveToFile(string filename) const {
    ofstream out(filename.c_str()); // .c_str() for C++98 fstream compatibility
    if (!out) return;

    out << flights.size() << "\n";
    for (size_t i = 0; i < flights.size(); i++) {
        Flight* f = flights[i];
        out << f->getFlightType() << "," << f->getFlightNum() << "," << f->getOrigin() << "," 
            << f->getDestination() << "," << f->getDateTime() << "," << f->getTotalSeats() << "\n";
    }

    out << passengers.size() << "\n";
    for (map<string, Passenger*>::const_iterator it = passengers.begin(); it != passengers.end(); ++it) {
        Passenger* p = it->second;
        out << p->getType() << "," << p->getId() << "," << p->getName() << "\n";
    }

    out << tickets.size() << "\n";
    for (size_t i = 0; i < tickets.size(); i++) {
        Ticket* t = tickets[i];
        out << t->getTicketId() << "," << t->getPassengerId() << "," << t->getFlightNum() << "," 
            << t->getSeatNumber() << "," << t->getFarePaid() << "," << t->getStatus() << "\n";
    }
    out.close();
}

void Airline::loadFromFile(string filename) {
    ifstream in(filename.c_str()); // .c_str() for C++98 fstream compatibility
    if (!in) return;

    clearData();
    int sizeCount;
    
    if (!(in >> sizeCount)) return;
    in.ignore();
    for (int i = 0; i < sizeCount; i++) {
        string type, fn, orig, dest, dt;
        int seats;
        getline(in, type, ',');
        getline(in, fn, ',');
        getline(in, orig, ',');
        getline(in, dest, ',');
        getline(in, dt, ',');
        in >> seats; in.ignore();

        if (type == "Domestic") flights.push_back(new DomesticFlight(fn, orig, dest, dt, seats));
        else if (type == "International") flights.push_back(new InternationalFlight(fn, orig, dest, dt, seats, "Visa Verification OK"));
        else if (type == "Charter") flights.push_back(new CharterFlight(fn, orig, dest, dt, seats, "Corporate Agreement"));
    }

    if (!(in >> sizeCount)) return;
    in.ignore();
    for (int i = 0; i < sizeCount; i++) {
        string type, id, name;
        getline(in, type, ',');
        getline(in, id, ',');
        getline(in, name);

        if (type == "Economy") passengers[id] = new EconomyPassenger(id, name);
        else if (type == "Business") passengers[id] = new BusinessPassenger(id, name);
        else if (type == "FirstClass") passengers[id] = new FirstClassPassenger(id, name);
    }

    if (!(in >> sizeCount)) return;
    in.ignore();
    for (int i = 0; i < sizeCount; i++) {
        string tId, pId, fNum, seat, status;
        double fare;
        getline(in, tId, ',');
        getline(in, pId, ',');
        getline(in, fNum, ',');
        getline(in, seat, ',');
        in >> fare; in.ignore();
        getline(in, status);

        Ticket* t = new Ticket(tId, pId, fNum, seat, fare, status);
        tickets.push_back(t);

        if (status == "Booked") {
            Flight* f = findItem(flights, FlightNumFinder(fNum));
            if (f) { f->bookSeat(); f->addRevenue(fare); }
        }
    }
    in.close();
}
