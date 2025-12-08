#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
    double grade;
    std::vector<double> homework;
    double exam;

    Student() : id(0), name(""), grade(0), exam(0) {}
    Student(int _id, const std::string &_name) : id(_id), name(_name), grade(0), exam(0) {}

    void setHomework(const std::vector<double> &hw) { homework = hw; }
    void setExam(double ex) { exam = ex; }

    void calculateFinalGrade() {
        double hwAvg = 0;
        if (!homework.empty()) {
            double sum = 0;
            for (double h : homework) sum += h;
            hwAvg = sum / homework.size();
        }
        grade = 0.4 * hwAvg + 0.6 * exam;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getGrade() const { return grade; }
};

#endif // STUDENT_H
