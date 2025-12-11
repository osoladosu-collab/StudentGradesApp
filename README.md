Student Grades Application (v0.1)
Overview

This application reads students' homework and exam results, calculates final grades using either the average or the median of homework scores, and prints a neatly formatted table. It supports manual input, random grade generation, reading data from .txt files, automatic detection of homework column count, sorting by name or surname, and displaying both Final (Avg.) and Final (Med.) with two-decimal precision. The Person class fully implements the Rule of Three and provides overloaded operator>> and operator<< for input/output operations.

Final Grade Formula

Final grade is calculated as:

Using average:

Final = 0.4 * Average(Homework) + 0.6 * Exam


Using median:

Final = 0.4 * Median(Homework) + 0.6 * Exam

Features
1. Manual Input Mode

Users can enter first name, surname, any number of homework grades, and an exam grade. Homework entry continues until the user chooses to stop. The user may choose to calculate the final grade using either the average or the median.

2. File Reading Mode

The program reads files formatted as:

Name     Surname    HW1 HW2 HW3 ... Exam
John     Smith        8   7   9       10
Anna     Brown       10   9   8        9


The program automatically detects how many homework columns the file contains, calculates both average-based and median-based final grades, sorts students alphabetically, and outputs neatly formatted results.

3. Random Grade Generation

The program can generate large student datasets, including:

students10000.txt

students100000.txt

students1000000.txt

These files contain randomly generated homework and exam results.

Class Design: Person

The Person class stores: first name, surname, a vector of homework results, an exam grade, and a final grade.

It implements:

Constructor(s)

Copy constructor

Copy assignment operator

Destructor

operator>> for input

operator<< for output

Methods for calculating final grade using average or median

This satisfies the Rule of Three.

Sample Output
Name       Surname        Final (Avg.) | Final (Med.)
-----------------------------------------------------
John       Smith                 8.74   |       8.50
Anna       Brown                 9.24   |       9.00

Project Structure
StudentGradesApp/
│
├── Person.cpp
├── Person.h
├── main.cpp
├── Students.txt
├── students10000.txt
├── students100000.txt
├── students1000000.txt
├── .gitattributes
├── .gitignore
└── README.md

Release v0.1

Release v0.1 includes the full implementation of the application, manual and file input functionality, random grade generation, sorting and formatting features, and all required student dataset files.
