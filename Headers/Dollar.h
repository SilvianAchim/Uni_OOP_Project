#pragma once

#include "Currency.h"

class Dollar : public Currency {
public:
    Dollar() : Currency("US Dollar", '$') {}

    double GetEuroConversionRate();
private:
};