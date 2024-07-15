/* Project CourseSelector authored by James Dyer*/

#include <iostream>
#include <vector>
#include <unordered_set>

#include "FileIO.h"
#include "GlobalVariables.h"


using namespace std;

int main(int argc, char* argv[])  {

    // readCoursesFromFile("./reqs/global.txt");
    // readCoursesFromFile("./reqs/society.txt");
    // readCoursesFromFile("./reqs/sustain.txt");
    readCoursesFromFile("./reqs/tests/test1.txt");
    readCoursesFromFile("./reqs/tests/test2.txt");
    readCoursesFromFile("./reqs/tests/test3.txt");
    readCoursesFromFile("./reqs/tests/test4.txt");
    readCoursesFromFile("./reqs/tests/test5.txt");

    printCourseInfo();
    cleanMemory();

    return 0;
}