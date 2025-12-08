#include "Student.h"
#include <numeric>

Student::Student(int id, const std::string &name) : id(id), name(name), exam(0), finalGrade(0.0) {}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
std::vector<int> Student::getHomework() const { return homework; }
int Student::getExam() const { return exam; }
double Student::getFinalGrade() const { return finalGrade; }

void Student::setHomework(const std::vector<int> &hw) { homework = hw; }
void Student::setExam(int ex) { exam = ex; }

void Student::calculateFinalGrade() {
    double hwAverage = 0.0;
    if (!homework.empty()) {
        hwAverage = std::accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    }
    finalGrade = 0.4 * hwAverage + 0.6 * exam;
}
