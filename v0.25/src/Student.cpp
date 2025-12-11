#include "Student.h"

Student::Student(const Student &other)
    : firstName(other.firstName),
      lastName(other.lastName),
      homework(other.homework),
      exam(other.exam),
      finalGrade(other.finalGrade)
{}

Student& Student::operator=(const Student &other) {
    if (this == &other) return *this;
    firstName = other.firstName;
    lastName = other.lastName;
    homework = other.homework;
    exam = other.exam;
    finalGrade = other.finalGrade;
    return *this;
}

void Student::calculateFinalGrade(bool averageMethod) {
    if (homework.empty()) {
        // fallback: use exam only (scaled to 100 if needed) — keeping scale consistent with hw/exam both 1..10
        finalGrade = 0.6 * static_cast<double>(exam);
        return;
    }

    if (averageMethod) {
        double sum = std::accumulate(homework.begin(), homework.end(), 0.0);
        double avg = sum / static_cast<double>(homework.size());
        finalGrade = 0.4 * avg + 0.6 * static_cast<double>(exam);
    } else {
        std::vector<int> tmp = homework;
        std::sort(tmp.begin(), tmp.end());
        double med;
        size_t n = tmp.size();
        if (n % 2 == 1) med = tmp[n/2];
        else med = (tmp[n/2 - 1] + tmp[n/2]) / 2.0;
        finalGrade = 0.4 * med + 0.6 * static_cast<double>(exam);
    }
}
