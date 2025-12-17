#include <iostream>
using namespace std;

class Node {
public:
    int id, duration;
    string name, artist;
    Node* next;

    Node ( int i, string n, string a, int d ) {
        id = i;
        name = n;
        artist = a;
        duration = d;
        next = NULL;
    }
};

class CSLL {
    Node* head;

public:
    CSLL ( ) {
        head = NULL;
    }

    void insertBeg ( ) {
        int i, d;
        string n, a;
        cin >> i >> n >> a >> d;
        Node* t = new Node ( i, n, a, d );

        if ( !head ) {
            head = t;
            t->next = t;
        }
        else {
            Node* p = head;
            while ( p->next != head ) {
                p = p->next;
            }
            t->next = head;
            p->next = t;
            head = t;
        }
    }

    void insertEnd ( ) {
        int i, d;
        string n, a;
        cin >> i >> n >> a >> d;
        Node* t = new Node ( i, n, a, d );

        if ( !head ) {
            head = t;
            t->next = t;
        }
        else {
            Node* p = head;
            while ( p->next != head ) {
                p = p->next;
            }
            p->next = t;
            t->next = head;
        }
    }

    void insertPos ( int pos ) {
        if ( pos <= 1 ) {
            insertBeg ( );
            return;
        }

        Node* cur = head;
        for ( int i = 1; cur->next != head && i < pos - 1; i++ ) {
            cur = cur->next;
        }

        int id, d;
        string n, a;
        cin >> id >> n >> a >> d;
        Node* t = new Node ( id, n, a, d );

        t->next = cur->next;
        cur->next = t;
    }

    void delBeg ( ) {
        if ( !head ) return;

        if ( head->next == head ) {
            delete head;
            head = NULL;
            return;
        }

        Node* p = head;
        while ( p->next != head ) {
            p = p->next;
        }

        Node* t = head;
        head = head->next;
        p->next = head;
        delete t;
    }

    void delEnd ( ) {
        if ( !head ) return;

        if ( head->next == head ) {
            delete head;
            head = NULL;
            return;
        }

        Node* p = head;
        while ( p->next->next != head ) {
            p = p->next;
        }

        delete p->next;
        p->next = head;
    }

    void delByID ( int id ) {
        if ( !head ) return;

        if ( head->id == id ) {
            delBeg ( );
            return;
        }

        Node* p = head;
        while ( p->next != head && p->next->id != id ) {
            p = p->next;
        }

        if ( p->next == head ) return;

        Node* t = p->next;
        p->next = t->next;
        delete t;
    }

    void display ( ) {
        if ( !head ) return;

        Node* p = head;
        do {
            cout << p->id << " "
                 << p->name << " "
                 << p->artist << " "
                 << p->duration << endl;
            p = p->next;
        }
        while ( p != head );
    }
};

int main ( ) {
    CSLL c;
    int ch, pos, id;

    do {
        cout << "\n1.Insert Beg 2.Insert End 3.Insert Pos 4.Del Beg 5.Del End 6.Del By ID 7.Display 0.Exit\n";
        cin >> ch;

        if ( ch == 1 ) c.insertBeg ( );
        else if ( ch == 2 ) c.insertEnd ( );
        else if ( ch == 3 ) { cin >> pos; c.insertPos ( pos ); }
        else if ( ch == 4 ) c.delBeg ( );
        else if ( ch == 5 ) c.delEnd ( );
        else if ( ch == 6 ) { cin >> id; c.delByID ( id ); }
        else if ( ch == 7 ) c.display ( );

    } while ( ch != 0 );
}

