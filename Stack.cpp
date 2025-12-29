#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

struct Book {
    int id;
    string title;
    string author;
    int year;
};

class BookStack {
private:
    Book books[MAX_SIZE];
    int top;

public:
    BookStack() {
        top = -1;
    }

    bool pushBook(int id, string title, string author, int year) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full.\n";
            return false;
        }
        
        top++;
        books[top].id = id;
        books[top].title = title;
        books[top].author = author;
        books[top].year = year;
        
        cout << "Book added.\n";
        return true;
    }

    bool popBook() {
        if (isEmpty()) {
            cout << "No books to remove.\n";
            return false;
        }
        
        cout << "\nRemoving top book:\n";
        cout << "ID: " << books[top].id << endl;
        cout << "Title: " << books[top].title << endl;
        cout << "Author: " << books[top].author << endl;
        cout << "Year: " << books[top].year << endl;
        
        top--;
        return true;
    }

    void peekBook() {
        if (isEmpty()) {
            cout << "No books to view.\n";
            return;
        }
        
        cout << "\nTop Book:\n";
        cout << "ID: " << books[top].id << endl;
        cout << "Title: " << books[top].title << endl;
        cout << "Author: " << books[top].author << endl;
        cout << "Year: " << books[top].year << endl;
    }

    void displayAllBooks() {
        if (isEmpty()) {
            cout << "No books to display.\n";
            return;
        }
        
        cout << "\nBooks in stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "Book #" << (top - i + 1) << ":\n";
            cout << "ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Year: " << books[i].year << endl;
            cout << "-----\n";
        }
    }

    bool isEmpty() {
        return (top == -1);
    }

    int getSize() {
        return top + 1;
    }
};

int main() {
    BookStack library;
    int choice;
    
    while (true) {
        cout << "\nBook Management System\n";
        cout << "1. Add book\n";
        cout << "2. Remove top book\n";
        cout << "3. View top book\n";
        cout << "4. Display all books\n";
        cout << "5. Check if empty\n";
        cout << "6. Get stack size\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int id, year;
            string title, author;
            
            cout << "Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Title: ";
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            cout << "Year: ";
            cin >> year;
            
            library.pushBook(id, title, author, year);
        }
        else if (choice == 2) {
            library.popBook();
        }
        else if (choice == 3) {
            library.peekBook();
        }
        else if (choice == 4) {
            library.displayAllBooks();
        }
        else if (choice == 5) {
            if (library.isEmpty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Stack has books.\n";
            }
        }
        else if (choice == 6) {
            cout << "Books in stack: " << library.getSize() << endl;
        }
        else if (choice == 7) {
            cout << "Exit.\n";
            break;
        }
        else {
            cout << "Invalid.\n";
        }
    }
    
    return 0;
}
