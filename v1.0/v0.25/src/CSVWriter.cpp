#include "CSVWriter.h"

CSVWriter::CSVWriter(const std::string &filename) {
    file.open(filename);
}

CSVWriter::~CSVWriter() {
    if (file.is_open())
        file.close();
}

void CSVWriter::writeHeader(const std::vector<std::string> &header) {
    for (size_t i = 0; i < header.size(); i++) {
        file << header[i];
        if (i + 1 < header.size()) file << ",";
    }
    file << "\n";
}

void CSVWriter::appendRow(const std::vector<std::string> &row) {
    for (size_t i = 0; i < row.size(); i++) {
        file << row[i];
        if (i + 1 < row.size()) file << ",";
    }
    file << "\n";
}
