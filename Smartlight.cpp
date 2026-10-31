#include <iostream>
using namespace std;

class SmartLight {
private:
    bool isOn;
    int brightness;

public:
    // Constructor
    SmartLight() : isOn(false), brightness(1) {}

    // Turn the light on
    void turnOn() {
        if (isOn) {
            cout << "Light is already ON.\n";
        } else {
            isOn = true;
            cout << "Light turned ON. Brightness: " << brightness << "\n";
        }
    }

    // Turn the light off
    void turnOff() {
        if (!isOn) {
            cout << "Light is already OFF.\n";
        } else {
            isOn = false;
            cout << "Light turned OFF.\n";
        }
    }

    // Adjust brightness (only when light is on)
    void adjustBrightness(int level) {
        if (!isOn) {
            cout << "Cannot adjust brightness — light is OFF.\n";
        } else if (level < 1 || level > 10) {
            cout << "Invalid brightness level. Choose between 1 and 10.\n";
        } else {
            brightness = level;
            cout << "Brightness adjusted to: " << brightness << "\n";
        }
    }

    // Display current state
    void getStatus() const {
        cout << "Light is " << (isOn ? "ON" : "OFF")
             << " | Brightness: " << brightness << "\n";
    }
};

int main() {
    SmartLight light;

    cout << "--- Initial Status ---\n";
    light.getStatus();

    cout << "\n--- Adjusting brightness while OFF ---\n";
    light.adjustBrightness(7);      // Should fail

    cout << "\n--- Turning ON ---\n";
    light.turnOn();

    cout << "\n--- Adjusting brightness while ON ---\n";
    light.adjustBrightness(7);      // Should succeed
    light.adjustBrightness(15);     // Out of range
    light.adjustBrightness(-1);     // Out of range

    cout << "\n--- Turning OFF ---\n";
    light.turnOff();
    light.turnOff();                // Already off

    cout << "\n--- Final Status ---\n";
    light.getStatus();

    return 0;
}