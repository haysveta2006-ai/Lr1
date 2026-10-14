#pragma once
#include <string>
#include "Base.h"

class Administrator : public Base {
private:
    std::string position;
    std::string phone;
    std::string responsibility;

public:
    Administrator();
    Administrator(const std::string& name, const std::string& position,
        const std::string& phone, const std::string& responsibility);
    Administrator(const Administrator& other);
    ~Administrator() override;

    void setPosition(const std::string& p);
    std::string getPosition() const;
    void setPhone(const std::string& ph);
    std::string getPhone() const;
    void setResponsibility(const std::string& r);
    std::string getResponsibility() const;

    void print() const override;
    void read() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
};