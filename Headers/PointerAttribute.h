#pragma once
#include <memory>

template <typename T>
class PointerAttribute {
public:
    explicit PointerAttribute(std::shared_ptr<T> ptr) : _ptr(std::move(ptr)) {}

private:
    std::shared_ptr<T> _ptr;
};