#include "IndexOutOfBoundsException.h"

IndexOutOfBoundsException::IndexOutOfBoundsException() {}

IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& arg)
    : m_code(ITERATOR_OUT_OF_BOUNDS_EXCEPTION), m_arg(arg) {}

const char* IndexOutOfBoundsException::what() const noexcept {
    const std::string text = "error code : " + std::to_string(m_code) + "\r\nerror message : " + m_arg;
    return text.c_str();
}