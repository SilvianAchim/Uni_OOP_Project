#pragma once

#include "Currency.h"

class Dollar : public Currency {
private:
    Dollar() : Currency("US Dollar", '$') {}
public:
    Dollar(const Dollar&) = delete;
    Dollar& operator=(const Dollar&) = delete;
    static Dollar& GetDollar() {
        static Dollar dollar;
        return dollar;
    }
    double GetEuroConversionRate();
};