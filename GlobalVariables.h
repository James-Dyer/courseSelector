// GlobalVariables.h
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "Course.h"
#include "Req.h"
#include "Logic.h"


extern struct Logic globalData;

Course* findCourse(const std::string& shortName);

bool checkCourseUniqueness(const std::string& shortName);

void printCourseInfo();

void cleanMemory();

#endif
