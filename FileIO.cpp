#include "FileIO.h"

//trims whitespace at the beginning of the string s
void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void readCoursesFromFile(const std::string& filename) {
//Parse the requirement name out off the file name
    std::size_t pos = filename.find_last_of("/"); 
    std::string shortReqName = filename.substr(pos + 1); 
    shortReqName = shortReqName.substr(0, shortReqName.size() - 4);
    std::ifstream file(filename);
    std::string line;

    //create new requirement
    Requirement* myReq = new Requirement(shortReqName);
    globalData.requirements.push_back(myReq);

    while (std::getline(file, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') {
                line.erase(line.size() - 1); 
        }
        if (line.empty()) {
                continue; // Skip processing empty lines
        }

        ltrim(line);

        std::string shortName;
        std::string fullName;
        char unitsChar = line.back();

        // Extract the short name and units from the course name
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            shortName = line.substr(0, colonPos);
            size_t colonPos2 = line.substr(colonPos + 1).find(':');
            if (colonPos2 != std::string::npos) {
                fullName = line.substr(colonPos + 2, colonPos2 - 7);
                //unitsStr = line.substr(colonPos2 + 2);
                
            } else {
                throw std::logic_error("Input file parsing failed: second colon not found.\n");
            }
        } else {
            throw std::logic_error("Input file parsing failed: first colon not found.\n");
        }

        // Convert unitsStr to an integer
        int units = unitsChar - '0';

        // Create a new Course object and add it to the myReq
        //we wanna add reqs to courses
        if (checkCourseUniqueness(shortName, globalData.allCourses)) {
            Course* newCourse = new Course(fullName, shortName, units);
            globalData.allCourses.emplace(shortName, newCourse);
            globalData.courses.push_back(newCourse);
            //myReq->addCourse(newCourse);
            newCourse->addReq(myReq);
        } else {
            Course* myCourse = findCourse(shortName, globalData.allCourses);
            //myReq->addCourse(myCourse);
            myCourse->addReq(myReq);
        }
    }

    file.close();
}