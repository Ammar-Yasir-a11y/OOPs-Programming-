#include "Flight.h"

using namespace std;

Flight::Flight(string fn, string orig, string dest, string dt, int seats, string type)
    : flightNum(fn), origin(orig), destination(dest), dateTime(dt), totalSeats(seats), availableSeats(seats), revenue(0.0), flightType(type) {}

string Flight::getFlightNum() const { return flightNum; }
string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
string Flight::getDateTime() const { return dateTime; }
int Flight::getAvailableSeats() const { return availableSeats; }
int Flight::getTotalSeats() const { return totalSeats; }
double Flight::getRevenue() const { return revenue; }
string Flight::getFlightType() const { return flightType; }

void Flight::bookSeat() { if (availableSeats > 0) availableSeats--; }
void Flight::releaseSeat() { if (availableSeats < totalSeats) availableSeats++; }
void Flight::addRevenue(double amount) { revenue += amount; }

ostream& operator<<(ostream& os, const Flight& flight) {
    flight.displayDetails();
    return os;
}

// Domestic Flight Implementation
DomesticFlight::DomesticFlight(string fn, string orig, string dest, string dt, int seats)
    : Flight(fn, orig, dest, dt, seats, "Domestic") {}
double DomesticFlight::calculateBaseFare() const { return 12000.0; } // Base ticket rate in PKR
void DomesticFlight::displayDetails() const {
    cout << "[Domestic] Flight No: " << flightNum << " | " << origin << " -> " << destination 
         << " | Date: " << dateTime << " | Seats Left: " << availableSeats << "/" << totalSeats;
}

// International Flight Implementation
InternationalFlight::InternationalFlight(string fn, string orig, string dest, string dt, int seats, string visa)
    : Flight(fn, orig, dest, dt, seats, "International"), visaRequirements(visa) {}
string InternationalFlight::getVisaRequirements() const { return visaRequirements; }
double InternationalFlight::calculateBaseFare() const { return 85000.0; } // Higher base rate
void InternationalFlight::displayDetails() const {
    cout << "[International] Flight No: " << flightNum << " | " << origin << " -> " << destination 
         << " | Date: " << dateTime << " | Seats Left: " << availableSeats << "/" << totalSeats << " | Visa: " << visaRequirements;
}

// Charter Flight Implementation
CharterFlight::CharterFlight(string fn, string orig, string dest, string dt, int seats, string holder)
    : Flight(fn, orig, dest, dt, seats, "Charter"), contractHolder(holder) {}
string CharterFlight::getContractHolder() const { return contractHolder; }
double CharterFlight::calculateBaseFare() const { return 350000.0; } // Private premium cost
void CharterFlight::displayDetails() const {
    cout << "[Charter] Flight No: " << flightNum << " | " << origin << " -> " << destination 
         << " | Date: " << dateTime << " | Seats Left: " << availableSeats << "/" << totalSeats << " | Contractor: " << contractHolder;
}
