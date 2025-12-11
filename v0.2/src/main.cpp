#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "Student.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileGenerator.h"
#include "Timer.h"
#include "Exceptions.h"

int main() {
    try {
        std::cout << "1) Generate files\n2) Process file\nChoice: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Generating files (10k, 100k, 1M, 10M)...\n";

            FileGenerator::generate("students10000.txt", 10000);
            FileGenerator::generate("students100000.txt", 100000);
            FileGenerator::generate("students1000000.txt", 1000000);
            FileGenerator::generate("students10000000.txt", 10000000);

            std::cout << "Done.\n";
            return 0;
        }

        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;

        Timer total;
        total.reset();

        // ------------------- READ -------------------
        Timer t;
        t.reset();
        auto students = FileReader::readFile(filename);
        double read_time = t.elapsed();
        std::cout << "Read " << students.size() << " students in "
                  << read_time << " s\n";

        // ------------------- SORT -------------------
        t.reset();
        std::sort(students.begin(), students.end(),
            [](const Student &a, const Student &b) {
                return a.getFirstName() < b.getFirstName();
            }
        );
        double sort_time = t.elapsed();
        std::cout << "Sorted in " << sort_time << " s\n";

        // ------------------- SPLIT -------------------
        t.reset();
        std::vector<Student> passed;
        std::vector<Student> failed;
        passed.reserve(students.size() / 2);
        failed.reserve(students.size() / 2);

        for (auto &s : students) {
            if (s.getFinalGrade() >= 5.0)
                passed.push_back(std::move(s));
            else
                failed.push_back(std::move(s));
        }
        double split_time = t.elapsed();
        std::cout << "Split in " << split_time << " s\n";

        // ------------------- WRITE -------------------
        t.reset();
        FileWriter::writeStudents("passed_" + filename, passed);
        FileWriter::writeStudents("failed_" + filename, failed);
        double write_time = t.elapsed();
        std::cout << "Wrote output files in " << write_time << " s\n";

        double total_time = total.elapsed();
        std::cout << "TOTAL TIME: " << total_time << " s\n";

        // ------------------- LOG TO CSV -------------------
        std::ofstream csv("results/timings.csv", std::ios::app);
        if (csv) {
            csv << filename << ","
                << students.size() << ","
                << "vector,"      // container type for v0.2
                << read_time << ","
                << sort_time << ","
                << split_time << ","
                << write_time << ","
                << total_time
                << "\n";
        }
    }
    catch (const FileOpenError &e) {
        std::cerr << "File error: " << e.what() << '\n';
        return 2;
    }
    catch (const ParseError &e) {
        std::cerr << "Parse error: " << e.what() << '\n';
        return 3;
    }
    catch (const GenerationError &e) {
        std::cerr << "Generation error: " << e.what() << '\n';
        return 4;
    }
    catch (const std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        return 5;
    }
    catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
        return 99;
    }

    return 0;
}
