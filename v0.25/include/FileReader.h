#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>
#include "Student.h"

class FileReader {
public:
    // Reads Name Surname HW... Exam
    static std::vector<Student> readStudents(const std::string &filename);
};

#endif
