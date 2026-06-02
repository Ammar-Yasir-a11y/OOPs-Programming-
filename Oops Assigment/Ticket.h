#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>

using namespace std;

class Ticket {
private:
    string ticketId;
    string passengerId;
    string flightNum;
    string seatNumber;
    double farePaid;
    string status; // "Booked" or "Cancelled"

public:
    Ticket(string tId, string pId, string fNum, string seat, double fare, string stat = "Booked");

    string getTicketId() const;
    string getPassengerId() const;
    string getFlightNum() const;
    double getFarePaid() const;
    string getStatus() const;
    string getSeatNumber() const;
    
    void cancelTicket();

    // Required Operator Overloading
    bool operator==(const Ticket& other) const;
    friend ostream& operator<<(ostream& os, const Ticket& ticket);
};

#endif
