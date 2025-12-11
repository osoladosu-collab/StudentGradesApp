#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <string>
#include <vector>
#include <fstream>

class CSVWriter {
public:
    explicit CSVWriter(const std::string &filename);
    ~CSVWriter();

    void writeHeader(const std::vector<std::string> &header);
    void appendRow(const std::vector<std::string> &row);

private:
    std::ofstream file;
};

#endif
