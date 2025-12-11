#include "FileGenerator.h"
#include "Exceptions.h"
#include <fstream>
#include <random>

void FileGenerator::generate(const std::string &filename, long count) {
    std::ofstream out(filename, std::ios::out | std::ios::binary);
    if (!out) throw GenerationError("Cannot create file: " + filename);

    static char buffer[1 << 16];
    out.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> grade(0, 10);

    for (long i = 1; i <= count; ++i) {
        out << "Name" << i << ' ' << "Surname" << i;
        for (int j = 0; j < 5; ++j) out << ' ' << grade(gen);
        out << ' ' << grade(gen) << '\n';
        if (!out) throw GenerationError("Write failed while generating: " + filename);
    }
}
