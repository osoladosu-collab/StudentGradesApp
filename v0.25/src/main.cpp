#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

#include "Student.h"
#include "Timer.h"
#include "CSVWriter.h"

template <typename Container>
void processWithContainer(const std::string &filename, bool useAverage)
{
    Container students;

    {
        Timer t("Reading file");
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Cannot open file: " << filename << "\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string fn, ln;
            ss >> fn >> ln;

            Student s(fn, ln);

            int hw;
            for (int i = 0; i < 5; i++) {
                ss >> hw;
                s.addHomework(hw);
            }

            int exam;
            ss >> exam;
            s.setExam(exam);

            students.push_back(s);
        }
    }

    {
        Timer t("Calculating final grades");
        for (auto &s : students)
            s.calculateFinalGrade(useAverage);
    }

    Container weak, strong;

    {
        Timer t("Splitting students");
        for (auto &s : students) {
            if (s.getFinalGrade() < 5.0)
                weak.push_back(s);
            else
                strong.push_back(s);
        }
    }

    {
        Timer t("Sorting students");

        if constexpr (std::is_same_v<Container, std::list<Student>>) {
            weak.sort([](const Student &a, const Student &b) {
                return a.getFinalGrade() < b.getFinalGrade();
            });
            strong.sort([](const Student &a, const Student &b) {
                return a.getFinalGrade() < b.getFinalGrade();
            });
        } else {
            std::sort(weak.begin(), weak.end(), [](const Student &a, const Student &b) {
                return a.getFinalGrade() < b.getFinalGrade();
            });
            std::sort(strong.begin(), strong.end(), [](const Student &a, const Student &b) {
                return a.getFinalGrade() < b.getFinalGrade();
            });
        }
    }

    {
        Timer t("Writing output files");
        CSVWriter w("weak.csv");
        CSVWriter s("strong.csv");

        for (auto &st : weak)
            w.writeRow({st.getFirstName(), st.getLastName(), std::to_string(st.getFinalGrade())});

        for (auto &st : strong)
            s.writeRow({st.getFirstName(), st.getLastName(), std::to_string(st.getFinalGrade())});
    }
}

int main()
{
    std::cout << "Running with std::vector...\n";
    processWithContainer<std::vector<Student>>("students.txt", true);

    std::cout << "Running with std::list...\n";
    processWithContainer<std::list<Student>>("students.txt", true);

    std::cout << "Running with std::deque...\n";
    processWithContainer<std::deque<Student>>("students.txt", true);

    return 0;
}
