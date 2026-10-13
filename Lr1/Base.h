#pragma once

class Base
{
public:
    Base();
    Base(const Base& other);
    virtual ~Base();

    virtual void print() const = 0;
};