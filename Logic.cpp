#include <iostream>
#include <vector>
#include <stack>
#include "Logic.h"

//Find the list of classes that are the most efficient
//Takes in a list of classes that are already chosen

int Logic::findBestClasses(std::vector<Course*> prechosenCourses){
    for (const auto& coursePair : globalData.allCourses) {
        // Your logic here using coursePair
        // coursePair.first gives you the key (std::string)
        // coursePair.second gives you the value (Course*)

        //for each course, check how many requirements it contains that aren't already fulfilled
        // TODO: update Course.h so they all carry thier requirements
        // store the fulfilled requirements in a list

    }
    return 0;
}

bool Logic::isReqFulfilled(Requirement* req) {
    // Check if the requirement exists in fulfilledReqs
    auto it = fulfilledReqs.find(req->name);
    return it != fulfilledReqs.end();
}


//sets the requirement parameter as fulfilled
void Logic::fulfillRequirement(Requirement* req) {
    fulfilledReqs[req->name] = req;
}

//interate and find the most efficent classes, save to a list
//call this algorithm for each class, removing thier respective requirements that they already fulfill
//return the many combinations of classes