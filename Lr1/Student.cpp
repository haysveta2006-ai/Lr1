#include "Student.h"

Student::Student() : Base(), group(""), specialty(""), course(0), averageScore(0.0) {
    std::cout << "[Student] Default constructor" << std::endl;
}

Student::Student(const std::string& name, const std::string& group,
    const std::string& specialty, int course, double avg)
    : Base(name), group(group), specialty(specialty), course(course), averageScore(avg) {
    std::cout << "[Student] Param constructor" << std::endl;
}

Student::Student(const Student& other)
    : Base(other), group(other.group), specialty(other.specialty),
    course(other.course), averageScore(other.averageScore) {
    std::cout << "[Student] Copy constructor" << std::endl;
}

Student::~Student() {
    std::cout << "[Student] Destructor" << std::endl;
}

void Student::setGroup(const std::string& g) { group = g; }
std::string Student::getGroup() const { return group; }
void Student::setSpecialty(const std::string& s) { specialty = s; }
std::string Student::getSpecialty() const { return specialty; }
void Student::setCourse(int c) { course = c; }
int Student::getCourse() const { return course; }
void Student::setAverageScore(double a) { averageScore = a; }
double Student::getAverageScore() const { return averageScore; }

void Student::print() const {
    std::cout << "=== Student ===" << std::endl;
    std::cout << "Full name: " << fullName << std::endl;
    std::cout << "Group: " << group << std::endl;
    std::cout << "Specialty: " << specialty << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Average score: " << averageScore << std::endl;
}

void Student::read() {
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "Enter group: ";
    std::getline(std::cin, group);
    std::cout << "Enter specialty: ";
    std::getline(std::cin, specialty);
    std::cout << "Enter course: ";
    std::cin >> course;
    std::cout << "Enter average score: ";
    std::cin >> averageScore;
}

void Student::save(std::ofstream& out) const {
    out << "Student" << std::endl;
    out << fullName << std::endl;
    out << group << std::endl;
    out << specialty << std::endl;
    out << course << std::endl;
    out << averageScore << std::endl;
}

void Student::load(std::ifstream& in) {
    std::getline(in, fullName);
    std::getline(in, group);
    std::getline(in, specialty);
    in >> course;
    in >> averageScore;
    in.ignore();
}

std::string Student::getType() const { return "Student"; }