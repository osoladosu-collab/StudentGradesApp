# Student Grades App — Version v0.25

This version extends v0.2 by implementing **three separate container types**:

- `std::vector`
- `std::list`
- `std::deque`

The program measures the execution time of:

1. Reading student data from file  
2. Sorting students  
3. Splitting into *passed* and *failed* groups  
4. Writing results to output files  

This allows performance comparison between different C++ container types for large datasets (10K, 100K, 1M, and 10M students).

---

## 📁 Project Structure

# Student Grades Application – Final Release (v1.0)

This project is a C++ application for processing large student datasets, computing final grades, sorting students, and dividing them into "passed" and "failed" groups.  
The final version (v1.0) focuses on performance optimization, container comparison, and algorithmic efficiency as required in Task 3.

---

## 📌 Implemented Features

- Reads student data from text files  
- Calculates final grades  
- Sorts students by final grade  
- Splits students into "weak" (failed) and "strong" (passed) groups  
- Exports results to CSV files  
- Measures execution time for each stage:
  - Reading
  - Sorting
  - Splitting
  - Writing
  - Total time

- Supports three STL containers:
  - `std::vector`
  - `std::deque`
  - `std::list`

- Supports two processing strategies:
  - Strategy 1 – Copy into two new containers  
  - Strategy 2 – Move weak students and shrink the base container  

- Uses STL algorithms from `<algorithm>` such as:
  - `std::sort`
  - `std::copy_if`
  - `std::remove_if`
  - `std::partition`

---

## 📂 Project Structure

