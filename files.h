#pragma once

#include <vector>
#include <string>
#include "student.h"

std::vector<Student> processDirectory(const std::string &path);
void writeStudentsToFile(const std::vector<Student> &students, const std::string &path);
