#pragma once

#include <iostream>
#include "student.h"
using namespace std;


class Roster {
   public:
        Student* classRosterArray[5];
        Roster();
        // Add a new student to the roster with detailed attributes including ID, name, email, age, days in course, and degree program.
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

        // Remove a student from the roster using their student ID. Displays an error if the ID is not found in the roster.        
        void remove(string studentID); 
        
        // Display the complete list of students in a tab-separated format. Iterates through the class roster, invoking the print function for each student.
        void printAll(); 
        
        // Calculate and display the average number of days a student, identified by their ID, spends in three courses.
        void printAverageDaysInCourse(string studentID); 
        
        // Check and display all student email addresses that do not meet the validity criteria (must contain '@' and '.', and no spaces).
        void printInvalidEmails();  
        
        // List student information for a specific degree program as defined by the DegreeProgram enum.
        void printByDegreeProgram(DegreeProgram degreeProgram); 
        ~Roster();
    
        // Arrays of different values.
        string StudentIDArray[5];
        string FirstNameArray[5];
        string LastNameArray[5];
        string EmailArray[5];
        int AgeArray [5];
        int DaysComplete1Array[5];
        int DaysComplete2Array[5];
        int DaysComplete3Array[5];
        DegreeProgram DegreeArray[5];
        DegreeProgram degreetest;
};