#include <iostream>
using namespace std;
class Node {
public:
    int id, semester;
    float gpa;
    string name;
    Node* prev;
    Node* next;
    Node(int i, string n, int s, float g) {
        id = i; name = n; semester = s; gpa = g;
        prev = next = NULL;
    }
};
class DLL {
    Node* head;
    Node* tail;
public:
    DLL(){
        head=tail=NULL;
    }
    void insertBeg(){
        int id,s;float g;string n;
        cin>>id>>n>>s>>g;
        Node*t=new Node(id,n,s,g);
        if (!head)head=tail=t;
        else{
            t->next=head;
            head->prev=t;
            head=t;
        }
	}
    void insertEnd() {
        int id,s;float g;string n;
        cin>>id>>n>>s>>g;
        Node* t=new Node(id,n,s,g);
        if (!tail)head=tail=t;
        else{
            tail->next=t;
            t->prev=tail;
            tail=t;
        }
    }
    void insertPos(int p) {
        if (p<=1){insertBeg();return;}
        Node* cur=head;
        for(int i=1;cur&&i< p - 1; i++)cur = cur->next;
        if (!cur) return;
        int id, s; float g; string n;
        cin>> id>> n>> s>>g;
        Node* t = new Node(id, n, s, g);
        t->next = cur->next;
        t->prev = cur;
        if (cur->next) cur->next->prev = t;
        else tail = t;
        cur->next = t;
    }
    void delBeg() {
        if (!head) return;
        Node* t = head;
        if (head == tail) head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete t;
    }
    void delEnd() {
        if (!tail) return;
        Node* t = tail;
        if (head == tail) head = tail = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete t;
    }
    void delPos(int p) {
        if (p <= 1) { delBeg(); return; }
        Node* cur = head;
        for (int i = 1; cur && i < p; i++) cur = cur->next;
        if (!cur) return;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        cur->prev->next = cur->next;
        delete cur;
    }
    void displayF() {
        for (Node* t = head; t; t = t->next)
            cout << t->id << " " << t->name << " " << t->semester << " " << t->gpa << endl;
    }
    void displayB() {
        for (Node* t = tail; t; t = t->prev)
            cout << t->id << " " << t->name << " " << t->semester << " " << t->gpa << endl;
    }
};
int main() {
    DLL d;
    int ch, p;
    do {
        cout << "\n1.Insert Beg 2.Insert End 3.Insert Pos 4.Del Beg 5.Del End 6.Del Pos 7.Display F 8.Display B 0.Exit\n";
        cin >> ch;
        if (ch == 1) d.insertBeg();
        else if (ch == 2) d.insertEnd();
        else if (ch == 3) { cin >> p; d.insertPos(p); }
        else if (ch == 4) d.delBeg();
        else if (ch == 5) d.delEnd();
        else if (ch == 6) { cin >> p; d.delPos(p); }
        else if (ch == 7) d.displayF();
        else if (ch == 8) d.displayB();
    } while (ch != 0);
}

