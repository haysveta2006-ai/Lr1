#include <iostream>
#include <limits>
#include <windows.h>
#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

void showMenu() {
    std::cout << "\n===== LAB 1 =====" << std::endl;
    std::cout << "1. Add student" << std::endl;
    std::cout << "2. Add teacher" << std::endl;
    std::cout << "3. Add administrator" << std::endl;
    std::cout << "4. Show all" << std::endl;
    std::cout << "5. Remove by index" << std::endl;
    std::cout << "6. Edit by index" << std::endl;
    std::cout << "7. Save to file" << std::endl;
    std::cout << "8. Load from file" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choice: ";
}

int main() {
    Keeper keeper;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Error: enter a number!" << std::endl;
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                Student* s = new Student();
                s->read();
                keeper.add(s);
                break;
            }
            case 2: {
                Teacher* t = new Teacher();
                t->read();
                keeper.add(t);
                break;
            }
            case 3: {
                Administrator* a = new Administrator();
                a->read();
                keeper.add(a);
                break;
            }
            case 4:
                keeper.printAll();
                break;
            case 5: {
                int idx;
                std::cout << "Enter index: ";
                std::cin >> idx;
                keeper.remove(idx);
                break;
            }
            case 6: {
                int idx;
                std::cout << "Enter index: ";
                std::cin >> idx;
                keeper.edit(idx);
                break;
            }
            case 7:
                keeper.saveToFile("data.txt");
                break;
            case 8:
                keeper.loadFromFile("data.txt");
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid menu item!" << std::endl;
            }
        }
        catch (std::exception& e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    }
    return 0;
}// Final version of Lab 1