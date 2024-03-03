#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Print to screen the project name
    cout << "Student Record System" << endl;

    // 2. Create an instance of the Roster class called classRoster.    
    Roster classRoster;

    int i;
    for (i = 0; i < 5; i++) {
        classRoster.add(
            classRoster.StudentIDArray[i],
            classRoster.FirstNameArray[i],
            classRoster.LastNameArray[i],
            classRoster.EmailArray[i],
            classRoster.AgeArray[i],
            classRoster.DaysComplete1Array[i],
            classRoster.DaysComplete2Array[i],
            classRoster.DaysComplete3Array[i],
            classRoster.DegreeArray[i]
        );
    }
    cout << endl;
    
    classRoster.printAll();

    cout << endl;
    
    classRoster.printInvalidEmails();

    cout << endl;
    
    //loop through classRosterArray and for each element:

    int x;
    for (x = 0; x < 5; x++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[x]->GetStudentID());   
    }

    //Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);

    cout << endl;

    classRoster.remove("A3");

    cout << endl;
    
    classRoster.printAll();

    cout << endl;
    
    classRoster.remove("A3");

    //expected: the above line should print a message saying such a student with this ID was not found.
    classRoster.~Roster();

    system("pause");

    return 0;
};
