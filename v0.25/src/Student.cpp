#include "Student.h"
#include <numeric>

Student::Student() : exam(0), finalGrade(0.0) {}

Student::Student(const std::string &fn, const std::string &ln)
    : firstName(fn), lastName(ln), exam(0), finalGrade(0.0) {}

void Student::addHomework(int grade) {
    homework.push_back(grade);
}

void Student::setExam(int examGrade) {
    exam = examGrade;
}

void Student::calculateFinalGrade() {
    if (homework.empty()) {
        finalGrade = exam * 0.6;
        return;
    }

    double sum = std::accumulate(homework.begin(), homework.end(), 0.0);
    double avg = sum / homework.size();

    finalGrade = avg * 0.4 + exam * 0.6;
}
