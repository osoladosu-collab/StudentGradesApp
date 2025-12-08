#pragma once
#include <string>
#include <vector>

class Student {
private:
    int id;
    std::string name;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Student(int id, const std::string &name); // id first, then name

    int getId() const;
    std::string getName() const;
    std::vector<int> getHomework() const;
    int getExam() const;
    double getFinalGrade() const;

    void setHomework(const std::vector<int> &hw);
    void setExam(int ex);
    void calculateFinalGrade();
};
