#include "Person.h"
#include <iomanip>
#include <algorithm>
#include <numeric> // for std::accumulate

// Constructors
Person::Person() : exam(0), finalGrade(0.0) {}
Person::Person(const std::string &fn, const std::string &ln)
    : firstName(fn), lastName(ln), exam(0), finalGrade(0.0) {}

// Copy constructor
Person::Person(const Person &other)
    : firstName(other.firstName), lastName(other.lastName),
      homework(other.homework), exam(other.exam), finalGrade(other.finalGrade) {}

// Assignment operator
Person& Person::operator=(const Person &other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    return *this;
}

// Destructor
Person::~Person() {}

// Input method
void Person::readData() {
    std::cout << "Enter first name: "; std::cin >> firstName;
    std::cout << "Enter last name: "; std::cin >> lastName;

    int hw;
    std::cout << "Enter homework grades (-1 to finish): ";
    while (std::cin >> hw && hw != -1) {
        homework.push_back(hw);
    }

    std::cout << "Enter exam grade: ";
    std::cin >> exam;
}

// Output method
void Person::printData() const {
    std::cout << std::left << std::setw(10) << firstName
              << std::setw(10) << lastName
              << std::setw(10) << std::fixed << std::setprecision(2)
              << finalGrade << std::endl;
}

// Average calculation
void Person::calculateFinalGradeByAverage() {
    double hwAvg = 0;
    if (!homework.empty()) {
        int sum = std::accumulate(homework.begin(), homework.end(), 0);
        hwAvg = static_cast<double>(sum) / homework.size();
    }
    finalGrade = 0.4 * hwAvg + 0.6 * exam;
}

// Median calculation
void Person::calculateFinalGradeByMedian() {
    if (homework.empty()) {
        finalGrade = 0.6 * exam;
        return;
    }
    std::vector<int> temp = homework;
    std::sort(temp.begin(), temp.end());
    double median;
    size_t n = temp.size();
    if (n % 2 == 0) {
        median = (temp[n/2 - 1] + temp[n/2]) / 2.0;
    } else {
        median = temp[n/2];
    }
    finalGrade = 0.4 * median + 0.6 * exam;
}

// Getters
std::string Person::getFirstName() const { return firstName; }
std::string Person::getLastName() const { return lastName; }
double Person::getFinalGrade() const { return finalGrade; }
