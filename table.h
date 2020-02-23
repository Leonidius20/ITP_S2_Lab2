#pragma once

#include <vector>
#include "student.h"

std::vector<Student> getScholarshipReceivers(const std::vector<Student> &students);

double getMinimumAvgGradeForScholarship(const std::vector<Student> &scholarshipReceivers);
