/**
 * @brief 单元测试不存在异常
 * @author Ricky
 * @date 2024/10/18
 * @version 1.0
 */
#ifndef NO_SUCH_UNIT_TEST_EXCEPTION_H
#define NO_SUCH_UNIT_TEST_EXCEPTION_H

#include <exception>
#include <string>

#include "ExceptionCode.h"

class NoSuchUnitTestException : public std::exception {
public:
    NoSuchUnitTestException();
    NoSuchUnitTestException(const std::string& arg);

    const char* what() const noexcept override;
private:
    ExceptionCode m_code;
    std::string m_arg;
};

#endif // NO_SUCH_UNIT_TEST_EXCEPTION_H