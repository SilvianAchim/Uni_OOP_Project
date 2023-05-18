#include "../Headers/Person.h"

Person::Person(std::string name, const unsigned age): Name(std::move(name)), Age(age), Cnp(GenerateRandomCnp())
{
    std::cout << "Constr Student without Cnp\n";
}

Person::~Person()
{
    std::cout << "Destructor Person\n";
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Nume: " << person.Name << ", Varsta: " << person.Age << "\n";
    return os;
}
    
bool Person::operator==(const Person& person) const
{
    return Cnp == person.Cnp;
}

unsigned long long Person::GenerateRandomCnp()
{
    return rand() % 1000; // NOLINT(cert-msc50-cpp)
}

std::string Person::GetName() const {
    return Name;
}
