#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <string>
#include "student.hpp"
#include "degree.h"


using namespace std;

    class Student {
        
    public:
        
        //constructor
        Student();
        
        //destructor
        ~Student();
        
        //accessors
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getCourseDay();
        DegreeProgram getDegreeProgram();
        
        //mutators
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setCourseDay(int courseDay[]);
        void setDegree(DegreeProgram degreeProgram);
        
        //other functions
        const static int courseDayArray = 3;
        Student(string studentID, string firstName, string lastName, string email, int age, int courseDay[], DegreeProgram degreeProgram);
        static void printHeader();
        void print();
        
        
        
    private:
        
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int courseDay[courseDayArray];
        DegreeProgram degreeProgram;

    };

#endif /* student_hpp */

