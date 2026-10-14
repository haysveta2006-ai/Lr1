#include "Administrator.h"

Administrator::Administrator()
    : Base(), position(""), phone(""), responsibility("") {
    std::cout << "[Administrator] Default constructor" << std::endl;
}

Administrator::Administrator(const std::string& name, const std::string& position,
    const std::string& phone, const std::string& responsibility)
    : Base(name), position(position), phone(phone), responsibility(responsibility) {
    std::cout << "[Administrator] Param constructor" << std::endl;
}

Administrator::Administrator(const Administrator& other)
    : Base(other), position(other.position), phone(other.phone),
    responsibility(other.responsibility) {
    std::cout << "[Administrator] Copy constructor" << std::endl;
}

Administrator::~Administrator() {
    std::cout << "[Administrator] Destructor" << std::endl;
}

void Administrator::setPosition(const std::string& p) { position = p; }
std::string Administrator::getPosition() const { return position; }
void Administrator::setPhone(const std::string& ph) { phone = ph; }
std::string Administrator::getPhone() const { return phone; }
void Administrator::setResponsibility(const std::string& r) { responsibility = r; }
std::string Administrator::getResponsibility() const { return responsibility; }

void Administrator::print() const {
    std::cout << "=== Administrator ===" << std::endl;
    std::cout << "Full name: " << fullName << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Responsibility area: " << responsibility << std::endl;
}

void Administrator::read() {
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter responsibility area: ";
    std::getline(std::cin, responsibility);
}

void Administrator::save(std::ofstream& out) const {
    out << "Administrator" << std::endl;
    out << fullName << std::endl;
    out << position << std::endl;
    out << phone << std::endl;
    out << responsibility << std::endl;
}

void Administrator::load(std::ifstream& in) {
    std::getline(in, fullName);
    std::getline(in, position);
    std::getline(in, phone);
    std::getline(in, responsibility);
}

std::string Administrator::getType() const { return "Administrator"; }