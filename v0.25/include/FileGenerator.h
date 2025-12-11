#ifndef FILEGENERATOR_H
#define FILEGENERATOR_H

#include <string>

class FileGenerator {
public:
    // generate a single file with 'count' records
    // each record: NameX SurnameX hw1 hw2 hw3 hw4 hw5 exam
    static void generateFile(const std::string &filename, long count);
};

#endif // FILEGENERATOR_H