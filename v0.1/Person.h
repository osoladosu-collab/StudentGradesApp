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
    // no need to store a single finalGrade; we'll compute avg/median on demand

public:
    // static: number of homework columns expected when reading from structured files
    static int fileHomeworkCount;
    // Constructors
    Person();
    Person(const std::string &fn, const std::string &ln);

    // Rule of three
    Person(const Person &other);
    Person& operator=(const Person &other);
    ~Person();

    // Read/write helpers (also used by operator>> / operator<<)
    void readFromConsole();                 // manual console input (hw until -1)
    static Person randomPerson(int hwCount); // create random person with hwCount homeworks

    // Calculations
    double homeworkAverage() const;
    double homeworkMedian() const;
    double finalByAverage() const; // 40% hw avg + 60% exam
    double finalByMedian() const;  // 40% hw median + 60% exam

    // Accessors
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::vector<int>& getHomework() const;
    int getExam() const;

    // For file parsing: read exactly fileHomeworkCount homework values and exam from a stream
    friend std::istream& operator>>(std::istream &is, Person &p);
    friend std::ostream& operator<<(std::ostream &os, const Person &p);

    // utility to set data directly (used by file parser)
    void setData(const std::string &fn, const std::string &ln,
                 const std::vector<int> &hw, int ex);

    // clear homework (helpful for reuse)
    void clearHomework();
};

#endif // PERSON_H
