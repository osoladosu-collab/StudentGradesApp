#include "Person.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<Person> students;
    char choice;
    do {
        Person p;
        p.readData();
        p.calculateFinalGradeByAverage(); // or calculateFinalGradeByMedian()
        students.push_back(p);

        std::cout << "Add another student? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "\nName       Surname       Final_Point(Aver.)\n";
    std::cout << "-------------------------------------------\n";
    for (const auto &s : students) s.printData();

    return 0;
}
