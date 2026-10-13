#pragma once

#include "Base.h"
#include <string>

class Teacher : public Base
{
private:
    std::string fullName;
    std::string groups;
    std::string subjects;

public:
    Teacher();

    Teacher(const std::string& fullName,
        const std::string& groups,
        const std::string& subjects);

    Teacher(const Teacher& other);

    ~Teacher() override;

    void print() const override;

    void setFullName(const std::string& fullName);
    void setGroups(const std::string& groups);
    void setSubjects(const std::string& subjects);

    std::string getFullName() const;
    std::string getGroups() const;
    std::string getSubjects() const;
};