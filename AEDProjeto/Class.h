

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H

#include <string>
#include "Schedule.h"
using namespace std;

class Class{

private:
    string ClassCode_;
    Schedule schedule_;

public:
    //constructors
    Class();
    Class(string classCode, Schedule schedule);

    //getters
    Schedule getSchedule() const;




    string getClassCode() const;

    //bool capacity(map<string, int> Max_StudentsClass, Class);

    //setters
    void setClassCode(string classCode);
    void setSchedule(Schedule schedule);


};
#endif


