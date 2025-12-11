#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

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
// Processing function
// ----------------------------------------------------------
template <typename Container>
void runContainer(const std::string& filename, const std::string& outPrefix) {
    Timer total;

    // READ
    Timer t_read;
    Container students( FileReader::readStudents(filename).begin(),
                        FileReader::readStudents(filename).end() );
    std::cout << "Loaded " << students.size() << " students\n";

    // SORT
    {
        Timer t_sort;
        sortStudents(students);
    }

    // SPLIT
    Container weak, strong;
    {
        Timer t_split;

        for (const auto& s : students) {
            if (s.getFinalGrade() < 5.0)
                weak.push_back(s);
            else
                strong.push_back(s);
        }
    }

    // WRITE OUTPUT
    {
        Timer t_write;

        FileWriter::write(outPrefix + "_weak.csv", weak);
        FileWriter::write(outPrefix + "_strong.csv", strong);
    }

    std::cout << "Processing completed.\n";
}


// ----------------------------------------------------------
// MAIN MENU
// ----------------------------------------------------------
int main() {
    std::cout << "1) Process using vector\n"
                 "2) Process using deque\n"
                 "3) Process using list\n"
                 "Enter choice: ";

    int choice;
    std::cin >> choice;

    std::string filename;
    std::cout << "Enter input filename: ";
    std::cin >> filename;

    if (choice == 1) {
        runContainer<std::vector<Student>>(filename, "vector_out");
    }
    else if (choice == 2) {
        runContainer<std::deque<Student>>(filename, "deque_out");
    }
    else if (choice == 3) {
        runContainer<std::list<Student>>(filename, "list_out");
    }
    else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
