#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include "Schedule.h"
#include <string>
using namespace std;

class Student{
private:
    string studentName_;
    int studentCode_;
    Schedule studentSchedule_;

public:
    //constructors
    Student();
    Student(string studentName, int studentCode, Schedule studentSchedule);

    //getters
    int getNumUcs() const;
    string getStudentName() const;
    int getStudentCode() const;
    Schedule getStudentSchedule() const;

    //setters
    void setStudentName(string studentName);
    void setStudentCode(int studentCode);
    void setStudentSchedule(Schedule studentSchedule);

};
#endif
