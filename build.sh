#!/bin/bash
set -e

echo "-------------------------------------"
echo " Rebuilding StudentGradesApp v0.1"
echo "-------------------------------------"

cd "$(dirname "$0")/v0.1"

g++ -std=c++17 -O2 main.cpp Person.cpp -o studentGrades

echo "-------------------------------------"
echo " Build complete!"
echo "-------------------------------------"
