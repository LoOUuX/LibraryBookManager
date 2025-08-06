
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int isbn;
    bool available;
    string dateAdded;

public:
    Book() {}

    Book(string t, string a, int i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdded = date;
    }

    void setBookDetails(string t, string a, int i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdded = date;
    }

    void displayBookDetails() const {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << isbn << "\nAvailable: " << (available ? "Yes" : "No")
             << "\nDate Added: " << dateAdded << endl;
    }

    int getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is not available.\n";
        }
    }

    void returnBook() {
        available = true;
        cout << "Book returned successfully.\n";
    }
};

#endif
