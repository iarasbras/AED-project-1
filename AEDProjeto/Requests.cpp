#include "Requests.h"


Requests::Requests(std::string type, std::string uc, int upNumber) : type_(type), uc_(uc), upNumber_(upNumber) {}
Requests::Requests(std::string type, std::string uc, std::string Class, std::string newClass, int upNumber) : type_(type), uc_(uc), upNumber_(upNumber), Class_(Class), newClass_(newClass){}
string Requests::getType() {return type_;}
string Requests::getClass() {return Class_;}
string Requests::getNewClass() {return newClass_;}
string Requests::getUc() {return uc_;}
int Requests::getUpNumber() {return upNumber_;}
