#include "Student.h"
#include <numeric>
#include <algorithm>

Student::Student() : exam(0), finalGrade(0.0) {}

Student::Student(const std::string &fn, const std::string &ln)
    : firstName(fn), lastName(ln), exam(0), finalGrade(0.0) {}

// Copy constructor
Student::Student(const Student &other)
    : firstName(other.firstName),
      lastName(other.lastName),
      homework(other.homework),
      exam(other.exam),
      finalGrade(other.finalGrade) {}

// Move constructor (NEW)
Student::Student(Student&& other) noexcept = default;

// Copy assignment
Student& Student::operator=(const Student &other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
        homework = other.homework;
        exam = other.exam;
        finalGrade = other.finalGrade;
    }
    return *this;
}

// Move assignment (NEW)
Student& Student::operator=(Student&& other) noexcept = default;

Student::~Student() {}

void Student::calculateFinalGrade() {
    if (homework.empty()) {
        finalGrade = 0.6 * exam;
        return;
    }
    double sum = std::accumulate(homework.begin(), homework.end(), 0);
    double avg = sum / homework.size();
    finalGrade = 0.4 * avg + 0.6 * exam;
}

double Student::getFinalGrade() const { return finalGrade; }
const std::string& Student::getFirstName() const { return firstName; }
const std::string& Student::getLastName() const { return lastName; }

void Student::setHomework(const std::vector<int> &hw) { homework = hw; }
void Student::setExam(int ex) { exam = ex; }
