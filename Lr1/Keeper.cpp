#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

Keeper::Keeper() : items(nullptr), size(0), capacity(2)
{
    items = new Base * [capacity];
    std::cout << "Вызван конструктор Keeper" << std::endl;
}

Keeper::Keeper(const Keeper& other)
    : items(nullptr), size(0), capacity(other.capacity)
{
    items = new Base * [capacity];

    try
    {
        for (int i = 0; i < other.size; i++)
        {
            if (Student* p = dynamic_cast<Student*>(other.items[i]))
                items[size++] = new Student(*p);
            else if (Teacher* p = dynamic_cast<Teacher*>(other.items[i]))
                items[size++] = new Teacher(*p);
            else if (Administrator* p =
                dynamic_cast<Administrator*>(other.items[i]))
                items[size++] = new Administrator(*p);
            else
                throw std::runtime_error("Неизвестный тип объекта.");
        }
    }
    catch (...)
    {
        for (int i = 0; i < size; i++)
            delete items[i];

        delete[] items;
        throw;
    }

    std::cout << "Вызван конструктор копирования Keeper" << std::endl;
}

Keeper& Keeper::operator=(const Keeper& other)
{
    if (this == &other)
        return *this;

    Keeper temp(other);

    Base** oldItems = items;
    int oldSize = size;
    int oldCapacity = capacity;

    items = temp.items;
    size = temp.size;
    capacity = temp.capacity;

    temp.items = oldItems;
    temp.size = oldSize;
    temp.capacity = oldCapacity;

    return *this;
}

Keeper::~Keeper()
{
    for (int i = 0; i < size; i++)
        delete items[i];

    delete[] items;

    std::cout << "Вызван деструктор Keeper" << std::endl;
}

