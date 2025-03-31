#include <iostream>
#include <fstream>
using namespace std;

#define FILE "waitlist.dat"

struct Passenger {
    string name;
    int priority;
};

struct Node {
    Passenger data;
    Node* next;
};

class Waitlist {
    Node *front = nullptr, *rear = nullptr;
public:
    ~Waitlist() { while (front) getNext(); }
    void add(string name, int priority);
    Passenger getNext();
    void load();
    void save() const;
    void display() const;
};

void Waitlist::add(string name, int priority) {
    Node* n = new Node{{name, priority}, nullptr};
    if (!front || priority < front->data.priority) {
        n->next = front;
        front = n;
    } else {
        Node* c = front;
        while (c->next && c->next->data.priority <= priority) c = c->next;
        n->next = c->next;
        c->next = n;
    }
    if (!n->next) rear = n;
    cout << name << " added to the waitlist with priority " << priority << "\n";
}

Passenger Waitlist::getNext() {
    if (!front) {
        cout << "Waitlist is empty!\n";
        return {"", -1};
    }
    Node* t = front;
    Passenger p = t->data;
    front = front->next;
    delete t;
    return p;
}

void Waitlist::load() {
    ifstream f(FILE);
    string name;
    int priority;
    while (getline(f, name) && f >> priority) {
        f.ignore();
        add(name, priority);
    }
}

void Waitlist::save() const {
    ofstream f(FILE);
    for (Node* c = front; c; c = c->next)
        f << c->data.name << "\n" << c->data.priority << "\n";
}

void Waitlist::display() const {
    if (!front) {
        cout << "Waitlist is empty!\n";
        return;
    }
    cout << "Current Waitlist:\n";
    for (Node* c = front; c; c = c->next)
        cout << "Name: " << c->data.name << ", Priority: " << c->data.priority << "\n";
}

int main() {
    Waitlist w;
    w.load();
    int choice;
    do {
        cout << "\nFlight Management System\n";
        cout << "1. Postpone the Flight\n2. Save and Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string ticketCode;
            cout << "Enter flight ticket code: ";
            getline(cin, ticketCode);
            string name;
            int priority;
            cout << "Enter passenger name: ";
            getline(cin, name);
            cout << "Enter new priority: ";
            cin >> priority;
            cin.ignore();
            w.add(name, priority);
        }
    } while (choice != 2);
    w.save();
    cout << "Waitlist saved. Exiting...\n";
    return 0;
}
