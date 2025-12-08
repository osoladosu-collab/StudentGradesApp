#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <vector>
#include <string>
#include "Student.h"

class FileWriter {
public:
    template <typename Container>
    static void write(const std::string &filename, const Container &students);
};

#endif
