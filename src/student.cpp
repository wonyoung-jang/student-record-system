#include <iostream>
#include <string>
#include "student.h"
using namespace std;


//Accessor Functions
string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstname;
}

string Student::GetLastName() const {
    return lastname;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

string Student::GetDaysToCompleteCourse() const {
    string tempString;
    int i;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            tempString.append(to_string(daysToCompleteCourse[i]));
        }
        else {
            tempString.append(to_string(daysToCompleteCourse[i]) + ",");
        }
    }
    return tempString;
}

DegreeProgram Student::GetDegreeName() const {
    return degreeName;
}

//Mutator Functions
void Student::SetStudentID(string studentIDToSet) {
    studentID = studentIDToSet;
}

void Student::SetFirstName(string firstnameToSet) {
    firstname = firstnameToSet;
}

void Student::SetLastName(string lastnameToSet) {
    lastname = lastnameToSet;
}

void Student::SetEmailAddress(string emailAddressToSet) {
    emailAddress = emailAddressToSet;
}

void Student::SetAge(int ageToSet) {
    age = ageToSet;
}

void Student::SetDaysToCompleteCourse(int days1, int days2, int days3) {
    daysToCompleteCourse[0] = days1;
    daysToCompleteCourse[1] = days2;
    daysToCompleteCourse[2] = days3;
}

void Student::SetDegreeName(DegreeProgram degreeNameToSet) {
    degreeName = degreeNameToSet;
}

//Constructor Function
Student::Student() {
    studentID = "noID";
    firstname = "noFirst";
    lastname = "noLast";
    emailAddress = "noEmail";
    age = 0;
    daysToCompleteCourse[0] = 0;
    daysToCompleteCourse[1] = 0;
    daysToCompleteCourse[2] = 0;
    degreeName = SOFTWARE;
}
Student::Student(string a, 
            string b, 
            string c,
            string d, 
            int e, 
            int f, 
            int g, 
            int h, 
            DegreeProgram i) {
    studentID = a;
    firstname = b;
    lastname = c;
    emailAddress = d;
    age = e;
    daysToCompleteCourse[0] = f;
    daysToCompleteCourse[1] = g;
    daysToCompleteCourse[2] = h;
    degreeName = i;
    }

//Print Function
void Student::Print() const {
    string degreeString;
    if (degreeName == 0) {
        degreeString = "SECURITY";
    }
    else if (degreeName == 1) {
        degreeString = "NETWORK";
    }
    else if (degreeName == 2) {
        degreeString = "SOFTWARE";
    }

    string printString;
    printString = 
        studentID + " \t First Name: " +
        firstname + " \t Last Name: " +
        lastname + " \t Age: " +
        to_string(age) + " \tdaysInCourse: {" +
        to_string(daysToCompleteCourse[0]) + ", " +
        to_string(daysToCompleteCourse[1]) + ", " +
        to_string(daysToCompleteCourse[1]) + "} Degree Program: " +
        degreeString;
    cout << printString << endl;
}