#include <iostream>
#include <string>
#include "Airline.h"
#include "Exceptions.h"

using namespace std;

void renderInterfaceMenu() {
    cout << "\n======================================================\n";
    cout << "          SKYLINK AIRWAYS CONSOLE MANAGEMENT          \n";
    cout << "======================================================\n";
    cout << "1. Add New Flight Records\n";
    cout << "2. View All Flight Schedules\n";
    cout << "3. Filter / Search for Flights\n";
    cout << "4. Register New Passenger Accounts\n";
    cout << "5. Process Ticket Reservation Booking\n";
    cout << "6. Cancel Flight Ticket Reservation\n";
    cout << "7. View Passenger Booking Profile History\n";
    cout << "8. Output Administration Performance Reports\n";
    cout << "9. Exit Application and Save State\n";
    cout << "Selection Choice: ";
}

int main() {
    Airline serviceHub;
    string fileStorageLocation = "airline_data.txt";
    
    // Automatically parse matching file database profiles on application initial startup execution
    serviceHub.loadFromFile(fileStorageLocation);

    // Initial mock startup entries bootstrapping (Provides reference baseline values immediately)
    serviceHub.addFlight(new DomesticFlight("PK-301", "Karachi", "Islamabad", "2026-06-01", 10));
    serviceHub.addFlight(new DomesticFlight("PK-302", "Lahore", "Karachi", "2026-06-01", 15));
    serviceHub.addFlight(new InternationalFlight("PK-781", "Islamabad", "Dubai", "2026-06-02", 20, "Gulf Entry Visa"));
    serviceHub.registerPassenger(new EconomyPassenger("P-901", "Ali Naqi"));
    serviceHub.registerPassenger(new BusinessPassenger("P-902", "Zainab Bibi"));

    int consoleSelection;
    do {
        renderInterfaceMenu();
        
        // Input validation to avoid infinite loops on invalid input types (e.g. entering characters)
        if (!(cin >> consoleSelection)) {
            cout << "Input Type Error! Please input numerical execution items only.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        try {
            if (consoleSelection == 1) {
                string fn, orig, dest, dt;
                int classification, totalSeats;
                cout << "Classification Tier (1: Domestic, 2: International, 3: Charter): "; cin >> classification;
                cout << "Flight Number Identifier: "; cin >> fn;
                cout << "Origin City Name: "; cin >> orig;
                cout << "Destination City Name: "; cin >> dest;
                cout << "Departure Date (YYYY-MM-DD): "; cin >> dt;
                cout << "Total Seating Count Capacity: "; cin >> totalSeats;

                if (classification == 1) serviceHub.addFlight(new DomesticFlight(fn, orig, dest, dt, totalSeats));
                else if (classification == 2) serviceHub.addFlight(new InternationalFlight(fn, orig, dest, dt, totalSeats, "Standard Check"));
                else if (classification == 3) serviceHub.addFlight(new CharterFlight(fn, orig, dest, dt, totalSeats, "Private Group Contract"));
                cout << "Flight registration transaction processed.\n";
            }
            else if (consoleSelection == 2) {
                serviceHub.listFlights();
            }
            else if (consoleSelection == 3) {
                int optionType;
                string queryStr;
                cout << "Query Criteria (1: By Flight Number, 2: By Route Location, 3: By Date Value): "; cin >> optionType;
                cout << "Search Keyword Term: "; cin >> queryStr;
                serviceHub.searchFlights(queryStr, optionType);
            }
            else if (consoleSelection == 4) {
                string pId, pName;
                int levelTier;
                cout << "Target Class Profile Tier (1: Economy, 2: Business, 3: First Class): "; cin >> levelTier;
                cout << "Assign Unique Identification ID: "; cin >> pId;
                cout << "Passenger Full Legal Name: "; cin.ignore(); getline(cin, pName);

                if (levelTier == 1) serviceHub.registerPassenger(new EconomyPassenger(pId, pName));
                else if (levelTier == 2) serviceHub.registerPassenger(new BusinessPassenger(pId, pName));
                else if (levelTier == 3) serviceHub.registerPassenger(new FirstClassPassenger(pId, pName));
                cout << "Passenger record addition complete.\n";
            }
            else if (consoleSelection == 5) {
                string pId, fNum, seatCode;
                cout << "Passenger Unique Key ID: "; cin >> pId;
                cout << "Flight Unique Target Code: "; cin >> fNum;
                cout << "Seat Row Placement Label (e.g., 14A): "; cin >> seatCode;
                serviceHub.bookTicket(pId, fNum, seatCode);
            }
            else if (consoleSelection == 6) {
                string tId;
                int remainingDays;
                cout << "Ticket Processing Reference ID: "; cin >> tId;
                cout << "Remaining days before scheduled departure: "; cin >> remainingDays;
                serviceHub.cancelTicket(tId, remainingDays);
            }
            else if (consoleSelection == 7) {
                string pId;
                cout << "Passenger Reference Lookup ID: "; cin >> pId;
                serviceHub.viewPassengerHistory(pId);
            }
            else if (consoleSelection == 8) {
                string dateTag;
                cout << "Enter current processing context timeline date (YYYY-MM-DD): "; cin >> dateTag;
                serviceHub.generateReports(dateTag);
            }
        }
        catch (const FlightFullException& err) {
            cout << "\n[RESERVATION FAULT EXCEPTION] -> " << err.what() << "\n";
        }
        catch (const InvalidCancellationException& err) {
            cout << "\n[CANCELLATION FAULT EXCEPTION] -> " << err.what() << "\n";
        }
        catch (const exception& generalErr) {
            cout << "\n[RUNTIME FAULT ERROR] -> " << generalErr.what() << "\n";
        }

    } while (consoleSelection != 9);

    // Commit file transaction outputs safely during runtime closing phases
    serviceHub.saveToFile(fileStorageLocation);
    cout << "State saved successfully to storage file reference. System safely offline.\n";
    return 0;
}
