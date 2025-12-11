#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

void FileWriter::writeStudents(const std::string &filename,
                               const std::vector<Student> &students) {
    std::ofstream out(filename);
    if (!out)
        throw std::runtime_error("ERROR: Cannot write to file " + filename);

    // Buffer for speed
    static char buffer[1 << 16];
    out.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    for (const auto &s : students) {
        out << s.getFirstName() << " "
            << s.getLastName() << " "
            << s.getFinalGrade() << "\n";
    }
}
