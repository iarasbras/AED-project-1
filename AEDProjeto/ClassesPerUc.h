#ifndef PROJECT_CLASSESPERUC_H
#define PROJECT_CLASSESPERUC_H

#include <string>
#include <list>

using namespace std;


class ClassesPerUc{
protected:
    string classCode_, ucCode_;
    int numberStudents = 0;

public:
    ClassesPerUc(string uccode, string classcode);
    ClassesPerUc();
    const string getClassCode() const;
    const string getUcCode() const;
    int getNumberStudents() const;
    void addStudent();
    static void ucOccupation(list<ClassesPerUc> classes);
    static void ucOccupationAscending(list<ClassesPerUc> classes);
    static void ucOccupationDescending(list<ClassesPerUc> classes);
    static int specificUcMaxOccupation(string ucCode, list<ClassesPerUc> classes);
    static int specificUcMinOccupation(string ucCode, list<ClassesPerUc> classes);
    static list<ClassesPerUc> classesForOneUc(list<ClassesPerUc>, string ucCode);
    static int classBalance(list<ClassesPerUc>, string ucCode);
};
#endif
