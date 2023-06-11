#include <iostream>
#include "../Headers/Logger.h"

template<typename T>
void Logger<T>::LogInformation(const std::string& information) {
    std::cout << type << delimitator << information << std::endl;
}

template<typename T>
void Logger<T>::LogError(const std::string& error) {
    std::cerr << "\033[31m" << type << delimitator << error << "\033[0m" << std::endl;
}

template<typename T>
void Logger<T>::LogSuccess(const std::string &success) {
    std::cout << "\033[32m" << type << delimitator<< success << "\033[0m" << std::endl;
}

template<typename T>
void Logger<T>::LogWarning(const std::string &warning) {
    std::cout << "\033[33m" << type << delimitator << warning << "\033[0m" << std::endl;
}

template<typename T>
std::string Logger<T>::GetType() {
    return typeid(T).name();
}