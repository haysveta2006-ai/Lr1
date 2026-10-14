#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include <iostream>
#include <fstream>
#include <exception>

class KeeperException : public std::exception {
    std::string msg;
public:
    KeeperException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

Keeper::Keeper() : items(nullptr), count(0), capacity(0) {
    std::cout << "[Keeper] Default constructor" << std::endl;
}

Keeper::Keeper(const Keeper& other) : items(nullptr), count(0), capacity(0) {
    std::cout << "[Keeper] Copy constructor" << std::endl;
    for (int i = 0; i < other.count; ++i) add(other.items[i]);
}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i) delete items[i];
    delete[] items;
    std::cout << "[Keeper] Destructor" << std::endl;
}

void Keeper::resize() {
    int newCap = (capacity == 0) ? 4 : capacity * 2;
    Base** newItems = new Base * [newCap];
    for (int i = 0; i < count; ++i) newItems[i] = items[i];
    delete[] items;
    items = newItems;
    capacity = newCap;
}

void Keeper::add(Base* obj) {
    if (count >= capacity) resize();
    items[count++] = obj;
    std::cout << "Object added. Total: " << count << std::endl;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= count)
        throw KeeperException("Invalid index for remove!");
    delete items[index];
    for (int i = index; i < count - 1; ++i) items[i] = items[i + 1];
    --count;
    std::cout << "Object removed." << std::endl;
}

void Keeper::printAll() const {
    if (count == 0) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "--- #" << i << " ---" << std::endl;
        items[i]->print();
    }
}

void Keeper::edit(int index) {
    if (index < 0 || index >= count)
        throw KeeperException("Invalid index for edit!");
    items[index]->read();
}

void Keeper::saveToFile(const char* filename) const {
    std::ofstream out(filename);
    if (!out.is_open())
        throw KeeperException("Cannot open file for writing!");
    out << count << std::endl;
    for (int i = 0; i < count; ++i) items[i]->save(out);
    out.close();
    std::cout << "Data saved." << std::endl;
}

void Keeper::loadFromFile(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open())
        throw KeeperException("Cannot open file for reading!");

    for (int i = 0; i < count; ++i) delete items[i];
    delete[] items;
    items = nullptr;
    count = 0;
    capacity = 0;

    int newCount;
    in >> newCount;
    in.ignore();

    for (int i = 0; i < newCount; ++i) {
        std::string type;
        std::getline(in, type);
        Base* obj = nullptr;
        if (type == "Student") obj = new Student();
        else if (type == "Teacher") obj = new Teacher();
        else if (type == "Administrator") obj = new Administrator();
        else throw KeeperException("Unknown type in file: " + type);
        obj->load(in);
        add(obj);
    }
    in.close();
    std::cout << "Data loaded." << std::endl;
}

int Keeper::getCount() const { return count; }
Base* Keeper::getAt(int index) const {
    if (index < 0 || index >= count) throw KeeperException("Invalid index!");
    return items[index];
}