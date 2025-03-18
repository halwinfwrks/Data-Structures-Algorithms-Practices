#if !defined(PERSON_H)
#define PERSON_H
#include <iostream>

class Person
{
    int id;
    int age;
    char* name;

public:
    Person(int id, int age, char* name) : id(id), age(age), name(name) {}
    int getId() { return id; }
    int getAge() { return age; }
    char* getName() { return name; }

    friend bool operator<(const Person &lhs, const Person &rhs);
    friend bool operator>(const Person &lhs, const Person &rhs);
    friend bool operator==(const Person &lhs, const Person &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};

#endif // PERSON_H
