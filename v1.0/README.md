📘 Student Grades Application — v1.0
📌 Project Overview

This project is a C++ application developed to analyze the performance of different STL containers (std::vector, std::deque, std::list) when processing large student datasets.

The program:

Reads student data from a file

Sorts students by final grade

Splits them into two groups: passed and failed

Measures execution time of each stage

Two different splitting strategies are implemented and compared.

This is the final optimized release (v1.0) for Task 3.

⚙️ Features

Supports three containers: vector, deque, list

Implements two splitting strategies:

Strategy 1: Copy students into two new containers

Strategy 2: Move failed students out and shrink base container

Uses STL algorithms: std::sort, std::copy_if, std::partition

Measures time for:

Reading

Sorting

Splitting

Writing results

Works with large datasets (10k – 1M students)

🛠️ Build Instructions
✅ Option 1 — Using Make (Linux / Unix)

From the v1.0 directory:

make clean
make


Run:

./studentGrades_v025

✅ Option 2 — Using CMake (Any OS)

From the v1.0 directory:

mkdir build
cd build
cmake ..
make


Run:

./studentGrades

▶️ How to Use the Application

When the program starts, follow the prompts.

1️⃣ Choose container:
1) vector
2) deque
3) list

2️⃣ Choose strategy:
1) Strategy 1 (copy into two containers)
2) Strategy 2 (move weak, shrink base)

3️⃣ Enter input file:

Example:

students10000.txt
students100000.txt
students1000000.txt


The program will display timing results and generate output CSV files:

*_weak.csv

*_strong.csv

🧪 Test Datasets

The following datasets were used:

students10000.txt

students100000.txt

students1000000.txt

📊 Benchmark Results Summary
DATASET: students10000.txt

Fastest:

Container: vector

Strategy: Strategy 2

Slowest:

Container: list

Strategy: Strategy 2

DATASET: students100000.txt

Fastest:

Container: vector

Strategy: Strategy 2

Slowest:

Container: list

Strategy: Strategy 2

DATASET: students1000000.txt

Fastest:

Container: vector

Strategy: Strategy 2

Slowest:

Container: list

Strategy: Strategy 2

🧠 Conclusions
✅ Fastest container overall:

std::vector

Because:

Contiguous memory

Best cache performance

Fastest sorting

✅ Fastest strategy overall:

Strategy 2 (move & shrink)

Because:

Less memory allocation

Avoids copying all students twice

Scales better for large files

📈 Performance vs File Size

As dataset size increased:

Read time grew linearly

Sorting became dominant after 100k students

std::list degraded heavily due to pointer-based memory layout

std::vector remained the most stable and fastest

🗂 Project Structure
v1.0/
├── include/        # Header files
├── src/            # Source files
├── Makefile        # Unix build system
├── CMakeLists.txt  # Cross-platform build system
├── README.md       # Documentation
└── students*.txt   # Test datasets
