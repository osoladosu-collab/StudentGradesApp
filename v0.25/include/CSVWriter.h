#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <fstream>
#include <string>
#include <vector>

class CSVWriter {
private:
    std::ofstream out;

public:
    CSVWriter(const std::string &filename) {
        out.open(filename);
    }

    ~CSVWriter() {
        if (out.is_open()) out.close();
    }

    void writeRow(const std::vector<std::string> &row) {
        for (size_t i = 0; i < row.size(); i++) {
            out << row[i];
            if (i + 1 < row.size()) out << ",";
        }
        out << "\n";
    }

    bool isOpen() const { return out.is_open(); }
};

#endif
