#include "Student.h"
using namespace std;

//constructors

Student::Student(string studentName, int studentCode, Schedule studentSchedule) {
    studentName_ = studentName;
    studentCode_ = studentCode;
    studentSchedule_ = studentSchedule;
};

Student::Student() {
    studentName_ = "";
    studentCode_ = 0;
    studentSchedule_ =  Schedule();
}

//getters

string Student::getStudentName() const{
    return studentName_;
}
int Student::getStudentCode() const{
    return studentCode_;
}

Schedule Student::getStudentSchedule() const {
    return studentSchedule_;
}
//Complexity O(n)
int Student::getNumUcs() const {
    int count = 0;
    for(Lecture lecture: studentSchedule_.getSchedule()){
        if(lecture.getType() == "TP" || lecture.getType() == "PL"){
            count++;
        }
    }
    return count;
}

//setters

void Student::setStudentName(string studentName) {studentName_ = studentName;}

void Student::setStudentCode(int studentCode) {studentCode_ = studentCode;}

void Student::setStudentSchedule(Schedule studentSchedule) {studentSchedule_ = studentSchedule;}
