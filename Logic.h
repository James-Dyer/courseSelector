#ifndef Logic_H
#define Logic_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include "Req.h"
#include "Course.h"
#include "GlobalVariables.h"

struct Logic{
    std::vector<Requirement*> requirements;
    std::vector<Course*> courses;
    std::unordered_map<std::string, Course*> allCourses;

    //int findBestClasses(std::vector<Course*> prechosenCourses);
};

#endif