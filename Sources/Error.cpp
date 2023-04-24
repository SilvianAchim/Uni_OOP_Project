#include "../Headers/Error.h"

const char *BaseError::what() const noexcept {
    return message.c_str();
}
