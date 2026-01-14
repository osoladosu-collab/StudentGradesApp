#include "FileGenerator.h"
#include "Exceptions.h"
#include <fstream>
#include <random>
#include <iostream>

void FileGenerator::generateFile(const std::string &filename, long count) {
    std::ofstream out(filename);
    if (!out) throw GenerationError("Cannot open file for writing: " + filename);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> grade(1, 10);

    // write lines: Name{i} Surname{i} hw1 hw2 hw3 hw4 hw5 exam
    for (long i = 1; i <= count; ++i) {
        out << "Name" << i << ' ' << "Surname" << i;
        for (int j = 0; j < 5; ++j) out << ' ' << grade(gen);
        out << ' ' << grade(gen) << '\n';
    }
    if (!out) throw GenerationError("Write error while generating file: " + filename);
}
