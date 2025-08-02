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
    Book() {
        title = "";
        author = "";
        isbn = "";
        availability = true;
        dateAdded = "";
    }

    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        availability = avail;
        dateAdded = date;
    }

    void displayBookDetails() {
        cout << "-----------------------------" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "-----------------------------" << endl;
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
        if (!availability) {
            availability = true;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "This book is already available." << endl;
        }
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return availability;
    }

    // Static method to sort books by ISBN
    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
        cout << "Books sorted by ISBN." << endl;
    }
};

int main() {
    Book books[5];
    books[0].setBookDetails("1984", "George Orwell", "003", true, "2023-01-15");
    books[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "001", true, "2023-01-10");
    books[2].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "005", true, "2023-01-20");
    books[3].setBookDetails("Pride and Prejudice", "Jane Austen", "004", true, "2023-01-12");
    books[4].setBookDetails("Moby-Dick", "Herman Melville", "002", true, "2023-01-18");

    int action;
    string inputISBN;

    while (true) {
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Borrow a Book" << endl;
        cout << "2. Return a Book" << endl;
        cout << "3. View Book Details" << endl;
        cout << "4. Sort and View All Books by ISBN" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> action;

        if (action == 0) {
            cout << "Exiting the system." << endl;
            break;
        }

        if (action == 4) {
            Book::sortBookData(books, 5);
            for (int i = 0; i < 5; i++) {
                books[i].displayBookDetails();
            }
            continue;
        }

        cout << "Enter ISBN: ";
        cin >> inputISBN;

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (books[i].getISBN() == inputISBN) {
                found = true;

                if (action == 1) {
                    books[i].displayBookDetails();
                    if (books[i].isAvailable()) {
                        cout << "This book is available to be borrowed." << endl;
                        cout << "Do you want to borrow it? (1 = Yes, 2 = No): ";
                        int confirm;
                        cin >> confirm;
                        if (confirm == 1) {
                            books[i].borrowBook();
                        } else {
                            cout << "Borrow cancelled." << endl;
                        }
                    } else {
                        cout << "This book is already borrowed." << endl;
                    }
                    books[i].displayBookDetails();
                }

                else if (action == 2) {
                    books[i].returnBook();
                    books[i].displayBookDetails();
                }

                else if (action == 3) {
                    books[i].displayBookDetails();
                }

                else {
                    cout << "Invalid option." << endl;
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

