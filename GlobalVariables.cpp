// GlobalVariables.cpp
#include "GlobalVariables.h"

Logic globalData;


//Finds a course in the specidied umap and returns its pointer
Course* findCourse(const std::string& shortName, const std::unordered_map<std::string, Course*>& map) {
    auto it = map.find(shortName); // Find the iterator for the key
    if (it != map.end()) { // Check if the key was found
        return it->second; // Return a pointer to the Course object
    } else {
        std::cerr << "Course not found in umap" << std::endl;
        return nullptr; // Return nullptr if the key was not found
    }
}

// Count the number of occurrences of shortName in allCourses
bool checkCourseUniqueness(const std::string& shortName, const std::unordered_map<std::string, Course*>& map) {
    int count = 0;
    for (const auto& pair : map) {
        if (pair.first == shortName) {
            count++;
        }
    }
    return count == 0;
}

void printCourseInfo(){
    // For printing Requirements -> Courses
        // std::cout << "Requirements -> Courses:\n" << std::endl;
        // for (size_t i = 0; i < globalData.requirements.size(); i++) {
        //     std::cout << globalData.requirements[i]->name << std::endl;
        //     for (size_t j = 0; j < globalData.requirements[i]->courses.size(); j++) {
        //         std::cout << "\t" << globalData.requirements[i]->courses[j]->shortName << std::endl;
        //     }
        //     std::cout << "\n";
        // }

    // For printing Courses -> Requirements
        for (size_t i = 0; i < globalData.courses.size(); i++) {
            std::cout << globalData.courses[i]->shortName << std::endl;
            for (size_t j = 0; j < globalData.courses[i]->requirements.size(); j++) {
                std::cout << "\t" << globalData.courses[i]->requirements[j]->name << std::endl;
            }
            std::cout << "\n";
        }
}

void printUMap(const std::unordered_map<std::string, Course*>& map) {
    for (const auto& pair : map) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second->fullName << std::endl;
    }
}

//clears allCourses
void cleanMemory(){
    for (auto& entry : globalData.allCourses) {
        delete entry.second; 
    }
    globalData.allCourses.clear(); 
}