#include "../Headers/Currency.h"

std::ostream& operator<<(std::ostream& os, const Currency& currency)
{
    os << "Nume: " << currency.Name << ", Simbol: " << currency.Symbol << "\n";
    return os;
}

