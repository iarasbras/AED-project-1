#ifndef L_EIC_SCHEDULES_MENU_H
#define L_EIC_SCHEDULES_MENU_H

#include <iostream>
#include <queue>
#include "Reading.h"
#include "Requests.h"
using namespace std;

class Menu {
private:
    BstNode *bst = Reading::readStudents();
    queue<Requests> requests;
    vector<Requests> success;
    vector<Requests> failed;
    vector<Lecture> lectures = Reading::readClasses();
    list<ClassesPerUc> classesPerUc = Reading::readClassesPerUC();


public:
    Reading d_;
    Menu();
    void welcome();
    void credits() const;
    void exitProgram() const;
    void readFiles();
    void mainMenu();
    void setReading(Reading d){d_ = d;}
    void studentsMenu() const;
    void studentsList() const;
    void studentsInfo() const;
    void lastPage() const;
    void timetablesMenu() const;
    void requestsMenu();
    void createRMenu();
    void processRMenu() ;
    void classMenu() ;
};
#endif