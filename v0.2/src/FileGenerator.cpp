#include "FileGenerator.h"
#include <fstream>
#include <random>
#include <stdexcept>

void FileGenerator::generate(const std::string &filename, long count) {
    std::ofstream out(filename);
    if (!out)
        throw std::runtime_error("ERROR: Cannot create file " + filename);

    // Optional: speed up large file writing
    static char buffer[1 << 16]; // 64KB
    out.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> grade(1, 10);

    for (long i = 1; i <= count; i++) {
        out << "Name" << i << " "
            << "Surname" << i << " ";

        for (int j = 0; j < 5; j++)
            out << grade(gen) << " ";

        out << grade(gen) << "\n"; // exam
    }
}
