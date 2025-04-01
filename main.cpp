#include <iostream>
#include <string>

using namespace std;

// Structure for flight and passenger details
struct Flight {
    string flightNumber;
    string origin;
    string destination;
    double price;
    string date;
};

struct Passenger {
    string name;
    int seatNumber;
};

// Constants and initialization
const int TOTAL_SEATS = 150;
Passenger seats[TOTAL_SEATS];
string currentFlightDate = "Not Scheduled";

// Flight database
Flight flights[15] = {
    {"ET500", "Addis Ababa", "New York", 1200, ""},
    {"ET700", "Addis Ababa", "London", 950, ""},
    {"ET300", "Addis Ababa", "Dubai", 800, ""},
    {"ET200", "Addis Ababa", "Nairobi", 500, ""},
    {"ET900", "Addis Ababa", "Toronto", 1100, ""},
    {"ET100", "Addis Ababa", "Paris", 1100, ""},
    {"ET2000", "Addis Ababa", "Rome", 1150, ""},
    {"ET2500", "Addis Ababa", "Frankfurt", 1050, ""},
    {"ET600", "Addis Ababa", "Cairo", 600, ""},
    {"ET1500", "Addis Ababa", "Johannesburg", 850, ""},
    {"ET1800", "Addis Ababa", "Beijing", 1300, ""},
    {"ET2200", "Addis Ababa", "Los Angeles", 1350, ""},
    {"ET2800", "Addis Ababa", "Mumbai", 950, ""},
    {"ET3500", "Addis Ababa", "Bangkok", 1200, ""},
    {"ET4000", "Addis Ababa", "Singapore", 1400, ""}
};

// Function to check excluded destinations
bool isExcludedDestination(const string& destination) {
    return (destination == "Yemen" || destination == "Ukraine" ||
            destination == "Eritrea" || destination == "Somalia" ||
            destination == "Russia" || destination == "Australia");
}

// Function to set the flight date
void setFlightDate() {
    cout << "Enter flight date (YYYY-MM-DD): ";
    getline(cin >> ws, currentFlightDate);
    cout << "Flight date set to: " << currentFlightDate << endl;
}

// Function to check available flights
void checkFlightsFromAddisAbaba() {
    string userDestination;
    cout << "Enter your desired destination: ";
    getline(cin >> ws, userDestination);

    bool found = false;
    cout << "\nSearching for flights to " << userDestination << "...\n";

    for (int i = 0; i < 15; i++) {
        if (flights[i].origin == "Addis Ababa" && flights[i].destination == userDestination) {
            if (isExcludedDestination(flights[i].destination)) {
                cout << "Sorry, flights to " << userDestination << " are currently not available.\n";
                return;
            }
            cout << "Flight " << flights[i].flightNumber << " to " << flights[i].destination
                 << " is available for $" << flights[i].price << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No flights found to your desired destination from Addis Ababa.\n";
    }
}

// Function to check flight capacity (reserved and available seats)
void displayFlightCapacity() {
    int reservedSeats = 0;
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].seatNumber != -1) {
            reservedSeats++;
        }
    }
    int availableSeats = TOTAL_SEATS - reservedSeats;

    cout << "\nFlight Capacity for " << currentFlightDate << ":\n";
    cout << "Total Seats: " << TOTAL_SEATS << endl;
    cout << "Reserved Seats: " << reservedSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;
}

// Function to reserve a seat
void reserveSeat() {
    string name;
    cout << "Enter your name: ";
    getline(cin >> ws, name);

    bool seatAssigned = false;
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].seatNumber == -1) { // Check for an available seat
            seats[i] = {name, i + 1};
            cout << "Seat " << (i + 1) << " reserved successfully for " << name
                 << " on flight " << currentFlightDate << ".\n";
            seatAssigned = true;
            break;
        }
    }
    if (!seatAssigned) {
        cout << "Sorry, no seats are available on this flight.\n";
    }
}

// Function to display all seat reservations
void displaySeats() {
    cout << "\nSeat Reservations for Flight on " << currentFlightDate << ":\n";
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].seatNumber != -1) {
            cout << "Seat " << seats[i].seatNumber << ": " << seats[i].name << endl;
        } else {
            cout << "Seat " << (i + 1) << ": Available\n";
        }
    }
}

// Function to display reserved and available seat counts
void displayReservedAndAvailableCount() {
    int reservedSeats = 0;
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i].seatNumber != -1) {
            reservedSeats++;
        }
    }
    int availableSeats = TOTAL_SEATS - reservedSeats;

    cout << "\nFlight Capacity Summary for " << currentFlightDate << ":\n";
    cout << "Reserved Seats: " << reservedSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;
}

// Main menu function
void displayMenu() {
    int choice;

    // Initialize seats
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = {"", -1}; // Ensuring all seats start as available
    }

    do {
        cout << "\n--- Ethiopian Airlines Reservation System ---\n";
        cout << "1. Set Flight Date\n";
        cout << "2. Check Available Flights\n";
        cout << "3. Check Flight Capacity\n";
        cout << "4. Reserve a Seat\n";
        cout << "5. Display Seats\n";
        cout << "6. Display Reserved and Available Count\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) { // Handle invalid input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(1000, '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                setFlightDate();
                break;
            case 2:
                checkFlightsFromAddisAbaba();
                break;
            case 3:
                displayFlightCapacity();
                break;
            case 4:
                reserveSeat();
                break;
            case 5:
                displaySeats();
                break;
            case 6:
                displayReservedAndAvailableCount();
                break;
            case 7:
                cout << "Exiting system. Goodbye!\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

// Main function
int main() {
    displayMenu();
    return 0;
}
