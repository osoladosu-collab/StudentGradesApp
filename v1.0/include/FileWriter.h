#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <fstream>
#include <string>
#include <stdexcept>
#include "Student.h"

class FileWriter {
public:
    template <typename Container>
    static void write(const std::string& filename, const Container& students) {
        std::ofstream out(filename);
        if (!out) {
            throw std::runtime_error("Failed to write: " + filename);
        }

        out << "FirstName,LastName,FinalGrade\n";

        for (const auto& s : students) {
            out << s.getName() << ","
                << s.getSurname() << ","
                << s.getFinalGrade() << "\n";
        }
    }
};

#endif
