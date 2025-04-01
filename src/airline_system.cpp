#include <iostream>
#include <string>

using namespace std;

// Define a structure for Seat
struct Seat {
    int seatNumber; // -1 indicates the seat is not reserved
    string passengerName; // Name of the passenger
};

// Define a structure for Flight
struct Flight {
    string flightNumber; // Flight number
    string origin; // Flight origin
    string destination; // Flight destination
    double price; // Flight price
};

// Function to check availability and price of flights from Addis Ababa
void checkFlightsFromAddisAbaba(Flight flights[], int size) {
    string userDestination;
    cout << "Enter your desired destination: ";
    cin.ignore();  // Clears the input buffer before using getline
    getline(cin, userDestination);

    bool found = false;
    cout << "\nSearching for flights from Addis Ababa to " << userDestination << "...\n";
    
    for (int i = 0; i < size; i++) {
        if (flights[i].origin == "Addis Ababa" && flights[i].destination == userDestination) {
            cout << "Flight " << flights[i].flightNumber << " to " << flights[i].destination
                 << " is available for $" << flights[i].price << ".\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Sorry, no flights available to " << userDestination << ".\n";
    }
}

// Function to reserve a seat automatically
void reserveSeatAuto(Seat seats[], int totalSeats, Flight currentFlight) {
    string name;

    // Ask user for their name
    cout << "Enter your name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    // Find the first available seat
    int seatAssigned = -1;
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i].seatNumber == -1) {
            seatAssigned = i + 1; // Seats are numbered from 1 to totalSeats
            seats[i].seatNumber = seatAssigned;
            seats[i].passengerName = name;
            break;
        }
    }

    if (seatAssigned == -1) {
        cout << "Sorry, no seats available for flight on " << currentFlight.flightNumber << ".\n";
    } else {
        cout << "Seat " << seatAssigned << " reserved successfully for " << name
             << " on flight " << currentFlight.flightNumber << ".\n";
    }
}

// Function to display flight capacity information
void displayFlightCapacity(Seat seats[], int totalSeats, Flight currentFlight) {
    int reservedSeats = 0;

    // Count reserved seats
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i].seatNumber != -1) {
            reservedSeats++;
        }
    }

    int availableSeats = totalSeats - reservedSeats;

    // Output flight capacity information
    cout << "\nFlight Capacity for " << currentFlight.flightNumber << ":" << endl;
    cout << "Total Seats: " << totalSeats << endl;
    cout << "Reserved Seats: " << reservedSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;
}

// Function to display reserved seats
void displayReservedSeats(Seat seats[], int totalSeats, Flight currentFlight) {
    cout << "\nReserved Seats for Flight " << currentFlight.flightNumber << ":" << endl;
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i].seatNumber != -1) {
            cout << "Seat " << seats[i].seatNumber << ": " << seats[i].passengerName << endl;
        }
    }
}

// Function to set flight date (or flight number in this case)
void setFlightDate(Flight &currentFlight) {
    cout << "Enter flight date (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, currentFlight.flightNumber); // Using flight number for simplicity
    cout << "Flight date set to: " << currentFlight.flightNumber << endl;
}
int main() {
    const int totalSeats = 150; // Total number of seats
    Seat seats[totalSeats];
    Flight flights[5] = { 
        {"ET500", "Addis Ababa", "New York", 1200},
        {"ET700", "Addis Ababa", "London", 950},
        {"ET300", "Addis Ababa", "Dubai", 800},
        {"ET200", "Addis Ababa", "Nairobi", 500},
        {"ET100", "Addis Ababa", "Paris", 1100}
    };
    Flight currentFlight = {"ET500", "Addis Ababa", "New York", 1200};  // Default current flight

    // Initialize all seats as not reserved
    for (int i = 0; i < totalSeats; ++i) {
        seats[i].seatNumber = -1;
        seats[i].passengerName = "";
    }

    int choice;
    do {
        cout << "\n--- Airline Reservation System ---\n";
        cout << "1. Set flight date\n";
        cout << "2. Check flight availability and price\n";  // Moved this option up
        cout << "3. Reserve a seat\n";
        cout << "4. Display flight capacity\n";
        cout << "5. Display reserved seats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                setFlightDate(currentFlight);
                break;
            case 2:
                checkFlightsFromAddisAbaba(flights, 5); // Check flight availability and price
                break;
            case 3:
                reserveSeatAuto(seats, totalSeats, currentFlight);
                break;
            case 4:
                displayFlightCapacity(seats, totalSeats, currentFlight);
                break;
            case 5:
                displayReservedSeats(seats, totalSeats, currentFlight);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
