#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Student() : exam(0), finalGrade(0.0) {}
    Student(const std::string& fn, const std::string& ln)
        : firstName(fn), lastName(ln), exam(0), finalGrade(0.0) {}

    // getters
    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName() const { return lastName; }
    double getFinalGrade() const { return finalGrade; }

    void setHomework(const std::vector<int>& hw) { homework = hw; }
    void addHomework(int x) { homework.push_back(x); }
    void setExam(int e) { exam = e; }

    void calculateFinalGrade(bool averageMethod = true) {
        if (homework.empty()) {
            finalGrade = exam * 0.6;
            return;
        }

        double hwComponent = 0.0;

        if (averageMethod) {
            hwComponent = std::accumulate(homework.begin(),
                                          homework.end(), 0.0) / homework.size();
        } else {
            std::vector<int> sorted = homework;
            std::sort(sorted.begin(), sorted.end());
            if (sorted.size() % 2 == 0)
                hwComponent = (sorted[sorted.size()/2 - 1] + sorted[sorted.size()/2]) / 2.0;
            else
                hwComponent = sorted[sorted.size()/2];
        }

        finalGrade = hwComponent * 0.4 + exam * 0.6;
    }

    std::string fullName() const { return firstName + " " + lastName; }
};

#endif
