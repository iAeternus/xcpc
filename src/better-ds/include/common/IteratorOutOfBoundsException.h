/**
 * @brief 迭代器越界异常
 * @author Ricky
 * @date 2024/6/24
 * @version 1.0
 */
#ifndef ITERATOR_OUT_OF_BOUNDS_EXCEPTION_H
#define ITERATOR_OUT_OF_BOUNDS_EXCEPTION_H

#include <exception>
#include <string>

#include "ExceptionCode.h"

class IteratorOutOfBoundsException : public std::exception {
public:
    IteratorOutOfBoundsException();
    IteratorOutOfBoundsException(const std::string& arg);

    const char* what() const noexcept override;
private:
    ExceptionCode m_code;
    std::string m_arg;
};

#endif  // ITERATOR_OUT_OF_BOUNDS_EXCEPTION_H