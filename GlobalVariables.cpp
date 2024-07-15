// GlobalVariables.cpp
#include "GlobalVariables.h"

std::unordered_map<std::string, Course*> allCourses;
Logic globalData;


//Finds a course in allCourses and returns its pointer
Course* findCourse(const std::string& shortName) {
    auto it = allCourses.find(shortName); // Find the iterator for the key
    if (it != allCourses.end()) { // Check if the key was found
        return it->second; // Return a pointer to the Course object
    } else {
        std::cerr << "Course not found in allCourses" << std::endl;
        return nullptr; // Return nullptr if the key was not found
    }
}

// Count the number of occurrences of shortName in allCourses
bool checkCourseUniqueness(const std::string& shortName) {
    int count = 0;
    for (const auto& pair : allCourses) {
        if (pair.first == shortName) {
            count++;
        }
    }
    return count == 0;
}

void printCourseInfo(){
    for (size_t i = 0; i < globalData.requirements.size(); i++) {
        std::cout << globalData.requirements[i]->name << std::endl;
        for (size_t j = 0; j < globalData.requirements[i]->courses.size(); j++) {
            std::cout << "\t" << globalData.requirements[i]->courses[j]->shortName << std::endl;
        }
        std::cout << "\n";
    }
}

//clears allCourses
void cleanMemory(){
    for (auto& entry : allCourses) {
        delete entry.second; 
    }
    allCourses.clear(); 
}