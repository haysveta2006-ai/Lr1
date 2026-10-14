#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Base {
protected:
    std::string fullName;

public:
    Base();
    Base(const std::string& name);
    Base(const Base& other);
    virtual ~Base();

    void setFullName(const std::string& name);
    std::string getFullName() const;

    virtual void print() const = 0;
    virtual void read() = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
    virtual std::string getType() const = 0;
};