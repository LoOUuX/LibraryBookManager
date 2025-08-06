#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
using namespace std;




// Sorting function by ISBN
void sortBookData(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });
}

// Display helper
void displayBooks(const vector<Book>& books) {
    for (const auto& b : books) {
        b.displayBookDetails();
        cout << "---------------------\n";
    }
}

int main() {
    cout << "=== Testing correct book initialisation ===\n";
    Book b1("C++ Basics", "John Smith", 105, true, "2024-05-01");
    Book b2("Python 101", "Jane Doe", 101, false, "2024-01-15");
    Book b3("Java Fundamentals", "Alice Lee", 110, true, "2024-03-10");

    b1.displayBookDetails();
    cout << "---------------------\n";
    b2.displayBookDetails();
    cout << "---------------------\n";
    b3.displayBookDetails();

    cout << "\n=== Testing incorrect initialisation ===\n";
    cout << "This section is commented out because it will cause compiler errors.\n";
    // Example incorrect initialisations:
    //Book wrong1("Test", "Test", "wrongISBN", "yes", 123); // ISBN should be int
    //Book wrong2("Sample", 123, 107, false, "2024-02-20"); // Author should be string
    //Book wrong3("Another", "Another", 109, true, 20240802);  // wrong type for dateAdded

   // wrong1.displayBookDetails();
   //cout << "---------------------\n";
    
    
    cout << "\n=== Sorting Arrays ===\n";

    // Ascending Order Test
    vector<Book> ascending = {b2, b1, b3};
    cout << "\n--- Before Sorting (Ascending Order) ---\n";
    displayBooks(ascending);
    sortBookData(ascending);
    cout << "\n--- After Sorting ---\n";
    displayBooks(ascending);

    // Descending Order Test
    vector<Book> descending = {b3, b1, b2};
    cout << "\n--- Before Sorting (Descending Order) ---\n";
    displayBooks(descending);
    sortBookData(descending);
    cout << "\n--- After Sorting ---\n";
    displayBooks(descending);

    // Mixed Order Test
    vector<Book> mixed = {b1, b3, b2};
    cout << "\n--- Before Sorting (Mixed Order) ---\n";
    displayBooks(mixed);
    sortBookData(mixed);
    cout << "\n--- After Sorting ---\n";
    displayBooks(mixed);

    return 0;
}
