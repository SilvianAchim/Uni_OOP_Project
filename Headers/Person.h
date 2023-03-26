#pragma once
#include <iostream>
#include <string>

class Person
{
public:
    std::string Name;
    unsigned int Age;

    Person(std::string name, unsigned int age);
    Person(std::string name, unsigned int age, unsigned long long cnp);
    Person(const Person& other);
    ~Person();

    bool operator==(const Person& person) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    unsigned long long _cnp;
    std::string _email;

    static unsigned long long GenerateRandomCnp();
};

