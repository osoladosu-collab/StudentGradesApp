#include "FileWriter.h"
#include "Exceptions.h"

#include <fstream>
#include <iomanip>

void FileWriter::writeStudents(const std::string &filename,
                               const std::vector<Student> &students)
{
    std::ofstream out(filename, std::ios::out | std::ios::binary);
    if (!out) throw FileOpenError("Cannot write to file: " + filename);

    static char buffer[1 << 16];
    out.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    out << "Name Surname Final\n";

    for (const auto &s : students) {
        out << s.getFirstName() << ' '
            << s.getLastName() << ' '
            << std::fixed << std::setprecision(2)
            << s.getFinalGrade() << '\n';
    }
}
