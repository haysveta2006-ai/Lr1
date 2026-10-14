#pragma once
#include <string>
#include "Base.h"

class Keeper {
private:
    Base** items;
    int count;
    int capacity;
    void resize();

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void add(Base* obj);
    void remove(int index);
    void printAll() const;
    void edit(int index);
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);

    int getCount() const;
    Base* getAt(int index) const;
};