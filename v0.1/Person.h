#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> homework;
    int exam;
    double finalGrade;

public:
    // Constructors
    Person();
    Person(const std::string &fn, const std::string &ln);

    // Rule of three
    Person(const Person &other);
    Person& operator=(const Person &other);
    ~Person();

    // Methods
    void readData();                  // Input from user
    void printData() const;           // Output formatted data
    void calculateFinalGradeByAverage();
    void calculateFinalGradeByMedian();

    // Optional: getters for sorting/output
    std::string getFirstName() const;
    std::string getLastName() const;
    double getFinalGrade() const;
};

#endif
