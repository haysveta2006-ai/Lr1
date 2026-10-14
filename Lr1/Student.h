#pragma once
#include <string>     // ← ВОТ ЭТУ СТРОКУ ДОБАВИЛИ
#include "Base.h"

class Student : public Base {
private:
    std::string group;
    std::string specialty;
    int course;
    double averageScore;

public:
    Student();
    Student(const std::string& name, const std::string& group,
        const std::string& specialty, int course, double avg);
    Student(const Student& other);
    ~Student() override;

    void setGroup(const std::string& g);
    std::string getGroup() const;
    void setSpecialty(const std::string& s);
    std::string getSpecialty() const;
    void setCourse(int c);
    int getCourse() const;
    void setAverageScore(double a);
    double getAverageScore() const;

    void print() const override;
    void read() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::string getType() const override;
};