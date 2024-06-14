#ifndef COURSE_H
#define COURSE_H

#include <unordered_set>
#include <string>


struct Course {
    std::string fullName;
    std::string shortName;
    int units;
    int uniqueness = -1;
    
    Course(const std::string& fullName, const std::string& shortName, int units);

    void setUniqueness(int u);

    int getUniqueness() const;
};

#endif