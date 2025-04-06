#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Patient {
    string name;
    string condition;
    int priority;
    int arrivalOrder;

    bool operator<(const Patient& other) const {
        if (priority == other.priority)
            return arrivalOrder > other.arrivalOrder; // Earlier arrival gets treated first
        return priority > other.priority; // Lower number = higher priority
    }
};

class PriorityQueue {
    vector<Patient> patients;
    int arrivalCount = 0;

public:
    int getPriorityFromCondition(const string& condition) {
        if (condition == "Heart Attack" || condition == "Stroke") return 1;
        else if (condition == "Broken Leg" || condition == "Severe Burn" || condition == "Fractured Arm") return 2;
        else if (condition == "Fever" || condition == "Food Poisoning" || condition == "Migraine") return 3;
        else return 4; // Mild Cold, Small Cut etc.
    }

    void addPatient(const string& name, const string& condition) {
        Patient p;
        p.name = name;
        p.condition = condition;
        p.priority = getPriorityFromCondition(condition);
        p.arrivalOrder = ++arrivalCount;
        patients.push_back(p);
        cout << "\nPatient added successfully!\n";
        displayTreatmentOrder();
    }

    void displayTreatmentOrder() {
        cout << "\nCurrent Treatment Order:\n";
        vector<Patient> sortedPatients = patients;
        sort(sortedPatients.begin(), sortedPatients.end());
        for (const auto& p : sortedPatients) {
            cout << p.name << " - " << p.condition << " (Priority " << p.priority << ")\n";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    string name, condition;

    do {
        cout << "\n--- Patient Treatment Menu ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter emergency condition: ";
                getline(cin, condition);
                pq.addPatient(name, condition);
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 2);

    return 0;
}
