#include <iostream>
#include <windows.h>
#include <string>
#include <exception>

#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Keeper keeper;
    int choice = -1;

    do
    {
        std::cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 1 =====\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Добавить преподавателя\n";
        std::cout << "3. Добавить административного сотрудника\n";
        std::cout << "4. Показать все объекты\n";
        std::cout << "5. Удалить объект\n";
        std::cout << "6. Изменить объект\n";
        std::cout << "7. Сохранить данные в файл\n";
        std::cout << "8. Загрузить данные из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка: введите число.\n";
            continue;
        }

        try
        {
            switch (choice)
            {
            case 1:
            {
                std::string fullName, group, specialty;
                int course;
                double averageGrade;

                std::cout << "Введите ФИО студента: ";
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
                    throw std::invalid_argument("Недопустимые значения курса или среднего балла.");

                keeper.add(new Student(fullName, group, specialty, course, averageGrade));
                std::cout << "Студент успешно добавлен.\n";
                break;
            }

            case 2:
            {
                std::string fullName, groups, subjects;
                std::cout << "Введите ФИО преподавателя: ";
                std::cin >> fullName;
                std::cout << "Введите группы: ";
                std::cin >> groups;
                std::cout << "Введите предметы: ";
                std::cin >> subjects;

                keeper.add(new Teacher(fullName, groups, subjects));
                std::cout << "Преподаватель успешно добавлен.\n";
                break;
            }

            case 3:
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

                keeper.add(new Administrator(fullName, position, phone, area));
                std::cout << "Административный сотрудник добавлен.\n";
                break;
            }

            case 4:
                keeper.print();
                break;

            case 5:
            {
                if (keeper.getSize() == 0)
                {
                    std::cout << "Список пуст.\n";
                    break;
                }

                keeper.print();
                int number;
                std::cout << "Введите номер объекта для удаления: ";
                if (!(std::cin >> number))
                    throw std::invalid_argument("Номер должен быть числом.");

                keeper.remove(number - 1);
                std::cout << "Объект удалён.\n";
                break;
            }

            case 6:
            {
                if (keeper.getSize() == 0)
                {
                    std::cout << "Список пуст.\n";
                    break;
                }

                keeper.print();
                int number;
                std::cout << "Введите номер объекта для изменения: ";
                if (!(std::cin >> number))
                    throw std::invalid_argument("Номер должен быть числом.");

                keeper.edit(number - 1);
                break;
            }

            case 7:
                keeper.saveToFile("university_data.txt");
                break;

            case 8:
                keeper.loadFromFile("university_data.txt");
                break;

            case 0:
                std::cout << "Выход из программы.\n";
                break;

            default:
                std::cout << "Такого пункта меню нет.\n";
                break;
            }
        }
        catch (const std::exception& error)
        {
            std::cout << "Ошибка: " << error.what() << '\n';

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }

    } while (choice != 0);

    return 0;
}
