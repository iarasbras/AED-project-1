
#include "Class.h"
#include <iostream>

//constructors

Class::Class(string classCode, Schedule schedule) : ClassCode_(classCode), schedule_(schedule) {}

//getters

string Class::getClassCode() const {
    return ClassCode_;
}

Schedule Class::getSchedule() const{
    return schedule_;
}

//setters

void Class::setClassCode(string classCode){ClassCode_ = classCode;}

void Class::setSchedule(Schedule schedule){schedule_ = schedule;}

