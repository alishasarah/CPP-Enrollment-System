#include <string>
#include "student.hpp"
#include "degree.h"

using namespace std;

//contstructor

Student::Student() {
    this->studentID="";
    this->firstName="";
    this->lastName="";
    this->email="";
    this->age=0;
    for (int i = 0; i < courseDayArray; i++) this->courseDay[i] = 0;
    this->degreeProgram=DegreeProgram::SOFTWARE;
}

//decontructor

Student::~Student() {
    
}

//accessors

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getCourseDay() { return this->courseDay; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//mutators

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setCourseDay(int courseDay[])
{
    for (int i = 0; i < courseDayArray; i++) this->courseDay[i] = courseDay[i];
}
void Student::setDegree(DegreeProgram degree) { this->degreeProgram = degree; }

//other fuctions

void Student::printHeader() {
    cout << "Student ID | First Name | Last Name | Email Address | Age | Days in Courses | Degree Program" << '\t' << endl;
}
void Student::print() {
    cout << getStudentID() << '\t';
    cout << getFirstName() << '\t';
    cout << getLastName() << '\t';
    cout << getEmail() << '\t';
    cout << getAge() << '\t';
    cout << "{ " << getCourseDay()[0] << ", " << getCourseDay()[2] << ", " << getCourseDay()[3] << "}" << '\t';
    string degreeProgram;
    if (getDegreeProgram() == SECURITY) {
        degreeProgram = "SECURITY";
        cout << degreeProgram << '\t';
    }
        else if (getDegreeProgram() == NETWORK) {
            degreeProgram = "NETWORK";
            cout << degreeProgram << '\t';
        }
        else if (getDegreeProgram() == SOFTWARE) {
            degreeProgram = "SOFTWARE";
            cout << degreeProgram << '\t';
        }
    cout << endl;
    };
    
Student::Student(string studentID, string firstName, string lastName, string email, int age, int courseDay[], DegreeProgram degreeProgram) {
    this->studentID=studentID;
    this->firstName=firstName;
    this->lastName=lastName;
    this->email=email;
    this->age=age;
    for (int i = 0; i < courseDayArray; i++) this->courseDay[i] = courseDay[i];
    this->degreeProgram=degreeProgram;
}

