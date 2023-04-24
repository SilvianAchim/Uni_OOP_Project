#pragma once
#include <exception>
#include <string>

class BaseError : public std::exception {
public:
    explicit BaseError(std::string msg) : message(std::move(msg)) {}
    const char* what() const noexcept override;

private:
    std::string message;
};

class AccountError : public BaseError {
public:
    explicit AccountError(const std::string& msg) : BaseError(msg) {}
};

class BankAccountError : public BaseError {
public:
    explicit BankAccountError(const std::string& msg) : BaseError(msg) {}
};