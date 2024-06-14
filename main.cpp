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

    //empty for readCoursesFromFile
    // std::unordered_set<std::string> satisfiedReqs;
    // int score = 0;

    // std::vector<Course*> courseVector;
    // for (const auto& pair : allCourses) {
    //     courseVector.push_back(pair.second);
    // }

    printCourseInfo();
    cleanMemory();

    return 0;
}