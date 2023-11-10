#include <iostream>
#include "Student.h"
#include "Class.h"
#include "Lecture.h"
#include "BinarySearchTree.h"
#include <list>
#include <queue>
#include "Reading.h"
#include "Requests.h"
#include "Menu.h"
using namespace std;
int main() {

    Reading d = Reading();
    Menu iFace = Menu();
    iFace.setReading(d);

    try {
        iFace.welcome();
    }
    catch (int exit) {
        return 0;
    }

}
