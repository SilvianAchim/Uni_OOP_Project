#include "Logger.cpp"
#include "../Headers/BankAccount.h"
#include "../Headers/Bank.h"

template class Logger<BankAccount>;
template class Logger<void>;
template class Logger<Bank>;
