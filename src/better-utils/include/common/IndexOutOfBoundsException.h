/**
 * @brief 索引越界异常
 * @author Ricky
 * @date 2024/11/3
 * @version 1.0
 */
#ifndef INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include <exception>
#include <string>

#include "ExceptionCode.h"

class IndexOutOfBoundsException : public std::exception {
public:
    IndexOutOfBoundsException();
    IndexOutOfBoundsException(const std::string& arg);

    const char* what() const noexcept override;
private:
    ExceptionCode m_code;
    std::string m_arg;
};

#endif  // INDEX_OUT_OF_BOUNDS_EXCEPTION_H