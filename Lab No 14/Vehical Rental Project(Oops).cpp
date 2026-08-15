#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle
{
protected:
    string company;
    string model;
    int regNo;
    float dailyRate;
    bool available;

public:

    Vehicle(string c, string m, int r, float rate)
    {
        company = c;
        model = m;
        regNo = r;
        dailyRate = rate;
        available = true;
    }

    virtual ~Vehicle()
    {
    }

    // Runtime Polymorphism
    virtual float calculateCost(int days)
    {
        return dailyRate * days;
    }

    virtual string getType()
    {
        return "Vehicle";
    }

    virtual void display()
    {
        cout << "Type: " << getType() << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "Daily Rent: Rs " << dailyRate << endl;

        if (available)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Rented" << endl;
    }

    void rent()
    {
        available = false;
    }

    void returnVehicle()
    {
        available = true;
    }

    bool isAvailable()
    {
        return available;
    }

    string getCompany()
    {
        return company;
    }

    string getModel()
    {
        return model;
    }

    int getRegNo()
    {
        return regNo;
    }
};

class Car : public Vehicle
{
private:
    int seats;

public:

    Car(string c, string m, int r, float rate, int s)
        : Vehicle(c, m, r, rate)
    {
        seats = s;
    }

    string getType() override
    {
        return "Car";
    }

    float calculateCost(int days) override
    {
        return dailyRate * days;
    }

    void display() override
    {
        cout << "Type: " << getType() << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "Daily Rent: Rs " << dailyRate << endl;
        cout << "Seats: " << seats << endl;

        if (available)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Rented" << endl;
    }
};


class Truck : public Vehicle
{
private:
    float payload;

public:

    Truck(string c, string m, int r, float rate, float p)
        : Vehicle(c, m, r, rate)
    {
        payload = p;
    }

    string getType() override
    {
        return "Truck";
    }

    // 20% surcharge
    float calculateCost(int days) override
    {
        float cost = dailyRate * days;

        cost = cost + (cost * 0.20);

        return cost;
    }

    void display() override
    {
        cout << "Type: " << getType() << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "Daily Rent: Rs " << dailyRate << endl;
        cout << "Payload: " << payload << " tonnes" << endl;

        if (available)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Rented" << endl;
    }
};

class Motorbike : public Vehicle
{
private:
    string engine;

public:

    Motorbike(string c, string m, int r, float rate, string e)
        : Vehicle(c, m, r, rate)
    {
        engine = e;
    }

    string getType() override
    {
        return "Motorbike";
    }

    // 10% discount for more than 7 days
    float calculateCost(int days) override
    {
        float cost = dailyRate * days;

        if (days > 7)
        {
            cost = cost - (cost * 0.10);
        }

        return cost;
    }

    void display() override
    {
        cout << "Type: " << getType() << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Registration No: " << regNo << endl;
        cout << "Daily Rent: Rs " << dailyRate << endl;
        cout << "Engine: " << engine << endl;

        if (available)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Rented" << endl;
    }
};


class Customer
{
private:
    string name;
    int id;
    bool rented;

public:

    Customer(string n, int i)
    {
        name = n;
        id = i;
        rented = false;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    bool hasRental()
    {
        return rented;
    }

    void setRental(bool value)
    {
        rented = value;
    }
};

class Rental
{
private:
    Customer* customer;
    Vehicle* vehicle;
    int days;
    float cost;
    bool active;

public:

    Rental(Customer* c, Vehicle* v, int d, float co)
    {
        customer = c;
        vehicle = v;
        days = d;
        cost = co;
        active = true;
    }

    Vehicle* getVehicle()
    {
        return vehicle;
    }

    Customer* getCustomer()
    {
        return customer;
    }

    bool isActive()
    {
        return active;
    }

    void closeRental()
    {
        active = false;
    }

    void display()
    {
        cout << "Customer: " << customer->getName() << endl;

        cout << "Vehicle: "
             << vehicle->getCompany() << " "
             << vehicle->getModel() << endl;

        cout << "Days: " << days << endl;

        cout << "Cost: Rs "
             << fixed << setprecision(2)
             << cost << endl;

        cout << "Status: Active" << endl;
    }
};

class RentalSystem
{
private:
    vector<Vehicle*> vehicles;
    vector<Customer*> customers;
    vector<Rental> rentals;

public:

    // Add vehicle
    void addVehicle(Vehicle* vehicle)
    {
        vehicles.push_back(vehicle);
    }

    // Add customer
    void addCustomer(Customer* customer)
    {
        customers.push_back(customer);
    }

    void rentVehicle(Customer* customer,
                     Vehicle* vehicle,
                     int days)
    {
        if (days <= 0)
        {
            cout << "\nInvalid number of days!" << endl;
            return;
        }

        if (!vehicle->isAvailable())
        {
            cout << "\nRental Failed!" << endl;
            cout << "Vehicle is already rented." << endl;
            return;
        }

        if (customer->hasRental())
        {
            cout << "\nRental Failed!" << endl;
            cout << "Customer already has an active rental." << endl;
            return;
        }

        // Runtime Polymorphism
        float cost = vehicle->calculateCost(days);

        vehicle->rent();

        customer->setRental(true);

        rentals.push_back(
            Rental(customer, vehicle, days, cost)
        );

        cout << "\n==================================" << endl;
        cout << "       RENTAL SUCCESSFUL" << endl;
        cout << "==================================" << endl;

        cout << "Customer: "
             << customer->getName() << endl;

        cout << "Vehicle: "
             << vehicle->getType() << " "
             << vehicle->getCompany() << " "
             << vehicle->getModel() << endl;

        cout << "Days: " << days << endl;

        cout << "Total Cost: Rs "
             << fixed << setprecision(2)
             << cost << endl;
    }

