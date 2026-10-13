#include "Administrator.h"
#include <iostream>

Administrator::Administrator()
    : fullName(""), position(""), phone(""), responsibilityArea("")
{
    std::cout << "Вызван конструктор Administrator без параметров" << std::endl;
}

Administrator::Administrator(const std::string& fullName,
    const std::string& position,
    const std::string& phone,
    const std::string& responsibilityArea)
    : fullName(fullName),
    position(position),
    phone(phone),
    responsibilityArea(responsibilityArea)
{
    std::cout << "Вызван конструктор Administrator с параметрами" << std::endl;
}

Administrator::Administrator(const Administrator& other)
    : Base(other),
    fullName(other.fullName),
    position(other.position),
    phone(other.phone),
    responsibilityArea(other.responsibilityArea)
{
    std::cout << "Вызван конструктор копирования Administrator" << std::endl;
}

Administrator::~Administrator()
{
    std::cout << "Вызван деструктор Administrator" << std::endl;
}

void Administrator::print() const
{
    std::cout << "Административный сотрудник:" << std::endl;
    std::cout << "ФИО: " << fullName << std::endl;
    std::cout << "Должность: " << position << std::endl;
    std::cout << "Телефон: " << phone << std::endl;
    std::cout << "Область ответственности: "
        << responsibilityArea << std::endl;
}

void Administrator::setFullName(const std::string& fullName)
{
    this->fullName = fullName;
}

void Administrator::setPosition(const std::string& position)
{
    this->position = position;
}

void Administrator::setPhone(const std::string& phone)
{
    this->phone = phone;
}

void Administrator::setResponsibilityArea(
    const std::string& responsibilityArea)
{
    this->responsibilityArea = responsibilityArea;
}

std::string Administrator::getFullName() const
{
    return fullName;
}

std::string Administrator::getPosition() const
{
    return position;
}

std::string Administrator::getPhone() const
{
    return phone;
}

std::string Administrator::getResponsibilityArea() const
{
    return responsibilityArea;
}