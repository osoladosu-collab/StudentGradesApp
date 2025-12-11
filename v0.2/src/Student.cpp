#include "Student.h"
#include <numeric>

// -------------------- Constructors --------------------

Student::Student() : exam(0), finalGrade(0.0) {}

Student::Student(const std::string &fn, const std::string &ln)
    : firstName(fn), lastName(ln), exam(0), finalGrade(0.0) {}

Student::Student(const Student &other) = default;

Student::Student(Student&& other) noexcept = default;

// -------------------- Assignment operators --------------------

Student& Student::operator=(const Student &other) = default;

Student& Student::operator=(Student&& other) noexcept = default;

// -------------------- Mutators --------------------

void Student::addHomework(int grade) {
    homework.push_back(grade);
}

void Student::setExam(int grade) {
    exam = grade;
}

void Student::computeFinal() {
    if (!homework.empty()) {
        double avg = std::accumulate(homework.begin(), homework.end(), 0.0)
                     / homework.size();
        finalGrade = 0.4 * avg + 0.6 * exam;
    } else {
        finalGrade = 0.6 * exam;
    }
}

// -------------------- Accessors --------------------

const std::string& Student::getFirstName() const {
    return firstName;
}

const std::string& Student::getLastName() const {
    return lastName;
}

const std::vector<int>& Student::getHomework() const {
    return homework;
}

int Student::getExam() const {
    return exam;
}

double Student::getFinalGrade() const {
    return finalGrade;
}
