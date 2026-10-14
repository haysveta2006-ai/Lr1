#include "Teacher.h"

static std::string* copyArray(const std::string* src, int count) {
    if (count <= 0 || src == nullptr) return nullptr;
    std::string* dst = new std::string[count];
    for (int i = 0; i < count; ++i) dst[i] = src[i];
    return dst;
}

Teacher::Teacher() : Base(), groups(nullptr), groupsCount(0),
subjects(nullptr), subjectsCount(0) {
    std::cout << "[Teacher] Default constructor" << std::endl;
}

Teacher::Teacher(const std::string& name,
    const std::string* grps, int grpCount,
    const std::string* subs, int subCount)
    : Base(name), groups(copyArray(grps, grpCount)), groupsCount(grpCount),
    subjects(copyArray(subs, subCount)), subjectsCount(subCount) {
    std::cout << "[Teacher] Param constructor" << std::endl;
}

Teacher::Teacher(const Teacher& other)
    : Base(other), groups(copyArray(other.groups, other.groupsCount)),
    groupsCount(other.groupsCount),
    subjects(copyArray(other.subjects, other.subjectsCount)),
    subjectsCount(other.subjectsCount) {
    std::cout << "[Teacher] Copy constructor" << std::endl;
}

Teacher::~Teacher() {
    delete[] groups;
    delete[] subjects;
    std::cout << "[Teacher] Destructor" << std::endl;
}

void Teacher::setGroups(const std::string* grps, int count) {
    delete[] groups;
    groups = copyArray(grps, count);
    groupsCount = count;
}
std::string* Teacher::getGroups() const { return groups; }
int Teacher::getGroupsCount() const { return groupsCount; }

void Teacher::setSubjects(const std::string* subs, int count) {
    delete[] subjects;
    subjects = copyArray(subs, count);
    subjectsCount = count;
}
std::string* Teacher::getSubjects() const { return subjects; }
int Teacher::getSubjectsCount() const { return subjectsCount; }

void Teacher::print() const {
    std::cout << "=== Teacher ===" << std::endl;
    std::cout << "Full name: " << fullName << std::endl;
    std::cout << "Groups (" << groupsCount << "): ";
    for (int i = 0; i < groupsCount; ++i) std::cout << groups[i] << "; ";
    std::cout << std::endl;
    std::cout << "Subjects (" << subjectsCount << "): ";
    for (int i = 0; i < subjectsCount; ++i) std::cout << subjects[i] << "; ";
    std::cout << std::endl;
}

void Teacher::read() {
    std::cout << "Enter full name: ";
    std::cin.ignore();
    std::getline(std::cin, fullName);
    std::cout << "How many groups? ";
    std::cin >> groupsCount;
    std::cin.ignore();
    delete[] groups;
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) {
        std::cout << "Group " << (i + 1) << ": ";
        std::getline(std::cin, groups[i]);
    }
    std::cout << "How many subjects? ";
    std::cin >> subjectsCount;
    std::cin.ignore();
    delete[] subjects;
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) {
        std::cout << "Subject " << (i + 1) << ": ";
        std::getline(std::cin, subjects[i]);
    }
}

void Teacher::save(std::ofstream& out) const {
    out << "Teacher" << std::endl;
    out << fullName << std::endl;
    out << groupsCount << std::endl;
    for (int i = 0; i < groupsCount; ++i) out << groups[i] << std::endl;
    out << subjectsCount << std::endl;
    for (int i = 0; i < subjectsCount; ++i) out << subjects[i] << std::endl;
}

void Teacher::load(std::ifstream& in) {
    std::getline(in, fullName);
    in >> groupsCount;
    in.ignore();
    delete[] groups;
    groups = new std::string[groupsCount];
    for (int i = 0; i < groupsCount; ++i) std::getline(in, groups[i]);
    in >> subjectsCount;
    in.ignore();
    delete[] subjects;
    subjects = new std::string[subjectsCount];
    for (int i = 0; i < subjectsCount; ++i) std::getline(in, subjects[i]);
}

std::string Teacher::getType() const { return "Teacher"; }