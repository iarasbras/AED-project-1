#include <iostream>
#include <algorithm>
#include <climits>
#include "ClassesPerUc.h"

ClassesPerUc::ClassesPerUc(string uccode,string classcode) : ucCode_(uccode), classCode_(classcode){}
ClassesPerUc::ClassesPerUc() {ucCode_ = ""; classCode_ = "";}

const string ClassesPerUc::getClassCode() const {
    return classCode_;
}

const string ClassesPerUc::getUcCode() const {
    return ucCode_;
}

int ClassesPerUc::getNumberStudents() const {
    return numberStudents;
}

void ClassesPerUc::addStudent() {numberStudents++;}
//Complexity O(n)
void ClassesPerUc::ucOccupation(list<ClassesPerUc> classes) {
    for (ClassesPerUc uc : classes){
        cout << uc.getUcCode() << "|" << uc.getClassCode() << " has " << uc.getNumberStudents() << " students " << endl;
    }
}
//Complexity O(n)
int ClassesPerUc::specificUcMaxOccupation(string ucCode, list<ClassesPerUc> classes) {
    int max = -1;
    for(ClassesPerUc uc : classes){
        if(uc.getUcCode() == ucCode){
            if(uc.getNumberStudents() > max) {
                max = uc.getNumberStudents();
            }
        }
    }
    return max;
}
//Complexity O(n)
int ClassesPerUc::specificUcMinOccupation(std::string ucCode, list<ClassesPerUc> classes) {
    int min = INT_MAX;
    for(ClassesPerUc uc : classes){
        if(uc.getUcCode() == ucCode){
            if(uc.getNumberStudents() < min) {
                min = uc.getNumberStudents();
            }
        }
    }
    return min;
}
//Complexity O(n)
void ClassesPerUc::ucOccupationAscending(list<ClassesPerUc> classes) {
    vector<ClassesPerUc> vector1(classes.begin(), classes.end());
    sort(vector1.begin(), vector1.end(), [](const ClassesPerUc& a, const ClassesPerUc& b){return a.getNumberStudents() < b.getNumberStudents();});
    for (ClassesPerUc uc : vector1){
        cout << uc.getUcCode() << "|" << uc.getClassCode() << " has " << uc.getNumberStudents() << " students " << endl;
    }
}
//Complexity O(n)
void ClassesPerUc::ucOccupationDescending(list<ClassesPerUc> classes) {
    vector<ClassesPerUc> vector1(classes.begin(), classes.end());
    sort(vector1.begin(), vector1.end(), [](const ClassesPerUc& a, const ClassesPerUc& b){return a.getNumberStudents() > b.getNumberStudents();});
    for (ClassesPerUc uc : vector1){
        cout << uc.getUcCode() << "|" << uc.getClassCode() << " has " << uc.getNumberStudents() << " students " << endl;
    }
}
//Complexity O(n)
list<ClassesPerUc> ClassesPerUc::classesForOneUc(list<ClassesPerUc> classesPerUc, std::string ucCode) {
    list<ClassesPerUc> newlist;
    for (ClassesPerUc classe : classesPerUc){
        if(classe.getUcCode() == ucCode){
            newlist.push_back(classe);
        }
    }
    return newlist;
}

int ClassesPerUc::classBalance(list<ClassesPerUc> classes, string ucCode) {
    return specificUcMaxOccupation(ucCode, classes) - specificUcMinOccupation(ucCode, classes);
}