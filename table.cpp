#include <vector>
#include <algorithm>
#include <cmath>
#include "student.h"

bool compareStudentsForScholarship(const Student &first, const Student &second);

std::vector<Student> getScholarshipReceivers(const std::vector<Student> &students) {
    std::vector<Student> receivers(students);
    std::sort(receivers.begin(), receivers.end(), compareStudentsForScholarship);

    int scholarshipCapacity = (int) std::round(receivers.size() * 0.4);
    return std::vector<Student>(receivers.begin(), receivers.begin() + scholarshipCapacity);
}

bool compareStudentsForScholarship(const Student &first, const Student &second) {
    return first.getAverageGrade() > second.getAverageGrade();
}

double getMinimumAvgGradeForScholarship(const std::vector<Student> &scholarshipReceivers) {
    return scholarshipReceivers.back().getAverageGrade();
}
