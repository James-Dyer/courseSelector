/* Project CourseSelector authored by James Dyer*/

#include <iostream>
#include <vector>
#include <unordered_set>

#include "FileIO.h"
#include "GlobalVariables.h"
#include "Logic.h"


using namespace std;

int main(int argc, char* argv[])  {

    readCoursesFromFile("./reqs/ucmercedReqs/global.txt");
    readCoursesFromFile("./reqs/ucmercedReqs/society.txt");
    //readCoursesFromFile("./reqs/ucmercedReqs/sustain.txt");
    //readCoursesFromFile("./reqs/ucmercedReqs/diversity.txt");
    //readCoursesFromFile("./reqs/ucmercedReqs/ethics.txt");

    // readCoursesFromFile("./reqs/testBatch1/test1.txt");
    // readCoursesFromFile("./reqs/testBatch1/test2.txt");
    // readCoursesFromFile("./reqs/testBatch1/test3.txt");
    // readCoursesFromFile("./reqs/testBatch1/test4.txt");
    // readCoursesFromFile("./reqs/testBatch1/test5.txt");

    // readCoursesFromFile("./reqs/testBatch2/r1.txt");
    // readCoursesFromFile("./reqs/testBatch2/r2.txt");
    // readCoursesFromFile("./reqs/testBatch2/r3.txt");

    //printCourseInfo();
    globalData.runLogic();
    
    cleanMemory();

    return 0;
}