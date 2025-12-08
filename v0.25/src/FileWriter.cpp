#include "FileWriter.h"
#include <fstream>
#include <stdexcept>

template <typename Container>
void FileWriter::write(const std::string &filename, const Container &students) {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("ERROR: Cannot write file " + filename);

    for (const auto &s : students) {
        out << s.getFirstName() << " "
            << s.getLastName() << " "
            << s.getFinalGrade() << "\n";
    }
}
template void FileWriter::write(const std::string&, const std::vector<Student>&);
template void FileWriter::write(const std::string&, const std::list<Student>&);
template void FileWriter::write(const std::string&, const std::deque<Student>&);
