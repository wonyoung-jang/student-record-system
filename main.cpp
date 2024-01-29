#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main() {
    // Print program name to screen.
    cout << "Student Record System" << endl;

    // Create an instance of the Roster class for managing student records.
    Roster classRoster;

    int studentIndex;
    for (studentIndex = 0; studentIndex < 5; studentIndex++) {
        classRoster.add(
            classRoster.StudentIDArray[studentIndex],
            classRoster.FirstNameArray[studentIndex],
            classRoster.LastNameArray[studentIndex],
            classRoster.EmailArray[studentIndex],
            classRoster.AgeArray[studentIndex],
            classRoster.DaysComplete1Array[studentIndex],
            classRoster.DaysComplete2Array[studentIndex],
            classRoster.DaysComplete3Array[studentIndex],
            classRoster.DegreeArray[studentIndex]
        );
    }
    cout << endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.printInvalidEmails();
    cout << endl;
    
    // Iterate through the classRosterArray to process each student element.
    // Use getter for classRosterArray to access each student's ID.
    int studentIndex;
    for (studentIndex = 0; studentIndex < 5; studentIndex++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[studentIndex]->GetStudentID());   
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    cout << endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.remove("A3");

    // Handle the case where a student ID is not found in the roster.
    classRoster.~Roster();

    system("pause");

    return 0;
};
