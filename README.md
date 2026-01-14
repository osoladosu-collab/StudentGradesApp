🎓 StudentGradesApp

A C++ application for processing large student datasets, computing final grades, and benchmarking different STL containers and strategies.

This repository contains multiple development stages of the same project (v0.1 → v0.25 → v1.0), showing the evolution from a basic grading system to a fully benchmarked, optimized application.

⭐ Final Release — v1.0 (Task 3)
📌 Overview

The final version (v1.0) focuses on performance optimization and benchmarking.
It compares how different STL containers and different splitting strategies affect execution speed when working with large student datasets.

The program:

Reads large student files

Sorts students by final grade

Splits them into failed (weak) and passed (strong) groups

Writes results to CSV files

Measures execution time for every stage

⚙️ Implemented Features (v1.0)

Reading student data from text files

Final grade calculation

Sorting by final grade

Splitting into “weak” and “strong” groups

Writing results to CSV files

Detailed timing of:

Read

Sort

Split

Write

Total execution time

Three STL containers:

std::vector

std::deque

std::list

Two strategies:

Strategy 1: Copy students into two new containers

Strategy 2: Move weak students and shrink the base container

STL algorithms from <algorithm>:

std::sort

std::copy_if

std::remove_if

std::partition

🛠 Build Instructions (v1.0)

Open a terminal in the v1.0 folder:

cd v1.0
make clean
make


Run the program:

./studentGrades_v025

▶️ How to Use

Choose container type:

1) vector
2) deque
3) list


Choose strategy:

1) Strategy 1 (copy into two containers)
2) Strategy 2 (move weak, shrink base)


Enter input file name:

students10000.txt
students100000.txt
students1000000.txt


Output files will be generated automatically.

📊 Benchmark Results

Tests were performed using three datasets:

students10000.txt

students100000.txt

students1000000.txt

✔ Dataset: students10000.txt

Fastest container: vector

Fastest strategy: Strategy 2

All containers perform similarly at small scale.

✔ Dataset: students100000.txt

vector consistently fastest

deque slightly slower

list significantly slower in sorting and splitting

✔ Dataset: students1000000.txt

vector is clearly the fastest overall

deque slightly slower

list much slower, especially for sorting and splitting

🧠 Conclusions

✅ Fastest container: std::vector

✅ Fastest strategy: Strategy 2 (move weak, shrink base)

✅ Scalability:

Differences are small for 10,000 students

Differences become significant at 100,000

Differences become very large at 1,000,000

std::vector benefits from contiguous memory and cache locality

std::list performs worst due to pointer-based structure

Strategy 2 is more memory-efficient and usually faster

➡️ Best overall choice: std::vector + Strategy 2

📁 Project Structure
StudentGradesApp/
│
├── v0.1/        → Initial grading system
├── v0.2/        → Improved file handling and generation
├── v0.25/       → Container benchmarking
├── v1.0/        → Final optimized release (Task 3)
│
└── README.md    → Project documentation

📘 Previous Versions (for grading & history)
v0.25 — Container comparison

Implemented vector, deque, and list

Benchmarked reading, sorting, splitting, and writing

Introduced performance measurement system

Folder: /v0.25

v0.1 — Initial version

Manual and file input

Average and median calculations

Sorting and formatted output

Random dataset generation

Rule of Three implemented in Person class

Folder: /v0.1