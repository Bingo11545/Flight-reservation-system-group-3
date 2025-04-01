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
    string date; // Flight date
};

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
        cout << "Sorry, no seats available for flight on " << currentFlight.date << ".\n";
    } else {
        cout << "Seat " << seatAssigned << " reserved successfully for " << name 
             << " on flight " << currentFlight.date << ".\n";
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
    cout << "\nFlight Capacity for " << currentFlight.date << ":" << endl;
    cout << "Total Seats: " << totalSeats << endl;
    cout << "Reserved Seats: " << reservedSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;
}

// Function to display reserved seats
void displayReservedSeats(Seat seats[], int totalSeats, Flight currentFlight) {
    cout << "\nReserved Seats for Flight on " << currentFlight.date << ":" << endl;
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i].seatNumber != -1) {
            cout << "Seat " << seats[i].seatNumber << ": " << seats[i].passengerName << endl;
        }
    }
}

// Function to set flight date
void setFlightDate(Flight &currentFlight) {
    cout << "Enter flight date (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, currentFlight.date);
    cout << "Flight date set to: " << currentFlight.date << endl;
}

int main() {
    const int totalSeats = 150; // Total number of seats
    Seat seats[totalSeats];
    Flight currentFlight;

    // Initialize all seats as not reserved
    for (int i = 0; i < totalSeats; ++i) {
        seats[i].seatNumber = -1;
        seats[i].passengerName = "";
    }

    // Set initial flight date
    currentFlight.date = "2025-04-01";

    int choice;
    do {
        cout << "\n--- Airline Reservation System ---\n";
        cout << "Current Flight Date: " << currentFlight.date << endl;
        cout << "1. Set flight date\n";
        cout << "2. Display flight capacity\n";
        cout << "3. Reserve a seat\n";
        cout << "4. Display reserved seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                setFlightDate(currentFlight);
                break;
            case 2:
                displayFlightCapacity(seats, totalSeats, currentFlight);
                break;
            case 3:
                reserveSeatAuto(seats, totalSeats, currentFlight);
                break;
            case 4:
                displayReservedSeats(seats, totalSeats, currentFlight);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
