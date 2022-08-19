#include "roster.hpp"
#include "student.hpp"

using namespace std;

//defining add

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    int numberDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    classRosterArray[++index] = new Student(studentID, firstName, lastName, email, age, numberDays, degreeProgram);
}

//defining removeStudent

void Roster::remove(string studentID) {
    bool studentRemoval = false;
    for (int i = 0; i <= Roster::index; i++) {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            studentRemoval = true;
            if (i < numberStudents - 1) {
                Student* temporaryID = classRosterArray[i] = classRosterArray[numberStudents - 1];
                classRosterArray[numberStudents - 1] = temporaryID;
            }
            Roster::index--;
        }
    }
    if (studentRemoval) {
    cout << "The student with the ID of " << studentID << " has been removed." << endl;
        cout << endl;
        swap(classRosterArray[2],classRosterArray[3]);
    printAll();
    }
    else cout << studentID << " was not found in the database." << endl;
    
}

//defining printAll

void Roster::printAll() {
    Student::printHeader();
    for (int i = 0; i <= Roster::index; i++) {
            if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->Student::print(); }
        }
    }


//defining printAverageDaysInCourse

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::index; i++) {
        cout <<" Student ID " << classRosterArray[i]->getStudentID() << " takes " << (classRosterArray[i]->getCourseDay()[0] + classRosterArray[i]->getCourseDay()[1] + classRosterArray[i]->getCourseDay()[2])/3.0 << " days on average to complete each course." << endl;
    }
    cout << endl;
}

//defining printInvalidEmails

void Roster::printInvalidEmails() {
    bool wrongEmail = false;
    for (int i = 0; i <= Roster::index; i++) {
        string email = (classRosterArray[i]->getEmail());
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            wrongEmail = true;
            cout << email << " is invalid." << endl;
        }
    }
    if (!wrongEmail) cout << "No wrong email addresses found." << endl;
}

//defining printByDegreeProgram

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::index; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
        cout << endl;
    };
    cout << endl;
}

//defining parse for removing student by ID

void Roster::parse(string studentData) {
    
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stod(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeProgram = studentData.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeParse = SOFTWARE;
    
    if (degreeProgram == "SECURITY") {
        degreeParse = SECURITY;
    }
    if (degreeProgram == "NETWORK") {
        degreeParse = NETWORK;
    }
    
    add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeParse);
    
}

//defining destructor

Roster::~Roster() {
    cout << "Destructor called!" << endl;
        for (int i = 0; i < numberStudents; i++)
        {
            cout << "Destroying student with ID A" << i + 1 << "." << endl;
            classRosterArray[i] = nullptr;
    }
}

