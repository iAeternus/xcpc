#include "IteratorOutOfBoundsException.h"

IteratorOutOfBoundsException::IteratorOutOfBoundsException() {}

IteratorOutOfBoundsException::IteratorOutOfBoundsException(const std::string& arg)
    : m_code(ITERATOR_OUT_OF_BOUNDS_EXCEPTION), m_arg(arg) {}

const char* IteratorOutOfBoundsException::what() const noexcept {
    const std::string text = "error code : " + std::to_string(m_code) + "\r\nerror message : " + m_arg;
    return text.c_str();
}