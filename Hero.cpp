#include <iostream>
#include <string>
using namespace std;

class Hero
{
private:
    string name;
    int health;
    int attackPower;

public:
    // Constructor
    Hero(string n, int h, int a)
    {
        name = n;
        health = h;
        attackPower = a;
    }

    // Method for attacking another hero
    void attack(Hero &target)
    {
        cout << "\n" << name << " attacks " << target.name
             << " with " << attackPower << " attack power!" << endl;

        target.health -= attackPower;

        // Prevent health from going below 0
        if (target.health < 0)
        {
            target.health = 0;
        }

        cout << target.name << "'s health is now "
             << target.health << "." << endl;
    }

    // Display hero details
    void displayStatus()
    {
        cout << "Hero: " << name
             << "\nHealth: " << health
             << "\nAttack Power: " << attackPower << endl;
    }
};

int main()
{
    string heroAName, heroBName;
    int heroAHealth, heroAAttack;
    int heroBHealth, heroBAttack;

    // User input for Hero A
    cout << "Enter Hero A name: ";
    getline(cin, heroAName);

    cout << "Enter Hero A health: ";
    cin >> heroAHealth;

    cout << "Enter Hero A attack power: ";
    cin >> heroAAttack;

    cin.ignore();

    // User input for Hero B
    cout << "\nEnter Hero B name: ";
    getline(cin, heroBName);

    cout << "Enter Hero B health: ";
    cin >> heroBHealth;

    cout << "Enter Hero B attack power: ";
    cin >> heroBAttack;

    // Create Hero objects
    Hero heroA(heroAName, heroAHealth, heroAAttack);
    Hero heroB(heroBName, heroBHealth, heroBAttack);

    // Display initial status
    cout << "\n===== Initial Hero Status =====" << endl;
    heroA.displayStatus();
    cout << endl;
    heroB.displayStatus();

    // Simulate one turn: Hero A attacks Hero B
    cout << "\n===== Turn-Based Battle =====" << endl;
    heroA.attack(heroB);

    // Display final status
    cout << "\n===== Final Hero Status =====" << endl;
    heroA.displayStatus();
    cout << endl;
    heroB.displayStatus();

    return 0;
}