#include "Lecture.h"
#include "ClassesPerUc.h"

//constructors

Lecture::Lecture(string classCode, string ucCode, string weekDay, double startHour, double duration, string type) : ClassesPerUc(ucCode, classCode), weekDay_(weekDay), startHour_(startHour), duration_(duration), type_(type){}
Lecture::Lecture(string ucCode, string classCode) : ClassesPerUc(classCode, ucCode){
    weekDay_ = "";
    startHour_ = 0;
    duration_ = 0;
    type_ = "";
}
Lecture::Lecture() : ClassesPerUc() {

    weekDay_ = "";
    startHour_ = 0;
    duration_ = 0;
    type_ = "";
}
//getters



string Lecture::getWeekDay() const {
    return weekDay_;
}

double Lecture::getStartHour() const {
    return startHour_;
}

double Lecture::getEndHour() const {
    return endHour_;
}

double Lecture::getDuration() const {
    return duration_;
}

string Lecture::getType() const {
    return type_;
}

//setters

void Lecture::setClassCode(string classCode) {classCode_ = classCode;}

void Lecture::setUcCode(string ucCode) {ucCode_ = ucCode;}

void Lecture::setWeekDay(string weekDay) {weekDay_ = weekDay;}

void Lecture::setStartHour(double startHour) {startHour_ = startHour;}

void Lecture::setEndHour(double endHour) {endHour_ = endHour;}

void Lecture::setDuration(double duration) {duration_ = duration;}

void Lecture::setType(string type) {type_ = type;}


//Complexity O(1)
bool Lecture::overlapsWith(const Lecture &otherLecture) const {
    if (weekDay_ == otherLecture.weekDay_) {
        if (type_ == "T" and (otherLecture.type_ == "TP" or otherLecture.type_ == "T" or otherLecture.type_ == "PL")) {
            return false;
        } else if (type_ == "TP" and (otherLecture.type_ == "T")) {
            return false;
        } else {
            if ((startHour_ == otherLecture.startHour_) or (startHour_ < (otherLecture.startHour_ + otherLecture.duration_) and (startHour_ + duration_) > otherLecture.startHour_)
                or (otherLecture.startHour_ < (startHour_ + duration_) && (otherLecture.startHour_ + otherLecture.duration_ > startHour_))){
                return true;
            }
        }
    }
    return false;
}
//Complexity O(n)
Lecture Lecture::TPPLlectureFromClass(ClassesPerUc classe, vector<Lecture> lectures) {
    for (Lecture lecture : lectures){
        if(lecture.getType() == "TP" || lecture.getType() == "PL"){
            if(lecture.getUcCode() == classe.getUcCode() && lecture.getClassCode() == classe.getClassCode()){return lecture;}
        }
    }
}




