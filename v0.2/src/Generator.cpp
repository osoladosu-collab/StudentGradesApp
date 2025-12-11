#include "Generator.h"
#include <iostream>

void Generator::generateFile(const std::string& filename, size_t count) {
    std::ofstream out(filename);
    if (!out.is_open())
        throw std::runtime_error("Failed to open output file: " + filename);

    out << "Name Surname HW1 HW2 HW3 HW4 HW5 Exam\n";

    for (size_t i = 1; i <= count; i++) {
        out << "Name"   << i << " "
            << "Surname"<< i << " "
            << 8 << " " << 7 << " " << 9 << " " << 10 << " " << 6 << " "
            << 9 << "\n";  
    }

    out.close();
    std::cout << "Generated: " << filename 
              << " (" << count << " students)\n";
}
