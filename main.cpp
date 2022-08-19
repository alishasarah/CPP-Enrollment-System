#include <iostream>
#include <string>
#include "roster.hpp"
#include "degree.h"
#include "student.hpp"


using namespace std;

int main() {
    
    cout << "C867 - Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 010358962" << endl;
    cout << "Alisha Crockford" << endl;
    cout << endl;
    
    
    const string studentData[] = {
        "A1,John,Smith,john1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,the_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Alisha,Crockford,acroc46@wgu.edu,26,3,5,1,SOFTWARE"
    };
    
    
    const int numberStudents = 5;
    Roster classRoster;
    
    
    //print all
    
    for (int i = 0; i < numberStudents; ++i) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << endl;
    classRoster.printAll();
    cout << endl;
    
    //degree programs
    
    for (int i = 0; i < 1; i++) {
        cout << "Students listed by degree program: " << degreeProgramString[2] << '\t';
        classRoster.printByDegreeProgram((DegreeProgram)2);
        cout << endl;
    }
    
    //invalid emails
    
    cout << "Students with invalid email addresses: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    //average days in course
    
    cout << "Average days it takes to complete each course: " << endl;
    classRoster.printAverageDaysInCourse("A1");
    
    //removing students by IDs
    
    cout << "Removing Student with the ID of A3:" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    //removing student by ID again with error
    
    cout << "Removing Student with the ID of A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;
    
    
    cout << "DONE." << endl << endl;
    
    return 0;
    
    
}
