#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    double mileage;

public:
    // Constructor
    Car(string b) {
        brand = b;
        mileage = 0;
    }

    // Method to drive the car
    void drive(double distance) {
        if (distance > 0) {
            mileage += distance;
        } else {
            cout << "Distance must be positive!" << endl;
        }
    }

    // Display car details
    void display() {
        cout << "\nCar Details" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Mileage: " << mileage << " km" << endl;
    }
};

int main() {
    string brand;
    double distance;

    // User inputs car brand
    cout << "Enter car brand: ";
    getline(cin, brand);

    Car car(brand);

    // User inputs distance driven
    cout << "Enter distance driven (km): ";
    cin >> distance;

    car.drive(distance);

    // Display updated details
    car.display();

    return 0;
}