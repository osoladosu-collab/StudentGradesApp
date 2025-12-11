#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include "Student.h"
#include "CSVWriter.h"
#include "Timer.h"

// --------------------------------------------------------------------
// Read File
// --------------------------------------------------------------------
template <typename Container>
void readFile(const std::string& filename, Container& students) {
    Timer t("Reading file");

    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    std::string fn, ln;
    while (in >> fn >> ln) {
        Student s(fn, ln);

        for (int i = 0; i < 5; i++) {
            int val;
            in >> val;
            s.addHomework(val);
        }

        int exam;
        in >> exam;
        s.setExam(exam);

        students.push_back(s);
    }
}

// --------------------------------------------------------------------
// Calculate Grades
// --------------------------------------------------------------------
template <typename Container>
void calculateGrades(Container& students) {
    Timer t("Calculating final grades");

    for (auto& s : students)
        s.calculateFinal();  // <-- correct name
}

// --------------------------------------------------------------------
// Split into passed / failed
// --------------------------------------------------------------------
template <typename Container>
void splitStudents(const Container& students,
                   Container& passed, Container& failed) {
    Timer t("Splitting students");

    for (const auto& s : students) {
        if (s.getFinalGrade() >= 5.0)
            passed.push_back(s);
        else
            failed.push_back(s);
    }
}

// --------------------------------------------------------------------
// Sorting (generic list)
// --------------------------------------------------------------------
template <typename Container>
void sortContainer(Container& c) {
    Timer t("Sorting students");

    c.sort([](const Student& a, const Student& b){
        return a.getSurname() < b.getSurname();
    });
}

// vector specialization
template<>
void sortContainer(std::vector<Student>& c) {
    Timer t("Sorting students");

    std::sort(c.begin(), c.end(),
        [](const Student& a, const Student& b){
            return a.getSurname() < b.getSurname();
        });
}

// deque specialization
template<>
void sortContainer(std::deque<Student>& c) {
    Timer t("Sorting students");

    std::sort(c.begin(), c.end(),
        [](const Student& a, const Student& b){
            return a.getSurname() < b.getSurname();
        });
}

// --------------------------------------------------------------------
// Write Output
// --------------------------------------------------------------------
template <typename Container>
void writeOutput(const Container& passed, const Container& failed,
                 const std::string& suffix) {
    Timer t("Writing output files");

    CSVWriter::write("passed_" + suffix + ".csv", passed);
    CSVWriter::write("failed_" + suffix + ".csv", failed);
}

// --------------------------------------------------------------------
// Run Entire Process
// --------------------------------------------------------------------
template <typename Container>
void runProcess(const std::string& filename, const std::string& name) {
    std::cout << "Running with " << name << "...\n";

    Container students;
    Container passed, failed;

    readFile(filename, students);
    calculateGrades(students);
    splitStudents(students, passed, failed);
    sortContainer(passed);
    sortContainer(failed);
    writeOutput(passed, failed, name);
}

// --------------------------------------------------------------------
// main
// --------------------------------------------------------------------
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./studentGrades_v025 datafile.txt\n";
        return 1;
    }

    std::string filename = argv[1];

    runProcess<std::vector<Student>>(filename, "vector");
    runProcess<std::list<Student>>(filename, "list");
    runProcess<std::deque<Student>>(filename, "deque");

    return 0;
}

