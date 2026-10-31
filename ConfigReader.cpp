#include <iostream>
#include <string>
using namespace std;

class ConfigReader
{
private:
    const string filename;   // Constant private data member

public:
    // Constructor using an initialization list
    ConfigReader(const string file) : filename(file)
    {
    }

    void display() const
    {
        cout << "Configuration file: " << filename << endl;
    }
};

int main()
{
    string fileName;

    cout << "Enter the configuration filename: ";
    getline(cin, fileName);

    ConfigReader config(fileName);

    config.display();

    return 0;
}