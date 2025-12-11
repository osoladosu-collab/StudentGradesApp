#include "Person.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

// -----------------------------------------------------------
// Helper: Print table header
// -----------------------------------------------------------
void printHeader() {
    std::cout << std::left << std::setw(12) << "Name"
              << std::setw(12) << "Surname"
              << std::right << std::setw(14) << "Final (Avg.)"
              << " | " << std::setw(12) << "Final (Med.)" << "\n";
    std::cout << std::string(12 + 12 + 14 + 3 + 12, '-') << "\n";
}

// -----------------------------------------------------------
// Helper: Split whitespace-separated tokens
// -----------------------------------------------------------
std::vector<std::string> splitWS(const std::string &line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string tok;
    while (iss >> tok) tokens.push_back(tok);
    return tokens;
}

// -----------------------------------------------------------
// Detect .txt files EXCLUDING DIRECTORIES
// -----------------------------------------------------------
std::vector<fs::path> findTextFiles() {
    std::vector<fs::path> out;
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_regular_file()) {                   // IGNORE DIRECTORIES
            if (entry.path().extension() == ".txt") {     // Only .txt
                out.push_back(entry.path());
            }
        }
    }
    std::sort(out.begin(), out.end());
    return out;
}

// -----------------------------------------------------------
// Detect number of HW columns from file header
// -----------------------------------------------------------
int detectHomeworkCountInHeader(const fs::path &p) {
    std::ifstream ifs(p.string());
    if (!ifs) return -1;

    std::string headerLine;
    std::getline(ifs, headerLine);

    auto tokens = splitWS(headerLine);

    // Expected: Name Surname HW1 ... HWn Exam
    if ((int)tokens.size() < 3) return -1;

    int hwCount = static_cast<int>(tokens.size()) - 3;
    if (hwCount < 0) hwCount = 0;

    return hwCount;
}

// -----------------------------------------------------------
// Read students from file using operator>> overload
// -----------------------------------------------------------
bool readStudentsFromFile(const fs::path &p, std::vector<Person> &students) {
    int hwCount = detectHomeworkCountInHeader(p);
    if (hwCount < 0) return false;

    Person::fileHomeworkCount = hwCount;

    std::ifstream ifs(p.string());
    if (!ifs) return false;

    // Skip header
    std::string header;
    std::getline(ifs, header);

    Person tmp;
    while (ifs >> tmp) {
        students.push_back(tmp);
    }
    return true;
}

// -----------------------------------------------------------
// Main Program
// -----------------------------------------------------------
int main() {
    std::cout << "Student Grades App (C++17)\n";
    std::cout << "--------------------------------\n";

    std::vector<Person> students;

    while (true) {
        std::cout << "\nChoose source:\n";
        std::cout << "  1) List .txt files in current folder and choose one to load\n";
        std::cout << "  2) Manual input (enter students by keyboard)\n";
        std::cout << "  3) Random generate students\n";
        std::cout << "  4) Exit\n";
        std::cout << "Select option (1-4): ";

        int opt;
        if (!(std::cin >> opt)) return 0;

        // ----------------------------------------
        // Option 1: Load from file
        // ----------------------------------------
        if (opt == 1) {
            auto files = findTextFiles();

            if (files.empty()) {
                std::cout << "No .txt files found in current directory.\n";
                continue;
            }

            std::cout << "\nFound .txt files:\n";
            for (size_t i = 0; i < files.size(); ++i) {
                std::cout << "  " << (i + 1) << ") "
                          << files[i].filename().string() << "\n";
            }

            std::cout << "Choose file number: ";
            size_t fidx;
            std::cin >> fidx;

            if (fidx < 1 || fidx > files.size()) {
                std::cout << "Invalid selection.\n";
                continue;
            }

            students.clear();
            bool ok = readStudentsFromFile(files[fidx - 1], students);
            if (!ok) {
                std::cout << "Failed to read file.\n";
                continue;
            }

            std::cout << "Loaded " << students.size()
                      << " students from " << files[fidx - 1].filename() << "\n";
        }

        // ----------------------------------------
        // Option 2: Manual input
        // ----------------------------------------
        else if (opt == 2) {
            students.clear();
            std::cout << "\nManual input mode.\n";

            while (true) {
                Person p;
                p.readFromConsole();
                students.push_back(p);

                std::cout << "Add another student? (y/n): ";
                char c; std::cin >> c;
                if (c != 'y' && c != 'Y') break;
            }
        }

        // ----------------------------------------
        // Option 3: Random data
        // ----------------------------------------
        else if (opt == 3) {
            students.clear();
            std::cout << "Random generation mode.\n";

            int n, hw;
            std::cout << "Number of students to generate: ";
            std::cin >> n;

            std::cout << "Number of homework assignments per student: ";
            std::cin >> hw;

            for (int i = 0; i < n; ++i)
                students.push_back(Person::randomPerson(hw));

            std::cout << "Generated " << students.size() << " students.\n";
        }

        // ----------------------------------------
        // Option 4: Exit
        // ----------------------------------------
        else break;

        // ----------------------------------------
        // Check
        // ----------------------------------------
        if (students.empty()) {
            std::cout << "No students loaded. Returning to menu.\n";
            continue;
        }

        // ----------------------------------------
        // Sorting
        // ----------------------------------------
        std::cout << "\nSort by: 1) First name  2) Surname. Choose (1/2): ";
        int sOpt;
        std::cin >> sOpt;

        if (sOpt == 1) {
            std::sort(students.begin(), students.end(),
                      [](const Person &a, const Person &b) {
                          return a.getFirstName() < b.getFirstName();
                      });
        } else {
            std::sort(students.begin(), students.end(),
                      [](const Person &a, const Person &b) {
                          return a.getLastName() < b.getLastName();
                      });
        }

        // ----------------------------------------
        // Print final table
        // ----------------------------------------
        printHeader();
        for (const auto &st : students) {
            std::cout << st << "\n";
        }

        std::cout << "\nDo another action? (y/n): ";
        char again;
        std::cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    std::cout << "Goodbye.\n";
    return 0;
}
