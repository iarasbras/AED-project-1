#include "Reading.h"
#include "Lecture.h"
#include "Student.h"
#include "ClassesPerUc.h"
#include "Class.h"
#include "Schedule.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "BinarySearchTree.h"
#include <fstream>
#include <sstream>
#include <list>
using namespace std;
//Complexity O(n)
vector<Lecture> Reading::readClasses(){
    string classCode, ucCode, weekDay, type, header;
    double startHour, duration;
    vector<Lecture> classes;
    ifstream file("../Data/classes.csv"); //IMPORTANTE: Deve ser alterado de acordo com os ficheiros onde estão os dados
    if(file.is_open()) {
        getline(file, header);
        for (string line; getline(file, line);) {
            istringstream in(line);
            getline(in, classCode, ',');
            getline(in, ucCode, ',');
            getline(in, weekDay, ',');
            in >> startHour;
            in.ignore();
            in >> duration;
            in.ignore();
            in >> type;
            Lecture lecture = Lecture(classCode, ucCode, weekDay, startHour, duration, type);
            classes.push_back(lecture);
        }
        return classes;
    }

}

//Complexity O(n)
list<ClassesPerUc> Reading::readClassesPerUC() {
    string classCode, ucCode, header;
    list<ClassesPerUc> classesPerUc;
    ifstream file("../Data/classes_per_uc.csv");
    if(file.is_open()) {
        getline(file, header);
        for (string line; getline(file, line);) {
            istringstream in(line);
            getline(in, ucCode, ',');
            in >> classCode;
            ClassesPerUc classPerUc = ClassesPerUc(ucCode, classCode);
            classesPerUc.push_back(classPerUc);
        }
        return classesPerUc;
    }
}
//Complexity O(n*m)
BstNode* Reading::readStudents() {
    vector<Lecture> lectures = Reading::readClasses();
    BstNode* bst = new BstNode();
    bool equals = true;
    int last = 0;
    string nameCopy, ucCopy, classCopy;
    string studentName, ucCode, classCode, header;
    int studentCode;
    ifstream file("../Data/students_classes.csv");
    if(file.is_open()) {
        getline(file, header);
        Schedule schedule = Schedule();
        for (string line; getline(file, line);) {
            istringstream in(line);
            in >> studentCode;
            getline(in, header, ',');
            getline(in, studentName, ',');
            getline(in, ucCode, ',');
            in >> classCode;
            if(last == 0) {
                for (Lecture &lecture: lectures) {
                    if (lecture.getUcCode() != ucCode) continue;
                    else if (lecture.getClassCode() != classCode) continue;
                    else {
                        schedule.addLecture(lecture);
                        break;
                    }
                }
                nameCopy = studentName;
                ucCopy = ucCode;
                classCopy = classCode;
                last = studentCode;
            }
            else if(last == studentCode){
                for (Lecture &lecture: lectures) {
                    if (lecture.getUcCode() != ucCode) continue;
                    else if (lecture.getClassCode() != classCode) continue;
                    else {
                        schedule.addLecture(lecture);
                        break;
                    }
                }
            }
            else if(last != studentCode){
                Student newstudent = Student(nameCopy,last, schedule);
                bst->ucInsert(bst, newstudent);
                schedule = Schedule();
                for (Lecture &lecture: lectures) {
                    if (lecture.getUcCode() != ucCode) continue;
                    else if (lecture.getClassCode() != classCode) continue;
                    else {
                        schedule.addLecture(lecture);
                        break;
                    }
                }
                nameCopy = studentName;
                ucCopy = ucCode;
                classCopy = classCode;
                last = studentCode;
            }
        }
    }
    return bst;
}
//Complexity O(n*m)
void Reading::studentPerClass(list<ClassesPerUc> &classes, BstNode *students) {
    if(!students) return;
    studentPerClass(classes, students->getLeft());
    Student estudante = students->getStudent();
    Schedule aulas = estudante.getStudentSchedule();
    for (Lecture &lecture: aulas.getSchedule()){
        if (lecture.getType() == "TP" || lecture.getType() == "PL"){
            for (ClassesPerUc &classe : classes){
                if(lecture.getClassCode() == classe.getClassCode() && lecture.getUcCode() == classe.getUcCode()){
                    classe.addStudent();
                }
            }
        }
    }
    studentPerClass(classes, students->getRight());
}



