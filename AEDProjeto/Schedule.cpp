#include <iostream>
#include "Student.h"
#include "Schedule.h"


//constructors

Schedule::Schedule() {
    vector<Lecture> schedule;
}

Schedule::Schedule(vector<Lecture> schedule) {
    schedule_ = schedule;
}
void Schedule::addLecture(Lecture& lecture) {
    vector<Lecture> aux;
    for(Lecture lecture1: schedule_){
        aux.push_back(lecture1);
    }
    aux.push_back(lecture);
    setSchedule(aux);
}
vector<Lecture> Schedule::removeLecture(string uc) {
    vector<Lecture> newSchedule;
    for(Lecture lecture: schedule_){
        if(lecture.getUcCode() != uc) newSchedule.push_back(lecture);
    }
    return newSchedule;
}
//getters

vector<Lecture> Schedule::getSchedule() const {
    return schedule_;
}

//setters

void Schedule::setSchedule(vector<Lecture> schedule){schedule_ = schedule;}

void Schedule::viewSchedule() {
    cout << "Monday: " << endl;
    for (Lecture lecture: schedule_){
        if(lecture.getWeekDay() == "Monday"){
            cout << "UC: " << lecture.getUcCode() << " Class: " << lecture.getClassCode() <<" Type: " << lecture.getType() <<  " Starts: "  << lecture.getStartHour() << " Ends " << lecture.getEndHour() << endl;        }
    }
    cout << "Tuesday:" << endl;
    for (Lecture lecture: schedule_){
        if(lecture.getWeekDay() == "Tuesday"){
            cout << "UC: " << lecture.getUcCode() << " Class: " << lecture.getClassCode() <<" Type: " << lecture.getType() <<  " Starts: "  << lecture.getStartHour() << " Ends " << lecture.getEndHour() << endl;        }
    }
    cout << "Wednesday:" << endl;
    for (Lecture lecture: schedule_){
        if(lecture.getWeekDay() == "Wednesday"){
            cout << "UC: " << lecture.getUcCode() << " Class: " << lecture.getClassCode() <<" Type: " << lecture.getType() <<  " Starts: "  << lecture.getStartHour() << " Ends " << lecture.getEndHour() << endl;
        }
    }
    cout << "Thursday:" << endl;
    for (Lecture lecture: schedule_){
        if(lecture.getWeekDay() == "Thursday"){
            cout << "UC: " << lecture.getUcCode() << " Class: " << lecture.getClassCode() <<" Type: " << lecture.getType() <<  " Starts: "  << lecture.getStartHour() << " Ends " << lecture.getEndHour() << endl;        }
    }
    cout << "Friday:" << endl;
    for (Lecture lecture: schedule_){
        if(lecture.getWeekDay() == "Friday"){
            cout << "UC: " << lecture.getUcCode() << " Class: " << lecture.getClassCode() <<" Type: " << lecture.getType() <<  " Starts: "  << lecture.getStartHour() << " Ends " << lecture.getEndHour() << endl;        }
    }
}

