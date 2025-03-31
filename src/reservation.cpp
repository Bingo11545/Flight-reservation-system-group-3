#include <iostream>
#include <string>
using namespace std;

const int TOTAL_SEATS = 150;

struct Passenger { string name; };

void checkSeatStatus(Passenger seats[], int seatNum) {
    if (seatNum < 1 || seatNum > TOTAL_SEATS) {
        cout << "Invalid seat number.\n";
        return;
    }
    if (seats[seatNum - 1].name.empty())
        cout << "Seat " << seatNum << " is available.\n";
    else
        cout << "Seat " << seatNum << " is reserved by " << seats[seatNum - 1].name << ".\n";
}

int main() {
    Passenger seats[TOTAL_SEATS] = {}; 
    int seatNum;
    
    cout << "Enter seat number (1-" << TOTAL_SEATS << "): ";
    cin >> seatNum;
    checkSeatStatus(seats, seatNum);

    return 0;
}
