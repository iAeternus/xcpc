/**
 * @brief 高精度整数类
 * @author ricky
 * @date 2024/10/7
 * @version 1.0
 */
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <iostream>

#define END_OF_NUM 0

class BigInteger {
public:
    using value_type = unsigned short;
    using const_value_type = const value_type;
    using pointer = value_type*;
    using const_pointer = const_value_type*;
    using reference = value_type&;
    using const_reference = const_value_type&;

    using reverse_iterator = __gnu_cxx::__normal_iterator<pointer, BigInteger>;
    using const_reverse_iterator = __gnu_cxx::__normal_iterator<const_pointer, BigInteger>;
    using iterator = std::reverse_iterator<reverse_iterator>;
    using const_iterator = std::reverse_iterator<const_reverse_iterator>;

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_iterator cbegin();
    const_iterator cend();
    const_reverse_iterator crbegin();
    const_reverse_iterator crend();

public:
    BigInteger& constructor(long long);
    BigInteger& constructor(const std::string&);

    BigInteger(long long = 0);
    BigInteger(const std::string&);
    BigInteger(const char*);
    BigInteger(const BigInteger&);
    ~BigInteger();

    BigInteger& operator=(const BigInteger&);

    BigInteger& add(const BigInteger&);
    BigInteger& subtract(const BigInteger&);
    BigInteger& multiply(const BigInteger&);
    BigInteger& divide(const BigInteger&);
    BigInteger& mod(const BigInteger&);
    BigInteger* divide_and_remainder(const BigInteger&);
    BigInteger& divide(const long long);
    BigInteger& mod(const long long);
    BigInteger* divide_and_remainder(const long long);

    BigInteger& operator+=(const BigInteger&);
    BigInteger& operator-=(const BigInteger&);
    BigInteger& operator*=(const BigInteger&);
    BigInteger& operator/=(const BigInteger&);
    BigInteger& operator%=(const BigInteger&);
    BigInteger& operator/=(const long long);
    BigInteger& operator%=(const long long);

    BigInteger& operator++();
    BigInteger operator++(int);
    BigInteger& operator--();
    BigInteger operator--(int);

    operator long long();
    operator std::string();
    operator bool();

    BigInteger& operator-();

    friend BigInteger operator+(const BigInteger&, const BigInteger&);
    friend BigInteger operator-(const BigInteger&, const BigInteger&);
    friend BigInteger operator*(const BigInteger&, const BigInteger&);
    friend BigInteger operator/(const BigInteger&, const BigInteger&);
    friend BigInteger operator%(const BigInteger&, const BigInteger&);
    friend BigInteger operator/(const BigInteger&, const long long);
    friend BigInteger operator%(const BigInteger&, const long long);
    friend bool operator>(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, const BigInteger&);
    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator!=(const BigInteger&, const BigInteger&);

    friend std::istream& operator>>(std::istream&, BigInteger&);
    friend std::ostream& operator<<(std::ostream&, const BigInteger&);

    unsigned short& operator[](size_t);

    long long to_integer(bool = true) const;
    std::string to_string() const;
    bool to_boolean() const;
    bool is_positive() const;
    bool is_negative() const;
    bool is_zero() const;
    bool is_one() const;
    bool is_within_long_long_range() const;
    size_t length() const;
    size_t size() const;
    int compare(const BigInteger&) const;
    void swap(BigInteger&);
    void clear();
    void resize(size_t);
    void set_positive(bool);
    void pop();
    void push(const unsigned short);
    bool empty();
    unsigned short front();
    unsigned short back();

private:
    value_type* __num = nullptr;
    size_t __num_length = 0, __num_size = 0;
    bool __flag = true;

    BigInteger** __new_bi_location = nullptr;
    size_t __new_bi_location_length = 0, __new_bi_location_size = 0;

    void __valid_number(const std::string&);

    void __location_push(BigInteger*);
    void __trim();

    size_t __newsize(unsigned short*&, size_t);
    size_t __resize(unsigned short*&, size_t, size_t);

    void __add(const BigInteger&, const BigInteger&, BigInteger&);
    void __subtract(const BigInteger&, const BigInteger&, BigInteger&);
    void __multiply(const BigInteger&, const BigInteger&, BigInteger&);
    void __divide_mod_bi(const BigInteger&, const BigInteger&, BigInteger&, BigInteger&);
    void __divide_mod_li(const BigInteger&, const long long, BigInteger&, BigInteger&);
};

#endif  // BIG_INTEGER_H