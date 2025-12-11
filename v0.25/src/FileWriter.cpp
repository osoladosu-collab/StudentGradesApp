#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

void FileWriter::writeStudents(const std::string &filename,
                               const std::vector<Student> &students)
{
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("Failed to open output file: " + filename);
    }

    for (const auto &s : students) {
        out << s.getFirstName() << " "
            << s.getLastName() << " "
            << s.getFinalGrade()
            << "\n";
    }
}
