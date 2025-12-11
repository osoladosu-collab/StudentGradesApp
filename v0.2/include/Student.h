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
    // Constructors
    Student();
    Student(const std::string &fn, const std::string &ln);

    // Copy operations
    Student(const Student &other);
    Student& operator=(const Student &other);

    // Move operations
    Student(Student&& other) noexcept;
    Student& operator=(Student&& other) noexcept;

    // Setters
    void addHomework(int grade);
    void setExam(int grade);
    void computeFinal();

    // Getters
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::vector<int>& getHomework() const;
    int getExam() const;
    double getFinalGrade() const;
};

#endif
