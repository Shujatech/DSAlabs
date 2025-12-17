#include <iostream>
using namespace std;

class Node {
public:
    int id, duration;
    string title, artist, album;
    Node* next;
    Node* prev;

    Node ( int i, string t, string ar, string al, int d ) {
        id = i;
        title = t;
        artist = ar;
        album = al;
        duration = d;
        next = prev = NULL;
    }
};

class CDLL {
    Node* head;
    Node* current;

public:
    CDLL ( ) {
        head = current = NULL;
    }

    void insertBeg ( ) {
        int i, d;
        string t, ar, al;
        cin >> i >> t >> ar >> al >> d;
        Node* n = new Node ( i, t, ar, al, d );

        if ( !head ) {
            head = current = n;
            n->next = n->prev = n;
        }
        else {
            Node* last = head->prev;
            n->next = head;
            n->prev = last;
            last->next = n;
            head->prev = n;
            head = n;
        }
    }

    void insertEnd ( ) {
        int i, d;
        string t, ar, al;
        cin >> i >> t >> ar >> al >> d;
        Node* n = new Node ( i, t, ar, al, d );

        if ( !head ) {
            head = current = n;
            n->next = n->prev = n;
        }
        else {
            Node* last = head->prev;
            last->next = n;
            n->prev = last;
            n->next = head;
            head->prev = n;
        }
    }

    void insertPos ( int pos ) {
        if ( pos <= 1 ) {
            insertBeg ( );
            return;
        }

        Node* temp = head;
        for ( int i = 1; temp->next != head && i < pos - 1; i++ ) {
            temp = temp->next;
        }

        int i1, d;
        string t, ar, al;
        cin >> i1 >> t >> ar >> al >> d;
        Node* n = new Node ( i1, t, ar, al, d );

        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }

    void delBeg ( ) {
        if ( !head ) return;

        if ( head->next == head ) {
            delete head;
            head = current = NULL;
            return;
        }

        Node* last = head->prev;
        Node* t = head;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete t;
    }

    void delEnd ( ) {
        if ( !head ) return;

        if ( head->next == head ) {
            delete head;
            head = current = NULL;
            return;
        }

        Node* last = head->prev;
        last->prev->next = head;
        head->prev = last->prev;
        delete last;
    }

    void delPos ( int pos ) {
        if ( pos <= 1 ) {
            delBeg ( );
            return;
        }

        Node* temp = head;
        for ( int i = 1; temp->next != head && i < pos; i++ ) {
            temp = temp->next;
        }

        if ( temp == head ) return;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void displayF ( ) {
        if ( !head ) return;
        Node* t = head;
        do {
            cout << t->id << " "
                 << t->title << " "
                 << t->artist << " "
                 << t->album << " "
                 << t->duration << endl;
            t = t->next;
        }
        while ( t != head );
    }

    void displayB ( ) {
        if ( !head ) return;
        Node* t = head->prev;
        do {
            cout << t->id << " "
                 << t->title << " "
                 << t->artist << " "
                 << t->album << " "
                 << t->duration << endl;
            t = t->prev;
        }
        while ( t != head->prev );
    }

    void playNext ( ) {
        if ( !current ) return;
        current = current->next;
        cout << "Playing: " << current->title << endl;
    }

    void playPrev ( ) {
        if ( !current ) return;
        current = current->prev;
        cout << "Playing: " << current->title << endl;
    }
};

int main ( ) {
    CDLL p;
    int ch, pos;

    do {
        cout << "\n1.InsBeg 2.InsEnd 3.InsPos 4.DelBeg 5.DelEnd 6.DelPos 7.DisplayF 8.DisplayB 9.Next 10.Prev 0.Exit\n";
        cin >> ch;

        if ( ch == 1 ) p.insertBeg ( );
        else if ( ch == 2 ) p.insertEnd ( );
        else if ( ch == 3 ) { cin >> pos; p.insertPos ( pos ); }
        else if ( ch == 4 ) p.delBeg ( );
        else if ( ch == 5 ) p.delEnd ( );
        else if ( ch == 6 ) { cin >> pos; p.delPos ( pos ); }
        else if ( ch == 7 ) p.displayF ( );
        else if ( ch == 8 ) p.displayB ( );
        else if ( ch == 9 ) p.playNext ( );
        else if ( ch == 10 ) p.playPrev ( );

    } while ( ch != 0 );
}

