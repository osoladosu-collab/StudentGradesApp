#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homework;
    int exam = 0;
    double finalGrade = 0.0;

public:
    Student() = default;

    Student(const std::string &fn, const std::string &ln)
        : firstName(fn), lastName(ln) {}

    // ------------- Getters -------------
    const std::string& getName() const { return firstName; }
    const std::string& getSurname() const { return lastName; }
    double getFinalGrade() const { return finalGrade; }

    // ------------- Input helpers -------------
    void addHomework(int x) { homework.push_back(x); }
    void setExam(int e) { exam = e; }

    // ------------- Grade calculation -------------
    void calculateFinal(bool useAverage = true) {
        if (homework.empty()) {
            finalGrade = 0.6 * exam;
            return;
        }

        double hwScore = 0.0;

        if (useAverage) {
            hwScore = std::accumulate(homework.begin(), homework.end(), 0.0)
                    / homework.size();
        } else {
            std::vector<int> temp = homework;
            std::sort(temp.begin(), temp.end());
            if (temp.size() % 2 == 0)
                hwScore = (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2.0;
            else
                hwScore = temp[temp.size()/2];
        }

        finalGrade = 0.4 * hwScore + 0.6 * exam;
    }
};

#endif
