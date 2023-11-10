#ifndef PROJECT_LECTURE_H
#define PROJECT_LECTURE_H

#include "ClassesPerUc.h"
#include <string>
#include <vector>

using namespace std;

class Lecture : public ClassesPerUc{
private:
    string weekDay_, type_;
    double startHour_, duration_;
    double endHour_ = (startHour_ + duration_);

public:
    //constructors
    Lecture();
    Lecture(string uccode, string classcode);
    Lecture(string classCode_, string ucCode_, string weekday, double startHour, double duration, string type);

    //getters
    string getWeekDay() const;
    double getStartHour() const;
    double getEndHour() const;
    double getDuration() const;
    string getType() const;


    //setters
    void setClassCode(string classCode);
    void setUcCode(string ucCode);
    void setWeekDay(string weekDay);
    void setStartHour(double startHour);
    void setEndHour(double endHour);
    void setDuration(double duration);
    void setType(string type);

    bool overlapsWith(const Lecture &otherLecture) const;
    static Lecture TPPLlectureFromClass(ClassesPerUc classe, vector<Lecture> lectures);
};
#endif
