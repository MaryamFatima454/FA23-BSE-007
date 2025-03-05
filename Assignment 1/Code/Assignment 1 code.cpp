#include <iostream>
#include <limits>
using namespace std;

// Structure for a Task node
struct Task {
    int id;
    string description;
    int priority;
    Task* next;

    Task(int id, string desc, int priority) {
        this->id = id;
        this->description = desc;
        this->priority = priority;
        this->next = nullptr;
    }
};

// Task Management System class
class TaskManager {
private:
    Task* head;

public:
    TaskManager() {
        head = nullptr;
    }

    // Function to add a task based on priority
    void addTask(int id, string desc, int priority) {
        Task* newTask = new Task(id, desc, priority);

        if (!head || head->priority < priority) {  // Insert at head if higher priority
            newTask->next = head;
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newTask->next = temp->next;
            temp->next = newTask;
        }
        cout << "Task added successfully!\n";
    }

    // Function to remove the highest priority task
    void removeHighestPriorityTask() {
        if (!head) {
            cout << "No tasks to remove!\n";
            return;
        }
        Task* temp = head;
        head = head->next;
        cout << "Task with ID " << temp->id << " removed.\n";
        delete temp;
    }

    // Function to remove a task by ID
    void removeTaskByID(int id) {
        if (!head) {
            cout << "No tasks available.\n";
            return;
        }
        if (head->id == id) {  // If head is the task to be removed
            Task* temp = head;
            head = head->next;
            delete temp;
            cout << "Task with ID " << id << " removed.\n";
            return;
        }
        Task* temp = head;
        while (temp->next && temp->next->id != id) {
            temp = temp->next;
        }
        if (!temp->next) {
            cout << "Task not found!\n";
            return;
        }
        Task* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Task with ID " << id << " removed.\n";
    }

    // Function to view all tasks
    void viewTasks() {
        if (!head) {
            cout << "No tasks available!\n";
            return;
        }
        Task* temp = head;
        cout << "\nTask List (sorted by priority):\n";
        while (temp) {
            cout << "ID: " << temp->id << " | Desc: " << temp->description << " | Priority: " << temp->priority << "\n";
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~TaskManager() {
        while (head) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function with menu
int main() {
    TaskManager tm;
    int choice, id, priority;
    string description;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Task ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Description: ";
                getline(cin, description);
                cout << "Enter Priority (Higher number = Higher priority): ";
                cin >> priority;
                tm.addTask(id, description, priority);
                break;

            case 2:
                tm.viewTasks();
                break;

            case 3:
                tm.removeHighestPriorityTask();
                break;

            case 4:
                cout << "Enter Task ID to remove: ";
                cin >> id;
                tm.removeTaskByID(id);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
