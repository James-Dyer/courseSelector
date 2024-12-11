#include "Logic.h"
void Logic::runLogic() { 
    std::cout << "Running... " << std::endl;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    Schedule* initialSchedule = new Schedule();
    scheduleQ.push(initialSchedule);

    while (!scheduleQ.empty()) {
        //std::cout << "\nPopping schedule: " << scheduleQ.front() << std::endl;
        //skip if a better optimal schedule is already found
        if (scheduleQ.front()->courses.size() > topScore) {
            //std::cout << "schedule skipped: schedule.courses = " << scheduleQ.front()->courses.size() << " > topScore: " << topScore << std::endl;
            scheduleQ.pop();
            continue;
        }
        
        //std::cout << "Is " << scheduleQ.front()->reqsFulfilled << " && " << scheduleQ.front()->fulfilledReqs.size() << " >= " << requirements.size() << " or " << courses.size() << " <= " << scheduleQ.front()->courses.size() << std::endl;
        countCourses(scheduleQ.front());
        scheduleQ.pop();
    };

    //TODO: garbage collector function
    printBestSchedules();

    // End timing
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Finished (" << "\033[35m" << duration << "ms" << "\033[0m" << ")" << std::endl;
    std::cout << "Results stored in " << "\033[0m" << "'best_schedules.txt'" << "\033[0m" << std::endl;
    
    return;
}

void Logic::countCourses(Schedule* mySchedule) {

    // Base case: if all requirements are fulfilled or no more courses to process, return the schedule
    if (mySchedule->fulfilledReqs.size() >= requirements.size()) {
        saveSchedule(mySchedule);
        return;
    } else if (courses.size() < mySchedule->courses.size()) {
        std::cerr << "Error: All requirments cannot be satisfied with this selection of courses." << std::endl;
        //return;
    }
    
    editSchedule(mySchedule);
}

std::set<std::string> uniqueSchedules;

//MAKE A NEW SCHEDULE FOR EACH EDIT AND ENQUEUE THAT NEW SCEDULE
void Logic::editSchedule(Schedule* mySchedule) {
    for (Course* course : courses) {
        // Check if the course is already in the schedule
        if (mySchedule->isCourseInSchedule(course)) {
            continue;  // Skip to the next course if it's already in the schedule
        }

        // Create a new schedule by copying the current one
        Schedule* newSchedule = new Schedule(*mySchedule);

        // Add the course to the new schedule (will also sort the courses)
        newSchedule->addCourse(course);

        // Create a string representation of the schedule
        std::ostringstream oss;
        for (Course* c : newSchedule->courses) {
            oss << c->shortName << ",";
        }
        std::string scheduleStr = oss.str();

        // Check if this schedule has already been processed
        if (uniqueSchedules.find(scheduleStr) != uniqueSchedules.end()) {
            delete newSchedule;  // Avoid memory leak
            continue;  // Skip processing this duplicate schedule
        }
        // If not a duplicate, add it to the set of unique schedules
        uniqueSchedules.insert(scheduleStr);


        // Update the number of fulfilled requirements with the unique ones from the new course
        newSchedule->reqsFulfilled += countUniqueFulfilled(course, newSchedule);

        // Recursively process the new schedules in BFS style
        scheduleQ.push(newSchedule);
    }
    delete mySchedule;
}


//count how many new reqs this course fulfills and then marks them as fulfilled
int Logic::countUniqueFulfilled(Course* course, Schedule* schedule) {
    int count = 0;
    for (int i = 0; i < course->requirements.size(); i++) {
        if (!isReqFulfilled(course->requirements[i], schedule)) {
            count++;
            fulfillReq(course->requirements[i], schedule);
        }
    }
    return count;
}

// Check if the requirement exists in fulfilledReqs
bool Logic::isReqFulfilled(Requirement* req, Schedule* schedule) {

    for (const auto& pair : schedule->fulfilledReqs) {
    }
    auto it = schedule->fulfilledReqs.find(req->name);
    return it != schedule->fulfilledReqs.end();
}

//set a requirement as fulfilled
void Logic::fulfillReq(Requirement* req, Schedule* schedule) {
    schedule->fulfilledReqs[req->name] = req;
}

//check if schedule is equal to or better than optimal and if not dont save it
#include <fstream>

void Logic::saveSchedule(Schedule* schedule) {
    int newScore = schedule->courses.size();

    // Open file in append mode
    std::ofstream outFile("best_schedules.txt", std::ios::app);

    if (topScore > newScore) {
        //std::cout << "New optimal schedule found: " << newScore << " \n";
        topScore = newScore;

        // Clear the file and write the new optimal schedule
        outFile.close(); // Close the current append stream
        outFile.open("best_schedules.txt", std::ios::trunc); // Reopen in truncate mode to clear contents
        outFile << "Optimal schedule found with " << newScore << " courses. \n";
        outFile << "Courses:\n";
        for (Course* course : schedule->courses) {
            outFile << course->shortName << "\n";
        }
        outFile << "----------------------------------------\n";
    } else if (topScore == newScore) {
        //std::cout << "equal schedule found: " << newScore << " \n";

        // Append the equal schedule to the file
        outFile << "Alternate optimal schedule found: \n";
        outFile << "Courses:\n";
        for (Course* course : schedule->courses) {
            outFile << course->shortName << "\n";
        }
        outFile << "----------------------------------------\n";
    } else {
        // Schedule is not optimal and therefore not saved
        //std::cout << "this schedule is not optimal. \n";
    }

    outFile.close(); // Close the file stream
}


bool Schedule::isCourseInSchedule(Course* course) {
        bool found = false;
        for (int i = 0; i < courses.size(); i++) {
            if (course == courses[i]) found = true;
        }
        return found;
}

void Logic::printSchedule(Schedule* schedule) {
    for (Course* course : schedule->courses) {
        std::cout << course->shortName << ", ";
    }
    std::cout << std::endl;
}

void Logic::printBestSchedules() {
    for (Schedule* schedule: bestSchedules) {
        printSchedule(schedule);
    }
    std::cout << "--------" << std::endl;
}

//interate and find the most efficent classes, save to a list
//call this algorithm for each class, removing thier respective requirements that they already fulfill
//return the many combinations of classes