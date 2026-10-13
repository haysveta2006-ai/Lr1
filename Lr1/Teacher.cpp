#include "Teacher.h"
#include <iostream>

Teacher::Teacher()
    : fullName(""), groups(""), subjects("")
{
    std::cout << "Вызван конструктор Teacher без параметров" << std::endl;
}

Teacher::Teacher(const std::string& fullName,
    const std::string& groups,
    const std::string& subjects)
    : fullName(fullName),
    groups(groups),
    subjects(subjects)
{
    std::cout << "Вызван конструктор Teacher с параметрами" << std::endl;
}

Teacher::Teacher(const Teacher& other)
    : Base(other),
    fullName(other.fullName),
    groups(other.groups),
    subjects(other.subjects)
{
    std::cout << "Вызван конструктор копирования Teacher" << std::endl;
}

Teacher::~Teacher()
{
    std::cout << "Вызван деструктор Teacher" << std::endl;
}

void Teacher::print() const
{
    std::cout << "Преподаватель:" << std::endl;
    std::cout << "ФИО: " << fullName << std::endl;
    std::cout << "Группы: " << groups << std::endl;
    std::cout << "Предметы: " << subjects << std::endl;
}

void Teacher::setFullName(const std::string& fullName)
{
    this->fullName = fullName;
}

void Teacher::setGroups(const std::string& groups)
{
    this->groups = groups;
}

void Teacher::setSubjects(const std::string& subjects)
{
    this->subjects = subjects;
}

std::string Teacher::getFullName() const
{
    return fullName;
}

std::string Teacher::getGroups() const
{
    return groups;
}

std::string Teacher::getSubjects() const
{
    return subjects;
}