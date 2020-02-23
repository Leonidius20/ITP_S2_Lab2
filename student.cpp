#include <string>
#include "student.h"

Student::Student(std::string lastName, int grades[5]) {
	this->lastName = lastName;
	int sumOfGrades = 0;
	for (int i = 0; i < 5; i++) {
		this->grades[i] = grades[i];
		sumOfGrades += grades[i];
	}
	this->avgGrade = sumOfGrades / 5;
}