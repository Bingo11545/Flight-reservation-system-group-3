#include <iostream>
#include <string>
using namespace std;

struct Flight {
    string flightNumber;
    string origin;
    string destination;
    double price;
};

bool isExcludedDestination(const string& destination) {
    return (destination == "Yemen"  destination == "Ukraine"  destination == "Eritrea" 
            destination == "Somalia"  destination == "Russia" || destination == "Australia");
}

void checkFlightsFromAddisAbaba(Flight flights[], int size) {
    string userDestination;
    cout << "Welcome to Ethiopian Airlines!\n";
    cout << "Please enter your desired destination: ";
    getline(cin, userDestination);

    bool found = false;

    cout << "\nSearching for flights to " << userDestination << "...\n";

    for (int i = 0; i < size; i++) {
        if (flights[i].origin == "Addis Ababa" && flights[i].destination == userDestination) {
            if (isExcludedDestination(flights[i].destination)) {
                cout << "Sorry, flights to " << userDestination << " are currently not available.\n";
                return;
            }
            cout << "Flight " << flights[i].flightNumber << " to " << flights[i].destination
                 << " is available for $" << flights[i].price << ".\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No flights found to your desired destination from Addis Ababa.\n";
    }
}

int main() {
    Flight flights[15] = {
        {"ET500", "Addis Ababa", "New York", 1200},
        {"ET700", "Addis Ababa", "London", 950},
        {"ET300", "Addis Ababa", "Dubai", 800},
        {"ET200", "Addis Ababa", "Nairobi", 500},
        {"ET900", "Addis Ababa", "Toronto", 1100},
        {"ET100", "Addis Ababa", "Paris", 1100},
        {"ET2000", "Addis Ababa", "Rome", 1150},
        {"ET2500", "Addis Ababa", "Frankfurt", 1050},
        {"ET600", "Addis Ababa", "Cairo", 600},
        {"ET1500", "Addis Ababa", "Johannesburg", 850},
        {"ET1800", "Addis Ababa", "Beijing", 1300},
        {"ET2200", "Addis Ababa", "Los Angeles", 1350},
        {"ET2800", "Addis Ababa", "Mumbai", 950},
        {"ET3500", "Addis Ababa", "Bangkok", 1200},
        {"ET4000", "Addis Ababa", "Singapore", 1400}
    };

    checkFlightsFromAddisAbaba(flights, 15);

    return 0;
}
