#include "Menu.h"
#include <regex>

Menu::Menu()= default;

void Menu::welcome() {
    cout << "*********************" << std::endl;
    cout << "*      WELCOME      *" << std::endl;
    cout << "*********************" << std::endl;
    cout << endl << "Options:\n\t1-Start\n\t2-Credits\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                mainMenu();
                return welcome();
            case ('2'):
                credits();
                return welcome();
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Menu::credits() const {
    cout << endl << "----------|CREDITS|----------" << endl;
    cout << endl;
    cout << "Made by:" << endl;
    cout << "André Santos, up202207724" << endl;
    cout << "Iara Brás, up202208825" << endl;
    cout << "Rafael Costa, up202205013" << endl;

    cout << endl << endl << "Options:\n\tb-Back\n\te-Exit"<< endl;
    char input;
    while (true) {
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Menu::exitProgram() const {
    cout << endl << "Saving changes..." << endl;
    /* d_.file_writer("..\\csv\\updated_students_classes.csv"); */
    cout << endl << "Exiting program..." << endl;
    throw 200;
}

void Menu::mainMenu() {
    cout << endl << "----------|MAIN MENU|----------" << endl;
    cout << endl;
    //explain the options
    cout << "Students -> View students info." << endl;
    cout << "Classes -> View a class's info." << endl;
    cout << "Timetables -> View student timetables." << endl;
    cout << "Requests -> Create and process requests." << endl;
    cout << endl << "Options:\n\t1-Students\n\t2-Classes\n\t3-Timetables\n\t4-Requests\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                studentsMenu();
                return mainMenu();
            case('2'):
                classMenu();
                return mainMenu();

            case ('3'):
                timetablesMenu();
                return mainMenu();
            case ('4'):
                requestsMenu();
                return mainMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Menu::studentsMenu() const {
    cout << endl << "=========STUDENTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:\n\t1-Search student name by code\n\t2-Get nº of students enrolled in at least n Uc's \n\t3-List students\n\tb-Back\n\te-Exit"<<endl;
    char input;
    int code;
    int n;
    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('1'):
                cout << endl << "Student's code:";
                cin >> code;
                cout << endl;
                cout << BstNode::searchUp(code, bst).getStudentName() << endl;
                lastPage();
                return studentsMenu();
            case ('2'):
                cout << endl << "Number of Uc's:";
                cin >> n;
                cout << endl;
                cout << BstNode::studentsInNucs(n,bst) << endl;
                return studentsMenu();
            case ('3'):
                studentsList();
                return studentsMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void Menu::classMenu()  {
    cout << endl << "=========CLASSES=========" << endl;
    cout << endl;
    cout << endl
         << "Options:\n\t1-Get class occupation (ascending)\n\t2-Get class occupation (descending) \n\t3-List classes for a specific UC\n\tb-Back\n\te-Exit"
         << endl;
    char input;
    int code;
    string uccode;
    while (true) {
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('1'):
                Reading::studentPerClass(classesPerUc,bst);
                ClassesPerUc::ucOccupationAscending(classesPerUc);
                lastPage();
                return classMenu();
            case ('2'):
                Reading::studentPerClass(classesPerUc,bst);
                ClassesPerUc::ucOccupationDescending(classesPerUc);
                return classMenu();
            case ('3'):
                cout << endl << "Insert the UC code:";
                cin >> uccode;
                cout << endl;
                for (ClassesPerUc classe: ClassesPerUc::classesForOneUc(classesPerUc, uccode)){
                    cout << classe.getClassCode() << endl;
                }
                Reading::studentPerClass(classesPerUc,bst);
                // cout << ClassesPerUc::classesForOneUc(classesPerUc, uccode);
                return classMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void Menu::studentsList() const {
    cout << endl << "=========LIST STUDENTS=========" << endl;
    cout << endl;
    cout << "Select the filter you want to apply: " << endl;
    cout << endl
         << "Options:\n\t1-All students info (code,name and classes)\n\t2-By year\n\t3-By class\n\tb-Back\n\te-Exit"
         << endl;
    char input;
    int nr;
    string ucCode, classCode;
    char op;
    bool flag = true;
    list<Student *> l = {};
    bool flag2 = false;
    while (true) {
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('1'):
                BstNode::view(bst);
                return studentsList();
            case ('2'):
                cout << endl << "Insert year: ";
                cin >> nr; cout << endl;
                BstNode::studentsPerYear(nr, bst);
                return studentsList();
            case ('3'):
                cout << endl << "Insert UC code ('L.EIC0xx', with 'xx' being from 01 to 25): ";
                cin >> ucCode; cout << endl;
                if(regex_match(ucCode, regex("(L\\.EIC0)((1[0-9])|(2[0-5])|(0[1-9]))"))){
                    cout << endl << "Insert Class code ('yLEICxx', with 'y' being the year and 'xx' the class number): ";
                    cin >> classCode; cout << endl;
                    ClassesPerUc classe(ucCode, classCode);
                    BstNode::studentsPerClass(classe,bst);

                }
                else {
                    cout << "ERROR: Could not find UC." << endl;
                    lastPage();
                }
                return studentsList();


            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}




void Menu::timetablesMenu() const {
    cout << endl << "=========TIMETABLES MENU=========" << endl;
    cout << endl;
    cout << "Select which type of timetable you want to see." << endl;
    cout << endl << "Options:\n\t1-Student\n\tb-Back\n\te-Exit"<<endl;
    char input;
    string ucCode, classCode;
    Student stu;
    int code;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                cout << endl << "Student's code:";
                cin >> code;
                cout << endl;
                stu = BstNode::searchUp(code, bst);
                if(stu.getStudentCode() != 0) stu.getStudentSchedule().viewSc
                hedule();
                lastPage();
                return timetablesMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}
void Menu::requestsMenu()  {
    cout << endl << "=========REQUESTS MENU=========" << endl;
    cout << endl;
    cout << endl << "Options:\n\t1-Create Request\n\t2-Process Requests\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('1'):
                createRMenu();
                return requestsMenu();
            case ('2'):
                processRMenu();
                return requestsMenu();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void Menu::createRMenu()  {
    cout << endl << "=========CREATE REQUESTS=========" << endl;
    cout << endl;
    cout << endl << "Insert Student's code:";
    int code;
    string ucCode;
    string classe;
    string newclasse;
    cin >> code;
    Student stu = BstNode::searchUp(code,bst);
    if (stu.getStudentCode() == 0) {lastPage();}
    else {
        cout << endl << "Select the type of request you want to make " << endl;
        cout << endl
             << "Options:\n\t1-Remove student from uc\n\t2-Add student to uc\n\t3-Switch student's classes\n\tb-Back\n\te-Exit"
             << endl;
        char input;
        while (true) {
            cout << "Choose option:";
            cin >> input;
            switch (input) {
                case ('1'): {
                    cout << endl << endl << "Choose the UC you want to remove('L.EIC0xx'):" << endl;
                    cin >> ucCode;
                    Requests requestremove("removeUc", ucCode, code);
                    requests.push(requestremove);
                    cout << "Requests saved." << endl << endl;
                    return;
                }
                case ('2'): {
                    cout << endl << endl <<"Choose the UC you want to add('L.EIC0xx'):"<< endl;
                    cin >> ucCode;
                    Requests requestadd("addUc", ucCode, code);
                    requests.push(requestadd);
                    cout << "Requests saved." << endl << endl;
                    return;
                }
                case ('3'): {
                    cout << endl << endl <<"Choose the UC('L.EIC0xx'):"<< endl;
                    cin >> ucCode;
                    cout << endl << endl <<"Choose the class you are in('yLEICxx'):" << endl;
                    cin >> classe;
                    cout << endl << endl << "Classes you want to switch to('yLEICxx'):" << endl;
                    cin >> newclasse;
                    Requests requestswitch("switchClass", ucCode, classe,newclasse, code);
                    requests.push(requestswitch);
                    cout << "Requests saved." << endl << endl;
                    return;
                }
                case ('b'):
                    return;
                case ('e'):
                    return exitProgram();
                default:
                    cout << endl << "Not a valid option" << endl;
            }
        }
    }
}


void Menu::processRMenu() {
    while (!requests.empty()) {
        bool fails = false;
        Requests request = requests.front();
        requests.pop();

        if (request.getType() == "removeUc") {
            string ucCode = request.getUc();
            Student &student = bst->searchUp(request.getUpNumber(), bst);
            student.setStudentSchedule(student.getStudentSchedule().removeLecture(ucCode));
            cout << '\n' << "The student was successfully removed from the Uc";
            success.push_back(request);
        }
        else if (request.getType() == "addUc") {
            string ucCode = request.getUc();
            vector<Lecture> aux;
            bool suces = false;
            Student &student = bst->searchUp(request.getUpNumber(), bst);
            if (student.getNumUcs() == 7) failed.push_back(request);
            else {
                int minoccupation = ClassesPerUc::specificUcMinOccupation(ucCode, classesPerUc);
                int maxoccupation = ClassesPerUc::specificUcMaxOccupation(ucCode, classesPerUc);
                for (ClassesPerUc &classe: classesPerUc) {
                     if (classe.getUcCode() == ucCode) {
                        if (classe.getNumberStudents() < maxoccupation || classe.getNumberStudents() == minoccupation) {
                            Lecture test = Lecture::TPPLlectureFromClass(classe, lectures);
                            for (Lecture lecture: student.getStudentSchedule().getSchedule()) {
                                if (test.overlapsWith(lecture)) fails = true;
                            }
                            if (!fails) {
                                for(Lecture lecture : student.getStudentSchedule().getSchedule()){
                                    aux.push_back(lecture);
                                }
                                for(Lecture lecture : lectures){
                                    if(lecture.getClassCode() == classe.getClassCode()){
                                        if(lecture.getUcCode() == ucCode) {
                                            aux.push_back(lecture);
                                        }
                                    }
                                }

                                student.setStudentSchedule(aux);
                                classe.addStudent();
                                success.push_back(request);
                                suces = true;
                                cout << '\n' << "The student was successfully added to the Uc";
                                break;
                            }
                        }
                    }
                }
                if(!suces){cout <<'\n' << "Couldn't add the student to the Uc";}
            }
        }
        else if (request.getType() == "switchClass") {
            int nold;
            int nnew;
            vector<Lecture> aux;
            Lecture oldLecture;
            Lecture newLecture;
            string uc = request.getUc();
            string oldClass = request.getClass();
            string newClass = request.getNewClass();
            Student &student = bst->searchUp(request.getUpNumber(), bst);
            for (ClassesPerUc &old: classesPerUc) {
                if (old.getUcCode() == uc && old.getClassCode() == oldClass) {
                    nold = old.getNumberStudents();
                    oldLecture = Lecture::TPPLlectureFromClass(old, lectures);
                }
            }
            for (ClassesPerUc neww: classesPerUc) {
                if (neww.getUcCode() == uc && neww.getClassCode() == newClass) {
                    nnew = neww.getNumberStudents();
                    newLecture = Lecture::TPPLlectureFromClass(neww, lectures);
                }
            }
            for (Lecture lecture1: student.getStudentSchedule().getSchedule()) {
                for (Lecture lecture: lectures) {
                    if (lecture.getUcCode() == uc && lecture.getClassCode() == newClass) {
                        if (lecture1.getUcCode() != uc && lecture1.getClassCode() != oldClass) {
                            if (lecture.overlapsWith(lecture1)) {
                                fails = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (!fails) {
                if (abs(nold - nnew) > abs((nold - 1) - (nnew + 1)) || abs((nold - 1) - (nnew + 1)) <= 4) {
                    student.setStudentSchedule(student.getStudentSchedule().removeLecture(uc));
                    for (Lecture lecture: lectures) {
                        if (lecture.getUcCode() == uc && lecture.getClassCode() == newClass) {
                            aux.push_back(lecture);
                            for (Lecture lecture: student.getStudentSchedule().getSchedule()) {
                                if(lecture.getUcCode() != uc){
                                    aux.push_back(lecture);
                                }
                            }
                            student.setStudentSchedule(aux);
                        }
                    }
                    cout << '\n' << "Class switch successfull";
                    success.push_back(request);
                }
            }
            else{cout << '\n' << "Class switch failed";}
        }

    }

}


void Menu::lastPage() const {
    cout << endl << endl;
    cout << endl << "Options:\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}