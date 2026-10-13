#include "Student.h"
#include <iostream>

Student::Student()
    : fullName(""),
    group(""),
    specialty(""),
    course(1),
    averageGrade(0.0)
{
    std::cout << "Вызван конструктор Student без параметров" << std::endl;
}

Student::Student(const std::string& fullName,
    const std::string& group,
    const std::string& specialty,
    int course,
    double averageGrade)
    : fullName(fullName),
    group(group),
    specialty(specialty),
    course(course),
    averageGrade(averageGrade)
{
    std::cout << "Вызван конструктор Student с параметрами" << std::endl;
    std::cout << "Полученное ФИО: " << this->fullName << std::endl;
}

Student::Student(const Student& other)
    : Base(other),
    fullName(other.fullName),
    group(other.group),
    specialty(other.specialty),
    course(other.course),
    averageGrade(other.averageGrade)
{
    std::cout << "Вызван конструктор копирования Student" << std::endl;
}

Student::~Student()
{
    std::cout << "Вызван деструктор Student" << std::endl;
}

void Student::print() const
{
    std::cout << "Студент:" << std::endl;
    std::cout << "ФИО: " << fullName << std::endl;
    std::cout << "Группа: " << group << std::endl;
    std::cout << "Специальность: " << specialty << std::endl;
    std::cout << "Курс: " << course << std::endl;
    std::cout << "Средний балл: " << averageGrade << std::endl;
}

void Student::setFullName(const std::string& fullName)
{
    this->fullName = fullName;
}

void Student::setGroup(const std::string& group)
{
    this->group = group;
}

void Student::setSpecialty(const std::string& specialty)
{
    this->specialty = specialty;
}

void Student::setCourse(int course)
{
    this->course = course;
}

void Student::setAverageGrade(double averageGrade)
{
    this->averageGrade = averageGrade;
}

std::string Student::getFullName() const
{
    return fullName;
}

std::string Student::getGroup() const
{
    return group;
}

std::string Student::getSpecialty() const
{
    return specialty;
}

int Student::getCourse() const
{
    return course;
}

double Student::getAverageGrade() const
{
    return averageGrade;
}
