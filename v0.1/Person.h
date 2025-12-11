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
    double finalAverage;
    double finalMedian;

    void computeFinals();

public:
    // Used when reading from files
    static int fileHomeworkCount;

    Person();
    Person(const std::string &fn, const std::string &ln,
           const std::vector<int> &hw, int ex);

    // Getters
    const std::string& getFirstName() const { return firstName; }
    const std::string& getLastName() const { return lastName; }
    const std::vector<int>& getHomework() const { return homework; }
    int getExam() const { return exam; }
    double getFinalAverage() const { return finalAverage; }
    double getFinalMedian() const { return finalMedian; }

    // User input
    void readFromConsole();

    // Random person generator
    static Person randomPerson(int hwCount);

    // Stream operators
    friend std::istream& operator>>(std::istream &is, Person &p);
    friend std::ostream& operator<<(std::ostream &os, const Person &p);
};

#endif
