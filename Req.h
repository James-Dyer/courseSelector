#ifndef REQ_H
#define REQ_H
#include <string>
#include "Course.h"
#include <vector>

struct Requirement{
    std::string name;
    std::vector<Course*> courses;

    Requirement(std::string name);

    void addCourse(Course* course){
        courses.push_back(course);
    }
};

#endif