#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "files.h"

using namespace std;
using namespace std::filesystem;

void processFile(const string& path, vector<Student> students);
string* splitRecord(const string &str);

vector<Student> processDirectory(const string& path) {
	vector<Student> students;

	for (directory_entry entry : directory_iterator(path)) {
		if (!entry.is_directory()) {
			processFile(entry.path().string(), students);
		}
	}

	return students;
}

void processFile(const string& path, vector<Student> students) {
	ifstream stream(path);
	if (!stream.is_open()) {
		cerr << "Failed to read file " << path;
		return;
	}
	
	string record;
	getline(stream, record);
	int records = stoi(record); // useless?

	while (getline(stream, record)) {
		string* elements = splitRecord(record);
		// TODO

		//students.push_back(Student(elements[0], avgGrade)); 
		delete[] elements;
	}

	stream.close();
}

void writeStudentsToFile(const std::vector<Student> &students, const std::string &path) {
	// TODO
}

string* splitRecord(const string &str) {
	string* words = new string[7];
	int offset = 0; // a starting position from which to look for 
					// the next occurence of 'delimiter'
	int index;      // index of a 'delimiter' char in a string
	for (int i = 0; i < 7; i++) {
		index = str.find(',', offset);
		words[i] = str.substr(offset, (index - offset));
		offset = index + 1;
	}
	return words;
}