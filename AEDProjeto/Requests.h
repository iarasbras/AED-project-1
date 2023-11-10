
#ifndef AEDPROJETO_REQUESTS_H
#define AEDPROJETO_REQUESTS_H

#include "Student.h"
#include "Schedule.h"
#include <string>
using namespace std;

class Requests{
private:
    string type_, uc_, Class_, newClass_;
    int upNumber_;
public:
    Requests(string type, string uc, int upNumber);
    Requests(string type, string uc, string Class, string newClass, int upNumber);
    string getType();
    string getUc();
    string getClass();
    string getNewClass();
    string getNewUc();
    int getUpNumber();
};

#endif //AEDPROJETO_REQUESTS_H
