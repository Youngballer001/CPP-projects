#include <iostream>
#include <string>
using namespace std;

// LibraryBook class
class LibraryBook {
private:
    string title;
    bool isAvailable;

public:
    // Constructor
    LibraryBook(string t) {
        title = t;
        isAvailable = true; // Book is available by default
    }

    // Method to check out the book
    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book \"" << title << "\" has been checked out successfully.\n";
        } else {
            cout << "Warning: The book \"" << title
                 << "\" is already checked out and is currently unavailable.\n";
        }
    }

    // Method to return the book
    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book \"" << title << "\" has been returned successfully.\n";
        } else {
            cout << "The book \"" << title << "\" is already available in the library.\n";
        }
    }

    // Display current status
    void displayStatus() {
        cout << "\nBook Title: " << title << endl;
        cout << "Availability: "
             << (isAvailable ? "Available" : "Checked Out") << endl;
    }
};

int main() {
    string bookTitle;
    int choice;

    cout << "Enter the title of the library book: ";
    getline(cin, bookTitle);

    LibraryBook book(bookTitle);

    do {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Check Out Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. Display Book Status" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                book.checkOut();
                break;

            case 2:
                book.returnBook();
                break;

            case 3:
                book.displayStatus();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}