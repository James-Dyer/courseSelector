#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>
#include "Req.h"

struct Course {

    struct Req;

    std::string fullName;
    std::string shortName;
    int units;
    int uniqueness = -1;
    std::vector<Requirement*> requirements;
    
    Course(const std::string& fullName, const std::string& shortName, int units);

    void setUniqueness(int u);

    int getUniqueness() const;

    void addReq(Requirement* req){
        requirements.push_back(req);
    }
};

#endif