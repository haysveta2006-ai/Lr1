#include "Base.h"
#include <iostream>

Base::Base()
{
    std::cout << "Вызван конструктор Base без параметров" << std::endl;
}

Base::Base(const Base& other)
{
    std::cout << "Вызван конструктор копирования Base" << std::endl;
}

Base::~Base()
{
    std::cout << "Вызван деструктор Base" << std::endl;
}