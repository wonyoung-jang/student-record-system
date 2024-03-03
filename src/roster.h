#pragma once

#include <iostream>
#include "student.h"
using namespace std;


class Roster {
   public:
        Student* classRosterArray[5];
        Roster();
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
            //sets the instance variables from part D1 and updates the roster. 
        
        void remove(string studentID); 
            //removes students from the roster by student ID. 
            //If the student ID does not exist, the function prints an error message indicating that the student was not found.
        void printAll(); 
            //prints a complete tab-separated list of student data in the provided format: 
            //A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
            //The printAll() function should loop through all the students in classRosterArray and call the print() function for each student
        void printAverageDaysInCourse(string studentID); 
            // correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
        void printInvalidEmails();  
            //verifies student email addresses and displays all invalid email addresses to the user 
            //valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
        void printByDegreeProgram(DegreeProgram degreeProgram); 
            //prints out student information for a degree program specified by an enumerated type.
        ~Roster();
    

        //Arrays of different values.
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