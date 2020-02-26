#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "files.h"

using namespace std;
using namespace std::filesystem;

void processFile(const string& path, vector<Student>& students, ofstream &bigfile);
void splitRecord(const string &str, string* words);

const int NUMBER_OF_FIELDS = 7;
const int NUMBER_OF_GRADES = 5;
const int PRECISION = 3;

vector<Student> processDirectory(const string& path) {
	vector<Student> students;

    int counter = 0;

    for (const directory_entry& entry : directory_iterator(path)) {
        if (!entry.is_directory()) {
            ifstream file(entry.path().string());
            int studentCount;
            file >> studentCount;
            counter += studentCount;
        }
    }

    ofstream bigfile("bigfile.csv");
    bigfile << counter << endl;

	for (const directory_entry& entry : directory_iterator(path)) {
		if (!entry.is_directory()) {
			processFile(entry.path().string(), students, bigfile);
		}
	}

    bigfile.close();

	return students;
}

void processFile(const string& path, vector<Student>& students, ofstream& bigfile) {
    ifstream stream(path);
	if (!stream.is_open()) {
		cerr << "Failed to read file " << path << endl;
		return;
	}

	string record;
	getline(stream, record); // discarding number of students
	string elements[NUMBER_OF_FIELDS];

	while (getline(stream, record)) {
		splitRecord(record, elements);
        bigfile << record << endl;
        cout << record << ",";

		double avgGrade = 0;
		for (int i = 1; i < NUMBER_OF_FIELDS - 1; i++) {
			avgGrade += stoi(elements[i]);
		}
		avgGrade /= NUMBER_OF_GRADES;
		cout << setprecision(PRECISION) << avgGrade << endl;

        if (elements[NUMBER_OF_FIELDS - 1] == "FALSE") {
            students.emplace_back(elements[0], avgGrade);
        }
	}

	stream.close();
}

void writeStudentsToFile(const std::vector<Student> &students, const std::string &path) {
	ofstream stream(path);
	if (!stream.is_open()) {
		cerr << "Couldn't write the data" << endl;
		return;
	}

	for (const Student& student : students) {
		stream << student.getLastName() << ","
			<< setprecision(PRECISION) << student.getAverageGrade() << endl;
	}

	stream.close();
}

void splitRecord(const string &str, string* words) {
	int offset = 0; // a starting position from which to look for
					// the next occurrence of the delimiter
	int index;      // index of the delimiter in the string
	for (int i = 0; i < NUMBER_OF_FIELDS; i++) {
		index = str.find(',', offset);
		words[i] = str.substr(offset, (index - offset));
		offset = index + 1;
	}
}
