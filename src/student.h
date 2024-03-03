#pragma once

#include <iostream>
#include "degree.h"
using namespace std;

class Student {
    public:
        // Constructor with all variables
        Student();
        Student(string a, 
            string b, 
            string c,
            string d, 
            int e, 
            int f, 
            int g, 
            int h, 
            DegreeProgram i);
        // Print function for each student
        void Print() const;

        // Accessors (getters)
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        string GetDaysToCompleteCourse() const;      
        DegreeProgram GetDegreeName() const;

        // Mutators (setters)
        void SetStudentID(string studentIDToSet);
        void SetFirstName(string firstnameToSet);
        void SetLastName(string lastnameToSet);
        void SetEmailAddress(string emailAddressToSet);
        void SetAge(int ageToSet);
        void SetDaysToCompleteCourse(int days1, int days2, int days3);
        void SetDegreeName(DegreeProgram degreeNameToSet);

    private:
        // Variables
        string studentID;
        string firstname;
        string lastname;
        string emailAddress;
        int age;
        int daysToCompleteCourse[3]; //array
        DegreeProgram degreeName; //enum
};