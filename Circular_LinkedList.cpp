#include <iostream>
using namespace std;

struct Node {
    int trackID;
    string trackName;
    string artistName;
    float duration;
    Node* next;
};

class CSLL {
private:
    Node* head;

public:
    CSLL() {
        head = NULL;
    }

    void insertAtBeginning(int id, string name, string artist, float duration) {
        Node* newNode = new Node{id, name, artist, duration, NULL};

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int id, string name, string artist, float duration) {
        Node* newNode = new Node{id, name, artist, duration, NULL};

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtPosition(int pos, int id, string name, string artist, float duration) {
        if (pos == 1) {
            insertAtBeginning(id, name, artist, duration);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        Node* newNode = new Node{id, name, artist, duration, temp->next};
        temp->next = newNode;
    }

    void deleteFirst() {
        if (head == NULL)
            return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        Node* del = head;
        head = head->next;
        temp->next = head;
        delete del;
    }

    void deleteLast() {
        if (head == NULL)
            return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* prev = NULL;
        Node* curr = head;

        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = head;
        delete curr;
    }

    void deleteByID(int id) {
        if (head == NULL)
            return;

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->trackID == id) {
                if (curr == head)
                    deleteFirst();
                else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void display() {
        if (head == NULL)
            return;

        Node* temp = head;
        do {
            cout << "ID: " << temp->trackID
                 << " Name: " << temp->trackName
                 << " Artist: " << temp->artistName
                 << " Duration: " << temp->duration << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CSLL playlist;
    int choice, id, pos;
    string name, artist;
    float duration;

    do {
        cout << "\n1 Insert Beginning\n2 Insert End\n3 Insert Position\n4 Delete First\n5 Delete Last\n6 Delete By ID\n7 Display\n0 Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> id >> name >> artist >> duration;
            playlist.insertAtBeginning(id, name, artist, duration);
            break;

        case 2:
            cin >> id >> name >> artist >> duration;
            playlist.insertAtEnd(id, name, artist, duration);
            break;

        case 3:
            cin >> pos >> id >> name >> artist >> duration;
            playlist.insertAtPosition(pos, id, name, artist, duration);
            break;

        case 4:
            playlist.deleteFirst();
            break;

        case 5:
            playlist.deleteLast();
            break;

        case 6:
            cin >> id;
            playlist.deleteByID(id);
            break;

        case 7:
            playlist.display();
            break;
        }
    } while (choice != 0);

    return 0;
}

