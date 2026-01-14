#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <iterator>

#include "Timer.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "Student.h"

// ----------------------------------------------------------
// Utility: detect if container is std::list
// ----------------------------------------------------------
template <typename T>
struct is_list : std::false_type {};

template <typename T>
struct is_list<std::list<T>> : std::true_type {};


// ----------------------------------------------------------
// Sorting (list has .sort(), others use std::sort)
// ----------------------------------------------------------
template <typename Container>
void sortStudents(Container& students) {
    if constexpr (is_list<Container>::value) {
        students.sort([](const Student& a, const Student& b) {
            return a.getFinalGrade() < b.getFinalGrade();
        });
    } else {
        std::sort(students.begin(), students.end(),
                  [](const Student& a, const Student& b) {
                      return a.getFinalGrade() < b.getFinalGrade();
                  });
    }
}


// ----------------------------------------------------------
// STRATEGY 1: COPY into two new containers
// (original students container remains unchanged)
// ----------------------------------------------------------
template <typename Container>
void splitStrategy1(const Container& students,
                    Container& weak,
                    Container& strong)
{
    std::copy_if(students.begin(), students.end(),
                 std::back_inserter(weak),
                 [](const Student& s) {
                     return s.getFinalGrade() < 5.0;
                 });

    std::copy_if(students.begin(), students.end(),
                 std::back_inserter(strong),
                 [](const Student& s) {
                     return s.getFinalGrade() >= 5.0;
                 });
}


// ----------------------------------------------------------
// STRATEGY 2: MOVE weak students out of base container
// (base becomes only strong students)
// ----------------------------------------------------------
template <typename Container>
void splitStrategy2(Container& students,
                    Container& weak)
{
    auto it = std::stable_partition(students.begin(), students.end(),
        [](const Student& s) {
            return s.getFinalGrade() >= 5.0;
        });

    std::move(it, students.end(), std::back_inserter(weak));
    students.erase(it, students.end());
}


// ----------------------------------------------------------
// Processing function
// ----------------------------------------------------------
template <typename Container>
void runContainer(const std::string& filename,
                  const std::string& outPrefix,
                  int strategy)
{
    Timer total("TOTAL");

    // READ
    Timer t_read("Read");
    auto base = FileReader::readStudents(filename);
    Container students(base.begin(), base.end());
    std::cout << "Loaded " << students.size() << " students\n";

    // SORT
    {
        Timer t_sort("Sort");
        sortStudents(students);
    }

    // SPLIT
    Container weak, strong;
    {
        Timer t_split("Split");

        if (strategy == 1) {
            splitStrategy1(students, weak, strong);
        }
        else {
            splitStrategy2(students, weak);
            strong = students;
        }
    }

    // WRITE OUTPUT
    {
        Timer t_write("Write");
        FileWriter::write(outPrefix + "_weak.csv", weak);
        FileWriter::write(outPrefix + "_strong.csv", strong);
    }

    std::cout << "Processing completed.\n\n";
}


// ----------------------------------------------------------
// MAIN MENU
// ----------------------------------------------------------
int main() {
    std::cout << "\nChoose container:\n"
              << "1) vector\n"
              << "2) deque\n"
              << "3) list\n"
              << "Enter choice: ";

    int choice;
    std::cin >> choice;

    std::cout << "\nChoose strategy:\n"
              << "1) Strategy 1 (copy into two containers)\n"
              << "2) Strategy 2 (move weak, shrink base)\n"
              << "Enter choice: ";

    int strategy;
    std::cin >> strategy;

    std::string filename;
    std::cout << "\nEnter input filename: ";
    std::cin >> filename;

    if (choice == 1)
        runContainer<std::vector<Student>>(filename, "vector", strategy);
    else if (choice == 2)
        runContainer<std::deque<Student>>(filename, "deque", strategy);
    else if (choice == 3)
        runContainer<std::list<Student>>(filename, "list", strategy);
    else
        std::cout << "Invalid container choice.\n";

    return 0;
}
