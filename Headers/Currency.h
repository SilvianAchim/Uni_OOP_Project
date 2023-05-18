#pragma once
#include <string>
#include <iostream>

class Currency
{
public:
    Currency(std::string name, const char symbol) : Name(std::move(name)), Symbol(symbol) {}
    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
private:
    std::string Name;
    char Symbol;
};

