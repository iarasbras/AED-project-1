

#ifndef AEDPROJETO_BINARYSEARCHTREE_H
#define AEDPROJETO_BINARYSEARCHTREE_H

#include "Student.h"
#include <set>

class BstNode {
private:
    Student student_;
    BstNode* left;
    BstNode* right;
public:
    BstNode();
    BstNode(Student student);
    BstNode* ucInsert(BstNode* bst, Student& student);
    static void view(BstNode* bst);
    BstNode* getLeft();
    BstNode* getRight();
    Student getStudent();
    static void studentsPerClass(ClassesPerUc& classe, BstNode* bst);
    static void studentsPerYear(int year, BstNode* bst);
    static int studentsInNucs(int n, BstNode* bst);
    static Student& searchUp(int uc, BstNode* bst);
};



#endif //AEDPROJETO_BINARYSEARCHTREE_H
