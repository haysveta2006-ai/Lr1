#pragma once
#include <string>
#include "Base.h"

class Teacher : public Base {
private:
    std::string* groups;
    int groupsCount;
    std::string* subjects;
    int subjectsCount;

public:
    Teacher();
    Teacher(const std::string& name,
        const std::string* grps, int grpCount,
        const std::string* subs, int subCount);
    Teacher(const Teacher& other);
    ~Teacher() override;

    void setGroups(const std::string* grps, int count);
    std::string* getGroups() const;
    int getGroupsCount() const;
    void setSubjects(const std::string* subs, int count);
    std::string* getSubjects() const;
    int getSubjectsCount() const;

    void print() const override;
    void read() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
};