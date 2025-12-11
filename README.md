# Student Grades Application (v0.1)

## Overview
This application reads students' homework and exam results, calculates final grades using either the **average** or **median** of homework results, and prints a neatly formatted table. It supports:

- Manual input
- Random generation of student grades
- Reading **any** `.txt` file in the working directory (auto-detects number of homework columns from the file header)
- Sorting by first name or surname
- Output of **Final (Avg.)** and **Final (Med.)** with two decimal precision
- Rule of Three implemented in `Person` class
- Overloaded `operator>>` and `operator<<` for `Person`

## Formula
Final grade is computed as:
