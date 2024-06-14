#ifndef GRAPHLOGIC_H
#define GRAPHLOGIC_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "Req.h"
#include "Course.h"

struct Graph{
    std::vector<Requirement*> requirements;
    std::vector<Course*> courses;
    std::unordered_map<std::string, Course*> allCourses;

    void DFS(int startVertex);
};

#endif