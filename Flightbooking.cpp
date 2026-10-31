#include <iostream>
#include <string>
using namespace std;

// FlightBooking class
class FlightBooking
{
private:
    string passengerName;
    string seatClass;

public:
    // Function to get passenger details
    void inputDetails()
    {
        cout << "Enter Passenger Name: ";
        getline(cin, passengerName);

        cout << "Select Seat Class:\n";
        cout << "1. First\n";
        cout << "2. Business\n";
        cout << "3. Economy\n";
        cout << "Enter your choice (1-3): ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            seatClass = "First";
            break;
        case 2:
            seatClass = "Business";
            break;
        case 3:
            seatClass = "Economy";
            break;
        default:
            cout << "Invalid choice! Defaulting to Economy.\n";
            seatClass = "Economy";
        }
    }

    // Function to display ticket details
    void displayTicket()
    {
        cout << "\n========== FLIGHT TICKET ==========\n";
        cout << "Passenger Name : " << passengerName << endl;
        cout << "Seat Class     : " << seatClass << endl;

        if (seatClass == "First")
            cout << "Luggage Allowance : 3 bags\n";
        else if (seatClass == "Business")
            cout << "Luggage Allowance : 2 bags\n";
        else
            cout << "Luggage Allowance : 1 bag\n";

        cout << "===================================\n";
    }
};

int main()
{
    FlightBooking booking;

    booking.inputDetails();
    booking.displayTicket();

    return 0;
}