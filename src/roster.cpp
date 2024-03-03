#include <iostream>
#include <string>
#include "roster.h"
using namespace std;


//StudentData Table (Req. A)
const string studentData[] = 
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,Tom,Blake,t_blake@hotmail.com,26,40,50,60,SOFTWARE"};

Roster::Roster() {
    int wordIndex[9];
    int indexCount = 0;
    int i;
    //For EVERY Student
    for (i = 0; i < 5; i++) {
        classRosterArray[i] = new Student();
        int p;
        for (p = 0; p < studentData[i].length(); p++) {
            if (studentData[i][p] == ',') {
                wordIndex[indexCount] = p;
                indexCount++;
            }
            if (p == studentData[i].length() - 1) {
                wordIndex[indexCount] = p;
            }
        }
        
        int startSubString = 0;
        int rangeSubString = 0;
        int x;

        //For EVERY line of table data
        for (x = 0; x < 9; x++) {

            if (x == 0) {
                startSubString = x;
                rangeSubString = wordIndex[x];
                StudentIDArray[i] = studentData[i].substr(startSubString, rangeSubString);
            }
            else if (x >= 1 && x != 8) {
                startSubString = wordIndex[x - 1] + 1;
                rangeSubString = wordIndex[x] - wordIndex[x - 1] - 1;
                if (x == 1) {
                    FirstNameArray[i] = studentData[i].substr(startSubString, rangeSubString);
                }
                else if (x == 2) {
                    LastNameArray[i] = studentData[i].substr(startSubString, rangeSubString);
                }
                else if (x == 3) {
                    EmailArray[i] = studentData[i].substr(startSubString, rangeSubString);
                }
                else if (x ==4) {
                    AgeArray[i] = stoi(studentData[i].substr(startSubString, rangeSubString));
                }
                else if (x == 5) {
                    DaysComplete1Array[i] = stoi(studentData[i].substr(startSubString, rangeSubString));
                }
                else if (x == 6) {
                    DaysComplete2Array[i] = stoi(studentData[i].substr(startSubString, rangeSubString));
                }
                else if (x == 7) {
                    DaysComplete3Array[i] = stoi(studentData[i].substr(startSubString, rangeSubString));
                }
            } 
            else {
                startSubString = wordIndex[x - 1] + 1;
                rangeSubString = wordIndex[x] - wordIndex[x - 1];
                if (x == 8) {
                    if (studentData[i].substr(startSubString, rangeSubString) == "SECURITY"){
                        degreetest = SECURITY;
                    }
                    else if (studentData[i].substr(startSubString, rangeSubString) == "NETWORK"){
                        degreetest = NETWORK;
                    }
                    else if (studentData[i].substr(startSubString, rangeSubString) == "SOFTWARE"){
                        degreetest = SOFTWARE;
                    }    
                    DegreeArray[i] = degreetest;                
                }
            }
        }
        indexCount = 0;
    }
};

Roster::~Roster() {
    int i;
    for (i = 0; i < 5; i++) {
        delete classRosterArray[i];
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int i;
    int matchIndex = 0;
    int changeCount = 0;
    for (i = 0; i < 5; i++) {
        if (classRosterArray[i]->GetStudentID() != studentID && classRosterArray[i]->GetStudentID() == "noID") {
            if (matchIndex == 0 && changeCount == 0) {
                matchIndex = i;
                changeCount++;
                classRosterArray[i]->SetStudentID(studentID);
                classRosterArray[i]->SetFirstName(firstName);
                classRosterArray[i]->SetLastName(lastName);
                classRosterArray[i]->SetEmailAddress(emailAddress);
                classRosterArray[i]->SetAge(age);
                classRosterArray[i]->SetDaysToCompleteCourse(daysInCourse1, daysInCourse2, daysInCourse3);
                classRosterArray[i]->SetDegreeName(degreeprogram);
            }
            else {
                continue;
            }
        }
    }
}

void Roster::remove(string studentID) {
    int i;
    int s = 0;
    for (i = 0; i < 5; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            classRosterArray[i] = new Student();
            break;
        }
    }
    if (i == 5) {
        cout << "Error! Student with ID " << studentID << " not found." << endl;
    }
}; 

void Roster::printAll() {
    int i;
    for (i = 0; i < 5; i++) {
        classRosterArray[i]->Print();
    }
}; 

void Roster::printAverageDaysInCourse(string studentID) {
    string average;
    int i;
    for (i = 0; i < 5; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            average = classRosterArray[i]->GetDaysToCompleteCourse();
            int x;
            int temp;
            int averageInt = 0;
            int cnt = 0;
            for (x = 0; x < 7; x += 3) {
                averageInt = averageInt + stoi(average.substr(x, 2));
            }
            averageInt = averageInt/3;
            cout << studentID << "\tAverage Days In Course:\t" << averageInt << endl;
        }
        if (classRosterArray[i]->GetStudentID() != studentID) {
            continue;
        }
    }
}; 

void Roster::printInvalidEmails() {
    string email;
    int i;
    int x;
    int invalid = 0; //0
    int valid = 0; //2
    for (i = 0; i < 5; i++) {
        email = classRosterArray[i]->GetEmailAddress();
        for (x = 0; x < email.size() + 1; x++) {
            if (email[x] == ' ') {
                invalid++;
            }
            else if (email[x] == '@' || email[x] == '.') {
                valid++;
            }
        }
        if (valid != 2 || invalid == 1) {
            cout << "Invalid Email: " << email << endl;
        }
        else {
            continue;
        }
        x = 0;
        invalid = 0;
        valid = 0;
    }
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    DegreeProgram degree;
    int i;
    for (i = 0; i < 5; i++) {
        if (classRosterArray[i]->GetDegreeName() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}; 