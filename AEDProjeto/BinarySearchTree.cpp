#include <iostream>
#include <set>
#include "BinarySearchTree.h"

BstNode::BstNode() {
    student_ = Student();
    right = nullptr;
    left = nullptr;
}
BstNode::BstNode(Student student) : student_(student) {right = left = nullptr;}
//Complexity O(log(n))
BstNode *BstNode::ucInsert(BstNode* bst, Student &student) {
    if(!bst) return new BstNode(student);
    if (student.getStudentCode() < bst->student_.getStudentCode()) {
        bst->left = ucInsert(bst->left, student);
    }
    else if(student.getStudentCode() > bst->student_.getStudentCode()) {
        bst->right = ucInsert(bst->right, student);
    }
    return bst;
}
//Complexity O(n)
void BstNode::view(BstNode* base){
    if(!base) return;
    view(base->left);
    vector<Lecture> lectures = base->student_.getStudentSchedule().getSchedule();
    cout << base->student_.getStudentCode() << " | ";
    cout << base->student_.getStudentName()  << "|" ;
    for(Lecture lecture: lectures) cout << lecture.getUcCode() << "|" << lecture.getClassCode() << endl;
    view(base->right);
}

BstNode* BstNode::getLeft() { return left;}
BstNode* BstNode::getRight() {return right;}

Student BstNode::getStudent() {return student_;}

//Complexity O(n)
void BstNode::studentsPerClass(ClassesPerUc& classe, BstNode* bst) {
    if(!bst) return;
    studentsPerClass(classe, bst->left);
    for(Lecture lecture: bst->student_.getStudentSchedule().getSchedule()){
        if (lecture.getUcCode() == classe.getUcCode() && lecture.getClassCode() == classe.getClassCode()){
            if(lecture.getType() == "TP" || lecture.getType() == "PL"){
                cout << bst->student_.getStudentCode() << "|" << bst->student_.getStudentName() << endl;
            }
        }
    }
    studentsPerClass(classe, bst->right);
}
//Complexity O(n)
void BstNode::studentsPerYear(int year, BstNode *bst) {
    if(!bst) return;
    studentsPerYear(year, bst->left);
    int max = 0;
    for(Lecture lecture: bst->student_.getStudentSchedule().getSchedule()){
        char first = lecture.getClassCode().at(0);
        int y = first - '0';
        if (y > max) max = y;
    }
    if (max == year) cout << bst->student_.getStudentCode() << "|" << bst->student_.getStudentName() << endl;
    studentsPerYear(year, bst->right);
}
//Complexity O(n)
int BstNode::studentsInNucs(int n, BstNode *bst) {
    if(!bst) return 0;
    int StudentNumber = 0;
    int leftCount = studentsInNucs(n, bst->left);
    int rightCount = studentsInNucs(n , bst->right);
    int count = 0;
    for(Lecture lecture: bst->student_.getStudentSchedule().getSchedule()){
        if(lecture.getType() == "TP" || lecture.getType() == "PL"){
            count++;
        }
    }
    if (count >= n) StudentNumber++;
    return leftCount+rightCount+StudentNumber;
}
//Complexity O(log(n))
Student& BstNode::searchUp(int uc, BstNode *bst) {
    if(!bst) return *(new Student());
    else if (uc == bst->student_.getStudentCode()) return bst->student_;
    else if (uc < bst->student_.getStudentCode()) return searchUp(uc, bst->left);
    else return searchUp(uc, bst->right);
}