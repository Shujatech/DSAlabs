#include <iostream>
using namespace std;

#define MAX 5

struct Ticket {
    int ticketID;
    string customerName;
    string issue;
};

class Queue {
private:
    Ticket queue[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int id, string name, string issue) {
        if (isFull()) {
            cout << "Queue is full. Cannot add new ticket.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        queue[rear] = {id, name, issue};
        cout << "Ticket added successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No ticket to process.\n";
            return;
        }

        cout << "Processing Ticket ID: " << queue[front].ticketID << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "\nPending Tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << queue[i].ticketID
                 << ", Name: " << queue[i].customerName
                 << ", Issue: " << queue[i].issue << endl;
        }
    }

    void cancelTicket(int id) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        int index = -1;
        for (int i = front; i <= rear; i++) {
            if (queue[i].ticketID == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Ticket not found.\n";
            return;
        }

        for (int i = index; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        rear--;

        if (rear < front) {
            front = rear = -1;
        }

        cout << "Ticket canceled successfully.\n";
    }
};

int main() {
    Queue q;
    int choice, id;
    string name, issue;

    do {
        cout << "\n--- Customer Service Ticket System ---\n";
        cout << "1. Add Ticket\n";
        cout << "2. Process Ticket\n";
        cout << "3. Display Tickets\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Ticket ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Customer Name: ";
            getline(cin, name);
            cout << "Enter Issue: ";
            getline(cin, issue);
            q.enqueue(id, name, issue);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Enter Ticket ID to cancel: ";
            cin >> id;
            q.cancelTicket(id);
            break;

        case 5:
            cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
            break;

        case 6:
            cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

