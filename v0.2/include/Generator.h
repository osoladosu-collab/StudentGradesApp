#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <fstream>
#include <stdexcept>

class Generator {
public:
    static void generateFile(const std::string& filename, size_t count);
};

#endif
