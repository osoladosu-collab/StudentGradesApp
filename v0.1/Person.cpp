#include "Person.h"
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <random>

int Person::fileHomeworkCount = 0;

// Constructors
Person::Person() : firstName(""), lastName(""), homework(), exam(0) {}
Person::Person(const std::string &fn, const std::string &ln)
    : firstName(fn), lastName(ln), homework(), exam(0) {}

// Copy constructor
Person::Person(const Person &other)
    : firstName(other.firstName), lastName(other.lastName),
      homework(other.homework), exam(other.exam) {}

// Assignment operator
Person& Person::operator=(const Person &other) {
    if (this != &other) {
        firstName = other.firstName;
        lastName  = other.lastName;
        homework  = other.homework;
        exam      = other.exam;
    }
    return *this;
}

// Destructor
Person::~Person() {}

// Console input (manual): hw until -1 sentinel
void Person::readFromConsole() {
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    homework.clear();
    std::cout << "Enter homework grades (integers 0-10). Enter -1 to finish:\n";
    int x;
    while (std::cin >> x && x != -1) {
        homework.push_back(x);
    }
    // clear any trailing newline state
    if (!std::cin) return; // input failure will be handled by caller

    std::cout << "Enter exam grade (integer 0-10): ";
    std::cin >> exam;
}

// Random person generator
Person Person::randomPerson(int hwCount) {
    static std::mt19937 rng((unsigned)std::random_device{}());
    std::uniform_int_distribution<int> gradeDist(1, 10);
    static int counter = 1;

    Person p;
    p.firstName = "RandName" + std::to_string(counter);
    p.lastName  = "RandSurname" + std::to_string(counter++);
    p.homework.clear();
    for (int i = 0; i < hwCount; ++i) p.homework.push_back(gradeDist(rng));
    p.exam = gradeDist(rng);
    return p;
}

// calculations
double Person::homeworkAverage() const {
    if (homework.empty()) return 0.0;
    double sum = std::accumulate(homework.begin(), homework.end(), 0);
    return sum / static_cast<double>(homework.size());
}

double Person::homeworkMedian() const {
    if (homework.empty()) return 0.0;
    std::vector<int> temp = homework;
    std::sort(temp.begin(), temp.end());
    size_t n = temp.size();
    if (n % 2 == 1) return static_cast<double>(temp[n/2]);
    return (temp[n/2 - 1] + temp[n/2]) / 2.0;
}

double Person::finalByAverage() const {
    if (homework.empty()) return 0.6 * exam;
    return 0.4 * homeworkAverage() + 0.6 * exam;
}

double Person::finalByMedian() const {
    if (homework.empty()) return 0.6 * exam;
    return 0.4 * homeworkMedian() + 0.6 * exam;
}

// Accessors
const std::string& Person::getFirstName() const { return firstName; }
const std::string& Person::getLastName() const  { return lastName; }
const std::vector<int>& Person::getHomework() const { return homework; }
int Person::getExam() const { return exam; }

void Person::setData(const std::string &fn, const std::string &ln,
                     const std::vector<int> &hw, int ex) {
    firstName = fn;
    lastName = ln;
    homework = hw;
    exam = ex;
}

void Person::clearHomework() { homework.clear(); }

// operator>> assumes Person::fileHomeworkCount is set appropriately before reading
std::istream& operator>>(std::istream &is, Person &p) {
    p.homework.clear();
    if (!(is >> p.firstName)) return is; // failed or EOF
    if (!(is >> p.lastName)) return is;

    // Read exactly fileHomeworkCount integers for homework
    for (int i = 0; i < Person::fileHomeworkCount; ++i) {
        int g;
        if (!(is >> g)) { // if unexpected EOF, set failbit and return
            is.setstate(std::ios::failbit);
            return is;
        }
        p.homework.push_back(g);
    }

    // read exam
    if (!(is >> p.exam)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    return is;
}

// operator<< prints name, surname, final(avg) and final(med) in aligned columns
std::ostream& operator<<(std::ostream &os, const Person &p) {
    os << std::left << std::setw(12) << p.firstName
       << std::setw(12) << p.lastName
       << std::right << std::setw(14) << std::fixed << std::setprecision(2) << p.finalByAverage()
       << " | " << std::setw(12) << std::fixed << std::setprecision(2) << p.finalByMedian();
    return os;
}
