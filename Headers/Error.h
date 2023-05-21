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

class NonexistentAccount : public BaseError {
public:
    explicit NonexistentAccount(const std::string& msg) : BaseError(msg) {}
};

class AccountAlreadyExists : public BaseError {
public:
    explicit AccountAlreadyExists(const std::string& msg) : BaseError(msg) {}
};