#include "Course.h"

Course::Course(const std::string& fullName, const std::string& shortName, int units) {
    this->fullName = fullName;
    this->shortName = shortName;
    this->units = units;
}

void Course::setUniqueness(int u) {
    this->uniqueness = u;
}

int Course::getUniqueness() const { 
    return this->uniqueness;
}