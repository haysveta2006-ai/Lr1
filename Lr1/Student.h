#pragma once

#include "Base.h"
#include <string>

class Student : public Base
{
private:
    std::string fullName;
    std::string group;
    std::string specialty;
    int course;
    double averageGrade;

public:
    Student();
    Student(const std::string& fullName,
        const std::string& group,
        const std::string& specialty,
        int course,
        double averageGrade);

    Student(const Student& other);

    ~Student() override;

    void print() const override;

    void setFullName(const std::string& fullName);
    void setGroup(const std::string& group);
    void setSpecialty(const std::string& specialty);
    void setCourse(int course);
    void setAverageGrade(double averageGrade);

    std::string getFullName() const;
    std::string getGroup() const;
    std::string getSpecialty() const;
    int getCourse() const;
    double getAverageGrade() const;
};