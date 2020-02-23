#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "files.h"

using namespace std;
using namespace std::filesystem;

void processFile(const string& path, vector<Student> students);
string* splitRecord(string str);

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
	int records;
	stream >> records;

	string record;
	while (stream.peek() != EOF) {
		getline(stream, record);
		string* elements = splitRecord(record);
		

		//students.push_back(Student(elements[0], avgGrade)); 
	}

	stream.close();
}

void writeStudentsToFile(const std::vector<Student>& students, const std::string& path) {
	// TODO
}

string* splitRecord(string str) {
	string words[7];
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