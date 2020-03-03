#include <iostream>
#include <string>
#include <filesystem>
#include "files.h"
#include "table.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string path;
    cout << "Path to directory: ";
    cin >> path;

    try {
        auto allStudents = processDirectory(path);
        auto studentsReceivingScholarship = getScholarshipReceivers(allStudents);

        double minGradeForScholarship = getMinimumAvgGradeForScholarship(studentsReceivingScholarship);
        printf("\nMinimum average grade to receive scholarship: %.3f", minGradeForScholarship);

        writeStudentsToFile(studentsReceivingScholarship, "rating.csv");
    }
    catch (filesystem::filesystem_error &e) {
        cerr << "Couldn't process the specified directory" << endl;
    }
}
