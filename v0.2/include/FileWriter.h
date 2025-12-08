#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <vector>
#include <string>
#include "Student.h"

class FileWriter {
public:
    static void writeStudents(const std::string &filename,
                              const std::vector<Student> &students);
};

#endif
