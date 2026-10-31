#include <iostream>
using namespace std;

class Thermometer {
private:
    double temperature;
    static constexpr double ABSOLUTE_ZERO = -273.15;

public:
    Thermometer(double temp = 0.0) {
        if (temp < ABSOLUTE_ZERO) {
            cout << "Error: Initial temperature " << temp
                 << "°C is below absolute zero. Defaulting to 0°C." << endl;
            temperature = 0.0;
        } else {
            temperature = temp;
        }
    }

    void setTemperature(double temp) {
        if (temp < ABSOLUTE_ZERO) {
            cout << "Error: " << temp
                 << "°C is below absolute zero (-273.15°C). Temperature unchanged." << endl;
        } else {
            temperature = temp;
        }
    }

    double getTemperature() const {
        return temperature;
    }
};

int main() {
    cout << "=== Thermometer Demo ===" << endl << endl;

    // Default constructor (0°C)
    Thermometer t1;
    cout << "t1 initial temperature: " << t1.getTemperature() << "°C" << endl;

    // Valid set
    t1.setTemperature(100.0);
    cout << "After setTemperature(100.0): " << t1.getTemperature() << "°C" << endl;

    // Invalid set (below absolute zero)
    t1.setTemperature(-300.0);
    cout << "After setTemperature(-300.0): " << t1.getTemperature() << "°C (unchanged)" << endl;

    // Set to exactly absolute zero (valid boundary)
    t1.setTemperature(-273.15);
    cout << "After setTemperature(-273.15): " << t1.getTemperature() << "°C" << endl;

    // Constructor with invalid temperature
    cout << endl;
    Thermometer t2(-500.0);
    cout << "t2 temperature after invalid init: " << t2.getTemperature() << "°C" << endl;

    return 0;
}