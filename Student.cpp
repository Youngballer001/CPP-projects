#include <iostream>
using namespace std;

// Student class
class Student
{
private:
    int rollNo;
    float gpa;

public:
    // Function to input student details
    void inputDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter GPA: ";
        cin >> gpa;
    }

    // Getter for roll number
    int getRollNo() const
    {
        return rollNo;
    }

    // Getter for GPA
    float getGPA() const
    {
        return gpa;
    }
};

int main()
{
    const int SIZE = 5;
    Student students[SIZE];

    cout << "Enter details for " << SIZE << " students:\n\n";

    // Populate the array with user input
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Student " << i + 1 << ":\n";
        students[i].inputDetails();
        cout << endl;
    }

    // Search for a student by roll number
    int targetRollNo;
    cout << "Enter the Roll Number to search: ";
    cin >> targetRollNo;

    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        if (students[i].getRollNo() == targetRollNo)
        {
            cout << "Student found.\n";
            cout << "Roll Number: " << students[i].getRollNo() << endl;
            cout << "GPA: " << students[i].getGPA() << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with Roll Number " << targetRollNo << " was not found." << endl;
    }

    return 0;
}