#include "Person.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <filesystem> // requires C++17

namespace fs = std::filesystem;

void printHeader() {
    std::cout << std::left << std::setw(12) << "Name"
              << std::setw(12) << "Surname"
              << std::right << std::setw(14) << "Final (Avg.)"
              << " | " << std::setw(12) << "Final (Med.)" << "\n";
    std::cout << std::string(12+12+14 + 3 + 12, '-') << "\n";
}

// split a string by whitespace into tokens
std::vector<std::string> splitWS(const std::string &line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string tok;
    while (iss >> tok) tokens.push_back(tok);
    return tokens;
}

// detect files in current directory with .txt extension
std::vector<fs::path> findTextFiles() {
    std::vector<fs::path> out;
    for (auto &entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_regular_file()) {
            if (entry.path().extension() == ".txt") out.push_back(entry.path());
        }
    }
    std::sort(out.begin(), out.end());
    return out;
}

// read file header to find how many HW columns (assumes header has Name Surname HW1..HWn Exam)
int detectHomeworkCountInHeader(const fs::path &p) {
    std::ifstream ifs(p.string());
    if (!ifs) return -1;
    std::string headerLine;
    std::getline(ifs, headerLine);
    auto tokens = splitWS(headerLine);
    // tokens: Name Surname HW1 ... HWn Exam
    if ((int)tokens.size() < 3) return -1;
    int hwCount = static_cast<int>(tokens.size()) - 3; // subtract Name, Surname, Exam
    if (hwCount < 0) hwCount = 0;
    return hwCount;
}

bool readStudentsFromFile(const fs::path &p, std::vector<Person> &students) {
    int hwCount = detectHomeworkCountInHeader(p);
    if (hwCount < 0) return false;
    Person::fileHomeworkCount = hwCount;

    std::ifstream ifs(p.string());
    if (!ifs) return false;

    // discard header line
    std::string header;
    std::getline(ifs, header);

    Person tmp;
    // read each line: operator>> will read exactly fileHomeworkCount hw values and exam
    while (ifs >> tmp) {
        students.push_back(tmp);
    }
    return true;
}

int main() {
    std::cout << "Student Grades App (C++17)\n";
    std::cout << "--------------------------------\n";

    std::vector<Person> students;

    // Menu: let user choose file or manual/random input
    while (true) {
        std::cout << "\nChoose source:\n";
        std::cout << "  1) List .txt files in current folder and choose one to load\n";
        std::cout << "  2) Manual input (enter students by keyboard)\n";
        std::cout << "  3) Random generate students\n";
        std::cout << "  4) Exit\n";
        std::cout << "Select option (1-4): ";
        int opt;
        if (!(std::cin >> opt)) return 0;

        if (opt == 1) {
            auto files = findTextFiles();
            if (files.empty()) {
                std::cout << "No .txt files found in current directory.\n";
                continue;
            }
            std::cout << "Found .txt files:\n";
            for (size_t i = 0; i < files.size(); ++i) {
                std::cout << "  " << (i+1) << ") " << files[i].filename().string() << "\n";
            }
            std::cout << "Choose file number: ";
            size_t fidx;
            std::cin >> fidx;
            if (fidx < 1 || fidx > files.size()) {
                std::cout << "Invalid selection.\n";
                continue;
            }
            students.clear();
            bool ok = readStudentsFromFile(files[fidx-1], students);
            if (!ok) {
                std::cout << "Failed to read file.\n";
                continue;
            }
            std::cout << "Loaded " << students.size() << " students from " << files[fidx-1].filename() << "\n";
        }
        else if (opt == 2) {
            students.clear();
            std::cout << "Manual input mode. After entering homework grades enter -1 to finish that student's HW list.\n";
            while (true) {
                Person p;
                p.readFromConsole();
                students.push_back(p);

                std::cout << "Add another student? (y/n): ";
                char c;
                std::cin >> c;
                if (c != 'y' && c != 'Y') break;
            }
        }
        else if (opt == 3) {
            students.clear();
            std::cout << "Random generation mode.\n";
            std::cout << "Number of students to generate: ";
            int n; std::cin >> n;
            std::cout << "Number of homework assignments per student: ";
            int hw; std::cin >> hw;
            for (int i = 0; i < n; ++i) students.push_back(Person::randomPerson(hw));
            std::cout << "Generated " << students.size() << " students.\n";
        }
        else break;

        if (students.empty()) {
            std::cout << "No students loaded. Returning to menu.\n";
            continue;
        }

        // Choose sorting
        std::cout << "\nSort by: 1) First name  2) Surname. Choose (1/2): ";
        int sOpt; std::cin >> sOpt;
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

        // Print table with both avg and median
        printHeader();
        for (const auto &st : students) {
            std::cout << st << "\n";
        }

        // After showing results, ask whether to do another action
        std::cout << "\nDo another action? (y/n): ";
        char again; std::cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    std::cout << "Goodbye.\n";
    return 0;
}
