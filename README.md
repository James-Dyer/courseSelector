# CourseSelector
CourseSelector is a tool designed to assist UC Merced students in determining the most efficient set of courses to fulfill their general education requirements. By parsing the university's requirement list and analyzing available courses, the algorithm generates optimized schedules, ensuring that all requirements are met with the least number of classes.

## Features
- **Requirement Parsing**: Reads and processes UC Merced's General Education requirements from input files.
- **Course Selection**: Identifies courses that fulfill multiple requirements and ensures the most efficient schedule.
- **Schedule Optimization**: Outputs the optimal and alternative schedules based on the courses selected.
- **Duplicate Prevention**: Eliminates duplicate or suboptimal schedules to ensure clarity.
- **Performance Metrics**: Displays execution time for the algorithm to highlight efficiency.

## How It Works
#### Workflow
- **Input Requirements**: A list of requirements is read from files, and their metadata is extracted.
- **Course Database**: Builds a database of all courses and their associated requirements.
- **Schedule Generation**:
  - Starts with an empty schedule.
  - Iteratively adds courses, ensuring that no duplicate requirements are fulfilled unnecessarily.
- **Optimization**: Compares all potential schedules to find the one that satisfies all requirements with the least number of courses.
- **Output Results**:
  - Prints optimal schedules to the console.
  - Saves the best schedules to a file named best_schedules.txt.
  
## Installation and Usage
#### Requirements
- A C++ compiler that supports C++17 or later.
- Input files structured with the UC Merced general education requirements and courses.
  - (Can be copied and pasted directly from the UC Merced Gen Ed. Requirement Listing website)
#### Compilation
- Use any standard C++ compiler (e.g., GCC, Clang, MSVC) to compile the project. Example with g++:
`g++ -std=c++17 -o CourseSelector main.cpp FileIO.cpp GlobalVariables.cpp Logic.cpp Schedule.cpp`
#### Running the program
`./courseSelector`
Place input files in the same directory or provide paths in the code.

#### Example Output
`best_schedules.txt:`
```
Optimal schedule found with 2 courses.
Courses:
COURSE101
COURSE102
----------------------------------------
```

## Performance
The algorithm is designed to handle large input files efficiently by leveraging breadth-first search and hash-based tracking of unique schedules. Execution time is logged for performance monitoring.

## Future Improvements:
- **GUI Integration**: Provide a user-friendly interface for course selection.
- **Dynamic Input Parsing**: Support for real-time requirement updates.
- **Advanced Optimization**: Incorporate additional constraints like time slots and prerequisites.

## License
This project is licensed under the MIT License. See `LICENSE` for details.
