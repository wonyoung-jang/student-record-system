#pragma once

#include <iostream>
#include "degree.h"
using namespace std;

class Student {
    public:
        // Construct a Student object initializing all member variables.
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
        // Output the details of a student object to the console.
        void Print() const;

        // Accessors (Getters)
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        string GetDaysToCompleteCourse() const;      
        DegreeProgram GetDegreeName() const;

        // Mutators (Setters)
        void SetStudentID(string studentIDToSet);
        void SetFirstName(string firstnameToSet);
        void SetLastName(string lastnameToSet);
        void SetEmailAddress(string emailAddressToSet);
        void SetAge(int ageToSet);
        void SetDaysToCompleteCourse(int days1, int days2, int days3);
        void SetDegreeName(DegreeProgram degreeNameToSet);

    private:
        // Private Variables
        string studentID;
        string firstname;
        string lastname;
        string emailAddress;
        int age;
        int daysToCompleteCourse[3]; // Array storing days to complete each of the three courses.
        DegreeProgram degreeName; // Degree program the student is enrolled in, represented as an enum.
};