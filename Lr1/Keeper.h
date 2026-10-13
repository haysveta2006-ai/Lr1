#pragma once

#include "Base.h"

class Keeper
{
private:
    Base** items;
    int size;
    int capacity;

    void resize();

public:
    Keeper();
    Keeper(const Keeper& other);
    Keeper& operator=(const Keeper& other);
    ~Keeper();

    void add(Base* item);
    void remove(int index);
    void edit(int index);
    void print() const;

    int getSize() const;

    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};