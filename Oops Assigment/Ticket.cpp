#include "Ticket.h"

using namespace std;

Ticket::Ticket(string tId, string pId, string fNum, string seat, double fare, string stat)
    : ticketId(tId), passengerId(pId), flightNum(fNum), seatNumber(seat), farePaid(fare), status(stat) {}

string Ticket::getTicketId() const { return ticketId; }
string Ticket::getPassengerId() const { return passengerId; }
string Ticket::getFlightNum() const { return flightNum; }
double Ticket::getFarePaid() const { return farePaid; }
string Ticket::getStatus() const { return status; }
string Ticket::getSeatNumber() const { return seatNumber; }

void Ticket::cancelTicket() { status = "Cancelled"; }

// Compare tickets using IDs
bool Ticket::operator==(const Ticket& other) const {
    return this->ticketId == other.ticketId;
}

ostream& operator<<(ostream& os, const Ticket& ticket) {
    os << "Ticket ID: " << ticket.ticketId << " | Passenger: " << ticket.passengerId 
       << " | Flight: " << ticket.flightNum << " | Seat: " << ticket.seatNumber 
       << " | Paid: " << ticket.farePaid << " PKR | Status: " << ticket.status;
    return os;
}
