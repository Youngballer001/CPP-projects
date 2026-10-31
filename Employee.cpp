#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
private:
    int id;
    string name;
    double hourlyRate;

public:
    // Constructor
    Employee(int empId, string empName, double rate)
    {
        id = empId;
        name = empName;
        hourlyRate = rate;
    }

    // Method to calculate salary
    double calculatePay(double hoursWorked)
    {
        if (hoursWorked <= 40)
        {
            return hoursWorked * hourlyRate;
        }
        else
        {
            double overtimeHours = hoursWorked - 40;
            return (40 * hourlyRate) + (overtimeHours * hourlyRate * 1.5);
        }
    }

    // Display employee details and salary
    void display(double hoursWorked)
    {
        cout << "\n----- Employee Payroll -----" << endl;
        cout << "Employee ID   : " << id << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Hourly Rate   : $" << fixed << setprecision(2) << hourlyRate << endl;
        cout << "Hours Worked  : " << hoursWorked << endl;
        cout << "Total Salary  : $" << calculatePay(hoursWorked) << endl;
    }
};

int main()
{
    int id;
    string name;
    double hourlyRate, hoursWorked;

    // User input
    cout << "Enter Employee ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Employee Name: ";
    getline(cin, name);

    cout << "Enter Hourly Rate: ";
    cin >> hourlyRate;

    cout << "Enter Hours Worked: ";
    cin >> hoursWorked;

    // Create Employee object
    Employee emp(id, name, hourlyRate);

    // Display payroll information
    emp.display(hoursWorked);

    return 0;
}