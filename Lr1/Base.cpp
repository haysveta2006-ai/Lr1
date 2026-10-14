#include "Base.h"

Base::Base() : fullName("Unknown") {
    std::cout << "[Base] Default constructor" << std::endl;
}

Base::Base(const std::string& name) : fullName(name) {
    std::cout << "[Base] Param constructor" << std::endl;
}

Base::Base(const Base& other) : fullName(other.fullName) {
    std::cout << "[Base] Copy constructor" << std::endl;
}

Base::~Base() {
    std::cout << "[Base] Destructor" << std::endl;
}

void Base::setFullName(const std::string& name) { fullName = name; }
std::string Base::getFullName() const { return fullName; }