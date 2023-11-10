#ifndef AEDPROJETO_READING_H
#define AEDPROJETO_READING_H

#include "Lecture.h"
#include "BinarySearchTree.h"
#include "Student.h"
#include "Class.h"
#include "ClassesPerUc.h"
#include "Schedule.h"
#include <list>
#include <string>

class Reading {
public:
    static list<ClassesPerUc> readClassesPerUC();
    static vector<Lecture> readClasses();
    static BstNode* readStudents();
    static void studentPerClass(list<ClassesPerUc> &classes, BstNode* students);
};













#endif
