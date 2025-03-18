#include "Person.h"
#include <cstring>

bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.id < rhs.id;
}

bool operator>(const Person &lhs, const Person &rhs)
{
    return lhs.id > rhs.id;
}

bool operator==(const Person &lhs, const Person &rhs)
{
    return lhs.id == rhs.id;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "ID: " << person.id << ", Name: " << person.name << ", Age: " << person.age << "\n";
    return os;
}