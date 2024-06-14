#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include <iostream>
#include <algorithm>

#include "GlobalVariables.h"



void ltrim(std::string& s);

void readCoursesFromFile(const std::string& filename);

#endif
