#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdded;

public:
    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
        dateAdded = date;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdded << endl;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return availability;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "This book is currently not available." << endl;
        }
    }

    void returnBook() {
        availability = true;
    }
};

int main() {
    Book books[5];

    // Initialise 5 books
    books[0].setBookDetails("1984", "George Orwell", "001", true, "2023-01-01");
    books[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "002", true, "2023-02-01");
    books[2].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "003", true, "2023-03-01");
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "004", true, "2023-04-01");
    books[4].setBookDetails("Moby-Dick", "Herman Melville", "005", true, "2023-05-01");

    string inputISBN;

    while (true) {
        cout << "\nEnter ISBN to borrow a book (or 0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting the system." << endl;
            break;
        }

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                } else {
                    cout << "Book is not available." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "No book found with that ISBN." << endl;
        }
    }

    return 0;
}
