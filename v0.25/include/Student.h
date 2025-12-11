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

    // Rule of 5 (default OK — vector handles its own memory)
    Student(const Student &) = default;
    Student(Student &&) noexcept = default;
    Student &operator=(const Student &) = default;
    Student &operator=(Student &&) noexcept = default;

    // Homework & exam input
    void addHomework(int grade);
    void setExam(int examGrade);

    // Final grade calculation
    void calculateFinalGrade();

    // Getters
    const std::string &getFirstName() const { return firstName; }
    const std::string &getLastName() const { return lastName; }
    const std::vector<int> &getHomework() const { return homework; }
    int getExam() const { return exam; }
    double getFinalGrade() const { return finalGrade; }
};

#endif
