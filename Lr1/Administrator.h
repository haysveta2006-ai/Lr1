#pragma once

#include "Base.h"
#include <string>

class Administrator : public Base
{
private:
    std::string fullName;
    std::string position;
    std::string phone;
    std::string responsibilityArea;

public:
    Administrator();

    Administrator(const std::string& fullName,
        const std::string& position,
        const std::string& phone,
        const std::string& responsibilityArea);

    Administrator(const Administrator& other);

    ~Administrator() override;

    void print() const override;

    void setFullName(const std::string& fullName);
    void setPosition(const std::string& position);
    void setPhone(const std::string& phone);
    void setResponsibilityArea(const std::string& responsibilityArea);

    std::string getFullName() const;
    std::string getPosition() const;
    std::string getPhone() const;
    std::string getResponsibilityArea() const;
};
