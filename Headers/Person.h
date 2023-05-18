#pragma once
#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string name, unsigned int age);
    ~Person();
    std::string GetName() const;
    bool operator==(const Person& person) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string Name;
    unsigned int Age;
    unsigned long long Cnp;
    std::string Email;

    static unsigned long long GenerateRandomCnp();
};

