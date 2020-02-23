#pragma once

#include <string>

class Student {
private:
    const std::string &lastName;
    const double avgGrade;

public:
    Student(const std::string &lastName, const double avgGrade) : lastName(lastName), avgGrade(avgGrade) {}

    const std::string &getLastName() const { return lastName; }

    double getAverageGrade() const { return avgGrade; }
};
