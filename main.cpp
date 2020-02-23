#include <iostream>
#include <string>
#include "files.h"
#include "table.h"

using namespace std;

int main() {
    string path;
    cout << "Path to directory: ";
    cin >> path;

    auto allStudents = processDirectory(path);
    auto studentsReceivingScholarship = getScholarshipReceivers(allStudents);

    double minGradeForScholarship = getMinimumAvgGradeForScholarship(studentsReceivingScholarship);
    printf("Minimum average grade to receive scholarship: %.3f", minGradeForScholarship);

    writeStudentsToFile(studentsReceivingScholarship, "rating.csv");
}
