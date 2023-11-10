#ifndef PROJECT_SCHEDULE_H
#define PROJECT_SCHEDULE_H

#include "Lecture.h"
#include <vector>
using namespace std;

class Schedule{
private:

    vector<Lecture> schedule_;

public:
    //constructors
    Schedule();
    Schedule(vector<Lecture> schedule);
    void addLecture(Lecture& lecture);
    vector<Lecture> removeLecture(string uc);

    //getters
    vector<Lecture> getSchedule() const;

    //setters
    void setSchedule(vector<Lecture> schedule);

    void viewSchedule();

    

};
#endif
