#ifndef Logic_H
#define Logic_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <climits>
#include <fstream>
#include <set>
#include <sstream>
#include <chrono>

#include "GlobalVariables.h"

struct Schedule;

struct Logic{
    std::vector<Requirement*> requirements;

    std::vector<Course*> courses;

    std::vector<Schedule*> bestSchedules;

    std::unordered_map<std::string, Course*> allCourses;

    std::queue<Schedule*> scheduleQ;

  

    int topScore = INT_MAX;
    //std::unordered_map<std::string, Requirement*> fulfilledReqs;

    //Schedule* countCourses(std::vector<Course*> courses, Course* course, Schedule* schedule);
    void countCourses(Schedule* mySchedule);

    void runLogic();

    bool isReqFulfilled(Requirement* req, Schedule* schedule);

    void fulfillReq(Requirement* req, Schedule* schedule);

    int countUniqueFulfilled(Course* course, Schedule* schedule);

    void saveSchedule(Schedule* schedule);

    void editSchedule(Schedule* mySchedule);

    void printSchedule(Schedule *schedule);

    void printBestSchedules();

    void testcountUniqueFulfilled();
};

// Represents a potential course selection to fulfill requirements in the most efficient way. (See optimization.jpeg for visual)
struct Schedule{
    std::vector<Course*> courses;
    std::unordered_map<std::string, Requirement*> fulfilledReqs;
    int reqsFulfilled;

    // Default constructor
    Schedule() {
    }

    Schedule(const Schedule& other) 
        : courses(other.courses), 
          fulfilledReqs(other.fulfilledReqs),
          reqsFulfilled(other.reqsFulfilled)
    {}

    // Assignment operator
    Schedule& operator=(const Schedule& other) {
        if (this != &other) {
            courses = other.courses;
            fulfilledReqs = other.fulfilledReqs;
            reqsFulfilled = other.reqsFulfilled;
        }
        return *this;
    }

    bool isCourseInSchedule(Course* course);

    void addCourse(Course* course) {
        courses.push_back(course);

        // Sort the courses vector by course name in lexicographical order
        std::sort(courses.begin(), courses.end(), [](Course* a, Course* b) {
            return a->shortName < b->shortName;
        });
    }
    
};

#endif