#include "FileWriter.h"
#include "Exceptions.h"
#include <fstream>
#include <iomanip>

void FileWriter::writeStudents(const std::string &filename,
                               const std::vector<Student> &students) {
    std::ofstream out(filename);
    if (!out) throw FileOpenError("Cannot write to file: " + filename);

    out << std::left << std::setw(15) << "FirstName"
        << std::setw(15) << "LastName"
        << std::setw(10) << "Final\n";

    out << std::string(40, '-') << "\n";

    for (const auto &s : students) {
        out << std::left << std::setw(15) << s.getFirstName()
            << std::setw(15) << s.getLastName()
            << std::fixed << std::setprecision(2)
            << std::setw(10) << s.getFinalGrade()
            << "\n";
    }
}

