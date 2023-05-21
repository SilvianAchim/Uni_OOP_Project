#pragma once
#include <memory>

template <typename T>
class SharedPtrManager { //TODO: In working for tema 3
public:
    explicit SharedPtrManager(std::shared_ptr<T> ptr) : _ptr(std::move(ptr)) {}

private:
    std::shared_ptr<T> _ptr;
};