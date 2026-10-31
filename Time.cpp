#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Parameterized constructor
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Constructor that takes total seconds from midnight
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    // Display function
    void display() {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }
};

int main() {
    // Default constructor
    Time t1;
    cout << "Default constructor: ";
    t1.display();

    // Parameterized constructor
    Time t2(10, 25, 45);
    cout << "Parameterized constructor: ";
    t2.display();

    // Constructor using total seconds from midnight
    Time t3(3661);
    cout << "From total seconds: ";
    t3.display();

    return 0;
}