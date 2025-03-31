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

// Function to reserve a seat
void reserveSeat(Seat seats[], int totalSeats) {
    int seatChoice;
    string name;

    // Ask user for their name
    cout << "Enter your name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    // Display available seats
    cout << "\nAvailable seats: ";
    for (int i = 0; i < totalSeats; ++i) {
        if (seats[i].seatNumber == -1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Ask user to choose a seat
    cout << "Enter seat number you want to reserve: ";
    cin >> seatChoice;

    // Validate seat choice
    if (seatChoice < 1 || seatChoice > totalSeats || seats[seatChoice - 1].seatNumber != -1) {
        cout << "Invalid seat choice! Please try again.\n";
        return;
    }

    // Reserve the seat
    seats[seatChoice - 1].seatNumber = seatChoice;
    seats[seatChoice - 1].passengerName = name;
    cout << "Seat " << seatChoice << " reserved successfully for " << name << ".\n";
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

// Main function
int main() {
    const int totalSeats = 150; // Total number of seats
    Seat seats[totalSeats];

    // Initialize all seats as not reserved
    for (int i = 0; i < totalSeats; ++i) {
        seats[i].seatNumber = -1;
        seats[i].passengerName = "";
    }

    // Create a flight instance
    Flight currentFlight;
    currentFlight.date = "2023-10-01"; // Example flight date

    int choice;
    do {
        cout << "\n--- Airline Reservation System ---\n";
        cout << "1. Display flight capacity\n";
        cout << "2. Reserve a seat\n";
        cout << "3. Display reserved seats\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayFlightCapacity(seats, totalSeats, currentFlight);
                break;
            case 2:
                reserveSeat(seats, totalSeats);
                break;
            case 3:
                displayReservedSeats(seats, totalSeats, currentFlight);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
