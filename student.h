#pragma once

#include <string>

class Student {
private:
    std::string lastName;
    double avgGrade;

public:
    Student(const std::string &lastName, const double avgGrade) {
        this->lastName = lastName;
        this->avgGrade = avgGrade;
    }

    const std::string &getLastName() const { return lastName; }

    double getAverageGrade() const { return avgGrade; }
};