void Keeper::resize()
{
    int newCapacity = capacity * 2;
    Base** newItems = new Base * [newCapacity];

    for (int i = 0; i < size; i++)
        newItems[i] = items[i];

    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

void Keeper::add(Base* item)
{
    if (item == nullptr)
        throw std::invalid_argument("Нельзя добавить пустой объект.");

    if (size == capacity)
        resize();

    items[size++] = item;
}

void Keeper::remove(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Неверный номер объекта.");

    delete items[index];

    for (int i = index; i < size - 1; i++)
        items[i] = items[i + 1];

    size--;
}

void Keeper::edit(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Неверный номер объекта.");

    if (Student* p = dynamic_cast<Student*>(items[index]))
    {
        std::string fullName, group, specialty;
        int course;
        double averageGrade;

        std::cout << "Введите ФИО: ";
        std::cin >> fullName;
        std::cout << "Введите группу: ";
        std::cin >> group;
        std::cout << "Введите специальность: ";
        std::cin >> specialty;
        std::cout << "Введите курс: ";

        if (!(std::cin >> course))
            throw std::invalid_argument("Курс должен быть числом.");

        std::cout << "Введите средний балл: ";

        if (!(std::cin >> averageGrade))
            throw std::invalid_argument("Средний балл должен быть числом.");

        if (course < 1 || averageGrade < 0 || averageGrade > 5)
            throw std::invalid_argument("Недопустимый курс или средний балл.");

        p->setFullName(fullName);
        p->setGroup(group);
        p->setSpecialty(specialty);
        p->setCourse(course);
        p->setAverageGrade(averageGrade);
    }
    else if (Teacher* p = dynamic_cast<Teacher*>(items[index]))
    {
        std::string fullName, groups, subjects;

        std::cout << "Введите ФИО: ";
        std::cin >> fullName;
        std::cout << "Введите группы: ";
        std::cin >> groups;
        std::cout << "Введите предметы: ";
        std::cin >> subjects;

        p->setFullName(fullName);
        p->setGroups(groups);
        p->setSubjects(subjects);
    }
    else if (Administrator* p =
        dynamic_cast<Administrator*>(items[index]))
    {
        std::string fullName, position, phone, area;

        std::cout << "Введите ФИО: ";
        std::cin >> fullName;
        std::cout << "Введите должность: ";
        std::cin >> position;
        std::cout << "Введите телефон: ";
        std::cin >> phone;
        std::cout << "Введите область ответственности: ";
        std::cin >> area;

        p->setFullName(fullName);
        p->setPosition(position);
        p->setPhone(phone);
        p->setResponsibilityArea(area);
    }
    else
    {
        throw std::runtime_error("Неизвестный тип объекта.");
    }

    std::cout << "Объект изменён." << std::endl;
}

void Keeper::print() const
{
    if (size == 0)
    {
        std::cout << "Список пуст." << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << "\nОбъект №" << i + 1 << std::endl;
        items[i]->print();
    }
}

int Keeper::getSize() const
{
    return size;
}

void Keeper::saveToFile(const char* filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Не удалось открыть файл для сохранения.");

    file << size << '\n';

    for (int i = 0; i < size; i++)
    {
        if (Student* p = dynamic_cast<Student*>(items[i]))
        {
            file << "STUDENT\n"
                << p->getFullName() << '\n'
                << p->getGroup() << '\n'
                << p->getSpecialty() << '\n'
                << p->getCourse() << '\n'
                << p->getAverageGrade() << '\n';
        }
        else if (Teacher* p = dynamic_cast<Teacher*>(items[i]))
        {
            file << "TEACHER\n"
                << p->getFullName() << '\n'
                << p->getGroups() << '\n'
                << p->getSubjects() << '\n';
        }
        else if (Administrator* p =
            dynamic_cast<Administrator*>(items[i]))
        {
            file << "ADMINISTRATOR\n"
                << p->getFullName() << '\n'
                << p->getPosition() << '\n'
                << p->getPhone() << '\n'
                << p->getResponsibilityArea() << '\n';
        }
    }

    if (!file)
        throw std::runtime_error("Ошибка записи в файл.");

    std::cout << "Данные сохранены в файл." << std::endl;
}

void Keeper::loadFromFile(const char* filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Не удалось открыть файл для загрузки.");

    int count;

    if (!(file >> count) || count < 0)
        throw std::runtime_error("Некорректный файл.");

    file.ignore(10000, '\n');

    Keeper loaded;

    for (int i = 0; i < count; i++)
    {
        std::string type;

        if (!std::getline(file, type))
            throw std::runtime_error("Не удалось прочитать тип объекта.");

        if (type == "STUDENT")
        {
            std::string fullName, group, specialty;
            int course;
            double averageGrade;

            if (!std::getline(file, fullName) ||
                !std::getline(file, group) ||
                !std::getline(file, specialty) ||
                !(file >> course >> averageGrade))
                throw std::runtime_error("Ошибка чтения данных студента.");

            file.ignore(10000, '\n');

            loaded.add(new Student(
                fullName, group, specialty, course, averageGrade));
        }
        else if (type == "TEACHER")
        {
            std::string fullName, groups, subjects;

            if (!std::getline(file, fullName) ||
                !std::getline(file, groups) ||
                !std::getline(file, subjects))
                throw std::runtime_error("Ошибка чтения данных преподавателя.");

            loaded.add(new Teacher(fullName, groups, subjects));
        }
        else if (type == "ADMINISTRATOR")
        {
            std::string fullName, position, phone, area;

            if (!std::getline(file, fullName) ||
                !std::getline(file, position) ||
                !std::getline(file, phone) ||
                !std::getline(file, area))
                throw std::runtime_error("Ошибка чтения данных сотрудника.");

            loaded.add(new Administrator(
                fullName, position, phone, area));
        }
        else
        {
            throw std::runtime_error("Неизвестный тип объекта в файле.");
        }
    }

    Base** oldItems = items;
    int oldSize = size;
    int oldCapacity = capacity;

    items = loaded.items;
    size = loaded.size;
    capacity = loaded.capacity;

    loaded.items = oldItems;
    loaded.size = oldSize;
    loaded.capacity = oldCapacity;

    std::cout << "Данные загружены из файла." << std::endl;
}