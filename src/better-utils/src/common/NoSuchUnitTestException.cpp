#include "NoSuchUnitTestException.h"

NoSuchUnitTestException::NoSuchUnitTestException() {}

NoSuchUnitTestException::NoSuchUnitTestException(const std::string& arg)
    : m_code(NO_SUCH_UNIT_TEST_EXCEPTION), m_arg(arg) {}

const char* NoSuchUnitTestException::what() const noexcept {
    const std::string text = "error code : " + std::to_string(m_code) + "\r\nerror message : " + m_arg;
    return text.c_str();
}