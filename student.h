#pragma once

#include <string>

class Student {
	std::string lastName;
	int grades[5];
	double avgGrade;

public:
	Student() = default;
	Student(std::string lastName, int grades[5]);
	double getAverageGrade() { return avgGrade; }
};