    void returnVehicle(Vehicle* vehicle)
    {
        int i = 0;

        // WHILE LOOP
        while (i < rentals.size())
        {
            if (rentals[i].getVehicle() == vehicle &&
                rentals[i].isActive())
            {
                rentals[i].closeRental();

                vehicle->returnVehicle();

                rentals[i].getCustomer()->setRental(false);

                cout << "\n==================================" << endl;
                cout << "      VEHICLE RETURNED" << endl;
                cout << "==================================" << endl;

                cout << "Vehicle: "
                     << vehicle->getCompany() << " "
                     << vehicle->getModel() << endl;

                cout << "Return Successful!" << endl;

                return;
            }

            i++;
        }

        cout << "\nNo active rental found!" << endl;
    }

    void displayVehicles()
    {
        cout << "\n==================================" << endl;
        cout << "          ALL VEHICLES" << endl;
        cout << "==================================" << endl;

        int i = 0;

        // WHILE LOOP
        while (i < vehicles.size())
        {
            cout << "\n----------------------------------" << endl;

            vehicles[i]->display();

            i++;
        }
    }

    void displayRentals()
    {
        cout << "\n==================================" << endl;
        cout << "        ACTIVE RENTALS" << endl;
        cout << "==================================" << endl;

        int i = 0;
        bool found = false;

        // WHILE LOOP
        while (i < rentals.size())
        {
            if (rentals[i].isActive())
            {
                rentals[i].display();

                cout << "----------------------------------" << endl;

                found = true;
            }

            i++;
        }

        if (!found)
        {
            cout << "No active rentals." << endl;
        }
    }

    void printSummary()
    {
        int available = 0;
        int rented = 0;

        int i = 0;

        // WHILE LOOP
        while (i < vehicles.size())
        {
            if (vehicles[i]->isAvailable())
                available++;
            else
                rented++;

            i++;
        }

        cout << "\n==================================" << endl;
        cout << "            SUMMARY" << endl;
        cout << "==================================" << endl;

        cout << "Available Vehicles: "
             << available << endl;

        cout << "Rented Vehicles: "
             << rented << endl;

        displayRentals();
    }


    // Destructor
    ~RentalSystem()
    {
        int i = 0;

        while (i < vehicles.size())
        {
            delete vehicles[i];
            i++;
        }

        i = 0;

        while (i < customers.size())
        {
            delete customers[i];
            i++;
        }
    }
};

int main()
{
    // Create Rental System
    RentalSystem system;

    Vehicle* car =
        new Car("Toyota", "Corolla", 101, 5000, 5);

    Vehicle* truck =
        new Truck("Isuzu", "NPR", 102, 10000, 5);

    Vehicle* bike =
        new Motorbike("Honda", "CB125", 103, 2000, "125cc");


    // Add vehicles
    system.addVehicle(car);
    system.addVehicle(truck);
    system.addVehicle(bike);

    Customer* customer1 =
        new Customer("Ammar", 1);

    Customer* customer2 =
        new Customer("Ali", 2);


    // Add customers
    system.addCustomer(customer1);
    system.addCustomer(customer2);


    // ========================================================
    // MENU
    // ========================================================

    int choice = 0;

    while (choice != 7)
    {
        cout << "\n\n==================================" << endl;
        cout << "       VEHICLE RENTAL SYSTEM" << endl;
        cout << "==================================" << endl;

        cout << "1. Display Vehicles" << endl;
        cout << "2. Rent Car" << endl;
        cout << "3. Rent Truck" << endl;
        cout << "4. Rent Motorbike" << endl;
        cout << "5. Return Vehicle" << endl;
        cout << "6. Show Summary" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system.displayVehicles();
        }

        else if (choice == 2)
        {
            int days;

            cout << "\nEnter number of days: ";
            cin >> days;

            system.rentVehicle(
                customer1,
                car,
                days
            );
        }

        else if (choice == 3)
        {
            int days;

            cout << "\nEnter number of days: ";
            cin >> days;

            system.rentVehicle(
                customer2,
                truck,
                days
            );
        }

        else if (choice == 4)
        {
            int days;

            cout << "\nEnter number of days: ";
            cin >> days;

            system.rentVehicle(
                customer1,
                bike,
                days
            );
        }

        else if (choice == 5)
        {
            int regNo;

            cout << "\nEnter Registration No: ";
            cin >> regNo;

            if (regNo == 101)
            {
                system.returnVehicle(car);
            }
            else if (regNo == 102)
            {
                system.returnVehicle(truck);
            }
            else if (regNo == 103)
            {
                system.returnVehicle(bike);
            }
            else
            {
                cout << "\nInvalid Registration Number!" << endl;
            }
        }

        else if (choice == 6)
        {
            system.printSummary();
        }

        else if (choice == 7)
        {
            cout << "\n==================================" << endl;
            cout << "Thank you for using the system!" << endl;
            cout << "Program Ended." << endl;
            cout << "==================================" << endl;
        }

        else
        {
            cout << "\nInvalid Choice!" << endl;
            cout << "Please enter 1 to 7." << endl;
        }
    }


    return 0;
}
