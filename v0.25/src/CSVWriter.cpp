#include "CSVWriter.h"
#include <fstream>

CSVWriter::CSVWriter(const std::string &filename)
    : filename(filename) {}

void CSVWriter::writeHeader(const std::vector<std::string> &header) {
    if (headerWritten) return;

    std::ofstream out(filename, std::ios::app);
    for (size_t i = 0; i < header.size(); ++i) {
        out << header[i];
        if (i + 1 < header.size()) out << ",";
    }
    out << "\n";

    headerWritten = true;
}

void CSVWriter::appendRow(const std::vector<std::string> &row) {
    std::ofstream out(filename, std::ios::app);
    for (size_t i = 0; i < row.size(); ++i) {
        out << row[i];
        if (i + 1 < row.size()) out << ",";
    }
    out << "\n";
}
