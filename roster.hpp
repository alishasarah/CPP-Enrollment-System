#ifndef roster_hpp
#define roster_hpp
#include "student.hpp"
#include <stdio.h>

class Roster {
    
    private:
    int index = -1;
    const static int numberStudents = 5;
    
    public:
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parse(string row);
    ~Roster();
    Student* classRosterArray[numberStudents];

    
};


#endif /* roster_hpp */
