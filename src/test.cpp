#include <iostream>
#include <string>
using namespace std;

int daysToCompleteCourse[3] = {17, 30, 40};

string GetDaysToCompleteCourse() {
    string tempString = "{";
    int i;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            tempString.append(to_string(daysToCompleteCourse[i]) + "}");
        }
        else {
            tempString.append(to_string(daysToCompleteCourse[i]) + ", ");
        }
    }
    return tempString;    
    }

int main() {
    string StringerBell = GetDaysToCompleteCourse();
    cout << StringerBell;
};