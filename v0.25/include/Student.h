#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    Student();
    Student(const std::string &fn, const std::string &ln);
    Student(const Student &other);
    Student& operator=(const Student &other);
    ~Student();

    void calculateFinalGrade();
    double getFinalGrade() const;

    const std::string& getFirstName() const;
    const std::string& getLastName() const;

    void setHomework(const std::vector<int> &hw);
    void setExam(int ex);
};

#endif
