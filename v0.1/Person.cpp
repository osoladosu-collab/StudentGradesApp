#include "Person.h"
#include <algorithm>
#include <iomanip>
#include <random>
#include <sstream>

// static member initialization
int Person::fileHomeworkCount = 0;

Person::Person() : exam(0), finalAverage(0), finalMedian(0) {}

Person::Person(const std::string &fn, const std::string &ln,
               const std::vector<int> &hw, int ex)
    : firstName(fn), lastName(ln), homework(hw), exam(ex) {
    computeFinals();
}

void Person::computeFinals() {
    if (homework.empty()) {
        finalAverage = 0;
        finalMedian = 0;
        return;
    }

    // Average
    double sum = 0;
    for (int h : homework) sum += h;
    finalAverage = 0.4 * (sum / homework.size()) + 0.6 * exam;

    // Median
    std::vector<int> sorted = homework;
    std::sort(sorted.begin(), sorted.end());
    double median;

    if (sorted.size() % 2 == 0)
        median = (sorted[sorted.size()/2 - 1] + sorted[sorted.size()/2]) / 2.0;
    else
        median = sorted[sorted.size()/2];

    finalMedian = 0.4 * median + 0.6 * exam;
}

void Person::readFromConsole() {
    homework.clear();

    std::cout << "Enter first name: ";
    std::cin >> firstName;

    std::cout << "Enter last name: ";
    std::cin >> lastName;

    std::cout << "Enter homework grades (enter -1 to finish): ";
    while (true) {
        int grade;
        std::cin >> grade;
        if (grade == -1) break;
        if (grade >= 0 && grade <= 10)
            homework.push_back(grade);
        else
            std::cout << "Invalid grade, enter 0–10 or -1 to finish: ";
    }

    std::cout << "Enter exam grade: ";
    std::cin >> exam;

    computeFinals();
}

Person Person::randomPerson(int hwCount) {
    static const std::vector<std::string> fnames = {
        "John","Mary","Alex","Sarah","Tom","Linda"
    };
    static const std::vector<std::string> lnames = {
        "Smith","Johnson","Brown","Taylor","Miller","Davis"
    };

    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> nameDist(0, 5);
    std::uniform_int_distribution<int> gradeDist(1, 10);

    std::string fn = fnames[nameDist(rng)];
    std::string ln = lnames[nameDist(rng)];

    std::vector<int> hw(hwCount);
    for (int &h : hw) h = gradeDist(rng);

    int ex = gradeDist(rng);

    return Person(fn, ln, hw, ex);
}

std::istream& operator>>(std::istream &is, Person &p) {
    p.homework.clear();

    if (!(is >> p.firstName >> p.lastName))
        return is;

    int grade;

    // read exactly fileHomeworkCount HW grades
    for (int i = 0; i < Person::fileHomeworkCount; ++i) {
        if (!(is >> grade)) return is;
        p.homework.push_back(grade);
    }

    // read exam
    if (!(is >> p.exam)) return is;

    p.computeFinals();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Person &p) {
    os << std::left << std::setw(12) << p.firstName
       << std::setw(12) << p.lastName
       << std::right << std::setw(14) << std::fixed << std::setprecision(2)
       << p.finalAverage << " | "
       << std::setw(12) << p.finalMedian;
    return os;
}
