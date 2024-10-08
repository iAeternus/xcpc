#include <cctype>
#include <iostream>
#include <stdexcept>
#include <cstring>

#include "BigInteger.h"

BigInteger::iterator BigInteger::begin() {
    return iterator(this->rend());
}

BigInteger::iterator BigInteger::end() {
    this->__num[-1] = END_OF_NUM;
    return iterator(this->rbegin());
}

BigInteger::reverse_iterator BigInteger::rbegin() {
    return reverse_iterator(this->__num);
}

BigInteger::reverse_iterator BigInteger::rend() {
    this->__num[this->__num_length] = END_OF_NUM;
    return reverse_iterator(this->__num + this->__num_length);
}

BigInteger::const_iterator BigInteger::cbegin() {
    return const_iterator(this->crend());
}

BigInteger::const_iterator BigInteger::cend() {
    this->__num[-1] = END_OF_NUM;
    return const_iterator(this->crbegin());
}

BigInteger::const_reverse_iterator BigInteger::crbegin() {
    return const_reverse_iterator(this->__num);
}

BigInteger::const_reverse_iterator BigInteger::crend() {
    this->__num[this->__num_length] = END_OF_NUM;
    return const_reverse_iterator(this->__num + this->__num_length);
}

BigInteger& BigInteger::constructor(long long num) {
    if (this->__num_size < 20) {
        this->__num_size = this->__newsize(this->__num, 20);
    }
    this->__num_length = 0;
    if (!num) {
        this->__flag = true;
        this->__num[this->__num_length++] = END_OF_NUM;
    } else {
        if (num < 0) {
            this->__flag = false;
            num = -num;
        } else {
            this->__flag = true;
        }

        while (num) {
            this->__num[this->__num_length++] = num % 10;
            num /= 10;
        }
    }
    return *this;
}

BigInteger& BigInteger::constructor(const std::string& str) {
    this->__valid_number(str);
    int start_index = 0, str_length = str.length();
    if (str[0] == '-') {
        this->__flag = false;
        ++start_index;
    } else {
        this->__flag = true;
    }

    while (str[start_index] == '0') {
        ++start_index;
    }
    if (this->__num_size < str_length - start_index + 1) {
        this->__num_size = this->__newsize(this->__num, str_length - start_index + 1);
    }
    this->__num_length = 0;

    for (int i = str_length - 1; i >= start_index; --i) {
        this->__num[this->__num_length++] = str[i] - '0';
    }

    if (!this->__num_length) {
        this->__num[this->__num_length++] = END_OF_NUM;
    }
    return *this;
}

BigInteger::BigInteger(long long num) {
    this->constructor(num);
}

BigInteger::BigInteger(const std::string& str) {
    this->constructor(str);
}

BigInteger::BigInteger(const char* str) {
    this->constructor(str);
}

BigInteger::BigInteger(const BigInteger& bi) {
    this->__num_size = this->__newsize(this->__num, bi.__num_size);
    memcpy(this->__num, bi.__num, bi.__num_length * sizeof(unsigned short));
    this->__num_length = bi.__num_length;
    this->__flag = bi.__flag;
}

BigInteger& BigInteger::operator=(const BigInteger& bi) {
    if (this != &bi) {
        this->__num_size = this->__newsize(this->__num, bi.__num_size);
        memcpy(this->__num, bi.__num, bi.__num_length * sizeof(unsigned short));
        this->__num_length = bi.__num_length;
        this->__flag = bi.__flag;
    }
    return *this;
}

BigInteger::~BigInteger() {
    delete[] this->__num;
    this->__num = nullptr;
    for (int i = 0; i < this->__new_bi_location_length; i++) {
        delete[] this->__new_bi_location[i];
        this->__new_bi_location[i] = nullptr;
    }
    delete[] this->__new_bi_location;
    this->__new_bi_location = nullptr;
}

BigInteger& BigInteger::add(const BigInteger& bi) {
    if (bi.__flag == this->__flag) {
        this->__add(*this, bi, *this);
    } else if (bi.is_positive()) {
        this->__flag = true;
        this->swap(BigInteger(bi).subtract(*this));
    } else {
        BigInteger& tmp = const_cast<BigInteger&>(bi);
        tmp.__flag = true;
        this->subtract(tmp);
        tmp.__flag = false;
    }
    return *this;
}

BigInteger& BigInteger::subtract(const BigInteger& bi) {
    if (bi.__flag == this->__flag) {
        int cmp = this->compare(bi);
        if(cmp > 0) {
            if(this->is_positive()) {
                this->__subtract(*this, bi, *this);
            } else {
                this->__subtract(bi, *this, *this);
            }
        } else if(cmp < 0) {
            if(this->is_positive()) {
                this->__subtract(bi, *this, *this);
            } else {
                this->__subtract(*this, bi, *this);
            }
            this->__flag = false;
        } else {
            this->clear();
        }
    } else {
        this->__add(*this, bi, *this);
    }
    return *this;
}

BigInteger& BigInteger::multiply(const BigInteger& bi) {
    if(this->is_zero() || bi.is_zero()) {
        this->clear();
    } else if(this->is_one()) {
        bool this_flag = this->__flag;
        BigInteger ans(bi);
        this->swap(ans);
        this->__flag = bi.is_positive() ? this_flag : !this_flag;
    } else if(bi.is_one()) {
        this->__flag = bi.is_positive() ? this->__flag : !this->__flag;
        return *this;
    } else {
        bool this_flag = this->__flag;
        this->__multiply(*this, bi, *this);
        this->__flag = this_flag == bi.__flag;
    }
    return *this;
}

BigInteger& BigInteger::divide(const BigInteger& bi) {
    if(bi.is_zero()) {
        throw std::runtime_error("Divided by zero.");
    }

    if(bi.is_one()) {
        this->__flag = bi.__flag == this->__flag;
    } else {
        this->swap(this->divide_and_remainder(bi)[0]);
    }
    return *this;
}

BigInteger& BigInteger::mod(const BigInteger& bi) {
    if(bi.is_zero()) {
        throw std::runtime_error("Divided by zero.");
    }

    if(bi.is_one()) {
        this->clear();
    } else {
        this->swap(this->divide_and_remainder(bi)[1]);
    }
    return *this;
}

BigInteger* BigInteger::divide_and_remainder(const BigInteger& bi) {
    BigInteger* ans = new BigInteger[2];
    this->__location_push(ans);

    if(bi.is_zero()) {
        throw std::runtime_error("Divided by zero.");
    }

    if (bi.is_one()) {
        BigInteger temp(*this);
        ans[0].swap(temp);
        ans[0].__flag = bi.__flag == this->__flag;
    } else {
        bool this_flag = this->__flag;
        if (bi.__flag != this->__flag) {
            this->__flag = bi.__flag;
        }
        int cmp = this->compare(bi);
        if (cmp > 0) {
            if (bi.__flag) {
                this->__divide_mod_bi(*this, bi, ans[0], ans[1]);
                ans[0].__flag = this_flag == bi.__flag;
                ans[1].__flag = this_flag;
            } else {
                BigInteger temp(*this);
                ans[1].swap(temp);
            }
        } else if (cmp < 0) {
            if (bi.__flag) {
                BigInteger temp(*this);
                ans[1].swap(temp);
            } else {
                this->__divide_mod_bi(*this, bi, ans[0], ans[1]);
                ans[0].__flag = this_flag == bi.__flag;
                ans[1].__flag = this_flag;
            }
        } else
            ans[0] = this_flag == bi.__flag ? 1 : -1;
        this->__flag = this_flag;
    }
    return ans;
}

BigInteger& BigInteger::divide(const long long li) {
    if(li == 0) {
        throw std::runtime_error("Divided by zero.");
    }

    if (li == 1 || li == -1) {
        this->__flag = li > 0 ? this->__flag : !this->__flag;
    } else {
        this->swap(this->divide_and_remainder(li)[0]);
    }
    return *this;
}

BigInteger& BigInteger::mod(const long long li) {
    if(li == 0) {
        throw std::runtime_error("Divided by zero.");
    }

    if (li == 1 || li == -1) {
        this->clear();
    } else {
        this->swap(this->divide_and_remainder(li)[1]);
    }
    return *this;
}

BigInteger* BigInteger::divide_and_remainder(const long long li) {
    BigInteger* ans = new BigInteger[2];
    this->__location_push(ans);

    if(li == 0) {
        throw std::runtime_error("Divided by zero.");
    }

    bool li_flag = li > 0;
    if(li == 1 || li == -1) {
        BigInteger tmp(*this);
        ans[0].swap(tmp);
        ans[0].__flag = li_flag == this->__flag;
    } else {
        BigInteger bi(li);
        if(bi.length() > 18) {
            this->__divide_mod_bi(*this, bi, ans[0], ans[1]);
        } else {
            this->__divide_mod_li(*this, (li > 0 ? li : -li), ans[0], ans[1]);
        }
        ans[0].__flag = this->__flag == li_flag;
        ans[1].__flag = this->__flag;
    }
    return ans;
}

BigInteger& BigInteger::operator+=(const BigInteger& bi) {
    this->add(bi);
    return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& bi) {
    this->subtract(bi);
    return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& bi) {
    this->multiply(bi);
    return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& bi) {
    this->divide(bi);
    return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger& bi) {
    this->mod(bi);
    return *this;
}

BigInteger& BigInteger::operator/=(const long long li) {
    this->divide(li);
    return *this;
}

BigInteger& BigInteger::operator%=(const long long li) {
    this->mod(li);
    return *this;
}

BigInteger& BigInteger::operator++() {
    this->add(1);
    return *this;
}

BigInteger BigInteger::operator++(int) {
    BigInteger ans(*this);
    this->add(1);
    return *this;
}

BigInteger& BigInteger::operator--() {
    this->subtract(1);
    return *this;
}

BigInteger BigInteger::operator--(int) {
    BigInteger ans(*this);
    this->subtract(1);
    return *this;
}

BigInteger::operator long long() {
    return this->to_integer(false);
}

BigInteger::operator std::string() {
    return this->to_string();
}

BigInteger::operator bool() {
    return this->to_boolean();
}

BigInteger& BigInteger::operator-() {
    if (!(this->__num_length == 1 && this->__num[0] == END_OF_NUM)) {
        this->__flag = !this->__flag;
    }
    return *this;
}

BigInteger operator+(const BigInteger& bi_a, const BigInteger& bi_b) {
    BigInteger ans(bi_a);
    ans.add(bi_b);
    return ans;
}

BigInteger operator-(const BigInteger& bi_a, const BigInteger& bi_b) {
    BigInteger ans(bi_a);
    ans.subtract(bi_b);
    return ans;
}

BigInteger operator*(const BigInteger& bi_a, const BigInteger& bi_b) {
    BigInteger ans(bi_a);
    ans.multiply(bi_b);
    return ans;
}

BigInteger operator/(const BigInteger& bi_a, const BigInteger& bi_b) {
    BigInteger ans(bi_a);
    ans.divide(bi_b);
    return ans;
}

BigInteger operator%(const BigInteger& bi_a, const BigInteger& bi_b) {
    BigInteger ans(bi_a);
    ans.mod(bi_b);
    return ans;
}

BigInteger operator/(const BigInteger& bi_a, const long long li_b) {
    BigInteger ans(bi_a);
    ans.divide(li_b);
    return ans;
}

BigInteger operator%(const BigInteger& bi_a, const long long li_b) {
    BigInteger ans(bi_a);
    ans.mod(li_b);
    return ans;
}

bool operator>(const BigInteger& bi_a, const BigInteger& bi_b) {
    return bi_a.compare(bi_b) > 0;
}

bool operator<(const BigInteger& bi_a, const BigInteger& bi_b) {
    return bi_a.compare(bi_b) < 0;
}

bool operator>=(const BigInteger& bi_a, const BigInteger& bi_b) {
    int cmp = bi_a.compare(bi_b);
    return cmp == 1 || cmp == 0;
}

bool operator<=(const BigInteger& bi_a, const BigInteger& bi_b) {
    int cmp = bi_a.compare(bi_b);
    return cmp == -1 || cmp == 0;
}

bool operator==(const BigInteger& bi_a, const BigInteger& bi_b) {
    return bi_a.compare(bi_b) == 0;
}

bool operator!=(const BigInteger& bi_a, const BigInteger& bi_b) {
    return !(bi_a.compare(bi_b) == 0);
}

std::istream& operator>>(std::istream& in, BigInteger& bi) {
    std::string str;
    in >> str;
    bi.constructor(str);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInteger& bi) {
    if(bi.is_negative()) {
        out << '-';
    }
    for (int i = bi.__num_length - 1; i >= 0; i--)
        out << bi.__num[i];
    return out;
}

unsigned short& BigInteger::operator[](size_t index) {
    return this->__num[this->__num_length - index - 1];
}

long long BigInteger::to_integer(bool check_overflow) const {
    if(check_overflow && (this->__num_length >= 19 || (this->__num_length == 19 && !this->is_within_long_long_range()))) {
        throw std::runtime_error("The number is out of the long long range.");
    }

    long long ans = 0, cnt = 1;
    for(int i = 0; i < this->__num_length; ++i, cnt *= 10) {
        ans += cnt * this->__num[i];
    }
    return this->__flag ? ans : -ans;
}

std::string BigInteger::to_string() const {
    std::string ans;
    if(this->is_negative()) {
        ans.push_back('-');
    }
    for(int i = this->__num_length - 1; i >= 0; --i) {
        ans.push_back(this->__num[i] + '0');
    }
    return ans;
}

bool BigInteger::to_boolean() const {
    return !this->is_zero();
}

bool BigInteger::is_positive() const {
    return this->__flag;
}

bool BigInteger::is_negative() const {
    return !this->__flag;
}

bool BigInteger::is_zero() const {
    return this->__num_length == 1 && this->__num[0] == 0;
}

bool BigInteger::is_one() const {
    return this->__num_length == 1 && this->__num[0] == 1;
}

bool BigInteger::is_within_long_long_range() const {
    return this->is_positive() ? this->compare(BigInteger("9223372036854775807")) <= 0 : this->compare(BigInteger("-9223372036854775807")) >= 0;
}

size_t BigInteger::length() const {
    return this->__num_length;
}

size_t BigInteger::size() const {
    return this->__num_size;
}

int BigInteger::compare(const BigInteger& bi) const {
    if(this->__flag != bi.__flag) {
        return this->is_positive() ? 1 : -1;
    }

    int ans = this->is_positive() ? 1 : -1;
    if(this->__num_length > bi.__num_length) {
        return ans;
    } else if(this->__num_length < bi.__num_length) {
        return -ans;
    } else {
        for(int i = this->__num_length - 1; i >= 0; --i) {
            if(this->__num[i] < bi.__num[i]) {
                return -ans;
            } else if(this->__num[i] > bi.__num[i]) {
                return ans;
            }
        }
        return 0;
    }
}

void BigInteger::swap(BigInteger& bi) {
    std::swap(this->__flag, bi.__flag);
    std::swap(this->__num_size, bi.__num_size);
    std::swap(this->__num_length, bi.__num_length);
    std::swap(this->__num, bi.__num);
    std::swap(this->__new_bi_location_size, bi.__new_bi_location_size);
    std::swap(this->__new_bi_location_length, bi.__new_bi_location_length);
    std::swap(this->__new_bi_location, bi.__new_bi_location);
}

void BigInteger::clear() {
    this->__num_length = 1;
    this->__num[0] = 0;
    this->__flag = true;
}

void BigInteger::resize(size_t size) {
    this->__num_size = this->__resize(this->__num, size, this->__num_size);
    this->__num_length = std::min(this->__num_size, this->__num_length);
}

void BigInteger::set_positive(bool flag) {
    if(this->is_zero()) {
        return;
    }
    this->__flag = flag;
}

void BigInteger::pop() {
    if(this->__num_length > 1) {
        --this->__num_length;
    } else {
        this->clear();
    }
}

void BigInteger::push(const unsigned short num) {
    if(this->is_zero()) {
        --this->__num_length;
    }
    if(this->__num_length >= this->__num_size) {
        this->__num_size = (size_t) (this->__num_size * 1.5);
        this->__num_size = this->__resize(this->__num, (this->__num_size == 1 ? 2 : this->__num_size), this->__num_length);
    }
    this->__num[this->__num_length++] = num;
}

bool BigInteger::empty() {
    return this->is_zero();
}

unsigned short BigInteger::front() {
    return this->__num[this->__num_length - 1];
}

unsigned short BigInteger::back() {
    return this->__num[0];
}

void BigInteger::__valid_number(const std::string& str) {
    int str_length = str.length();
    if (str_length == 0) {
        throw std::runtime_error("Input string is empty.");
    }

    int start_index = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (int i = start_index; i < str_length; ++i) {
        if (!isdigit(str[i])) {
            throw std::runtime_error("Input string contains non-numeric characters.");
        }
    }
}

void BigInteger::__location_push(BigInteger* new_bi_location) {
    if (this->__new_bi_location_length >= this->__new_bi_location_size) {
        this->__new_bi_location_size *= 1.5;
        this->__new_bi_location_size = this->__new_bi_location_size ? this->__new_bi_location_size : 4;
        BigInteger** new_bi_location_list = new BigInteger* [this->__new_bi_location_size] { NULL };
        memcpy(new_bi_location_list, this->__new_bi_location, this->__new_bi_location_length * sizeof(BigInteger*));
        delete[] this->__new_bi_location;
        this->__new_bi_location = new_bi_location_list;
    }
    this->__new_bi_location[this->__new_bi_location_length++] = new_bi_location;
}

void BigInteger::__trim() {
    while(this->__num_length > 1 && this->__num[this->__num_length - 1] == 0) {
        --this->__num_length;
    }
}

size_t BigInteger::__newsize(unsigned short*& num, size_t length) {
    delete[] num;
    num = new unsigned short[length]{0};
    return length;
}

size_t BigInteger::__resize(unsigned short*& num, size_t length, size_t pre_len) {
    unsigned short* new_num = new unsigned short[length]{0};
    memcpy(new_num, num, std::min(pre_len, length) * sizeof(unsigned short));
    delete[] num;
    num = new_num;
    return length;
}

void BigInteger::__add(const BigInteger& a, const BigInteger& b, BigInteger& c) {
    int a_length = a.__num_length, b_length = b.__num_length;
    int min_length = a_length < b_length ?
                        (b_length + 1 > c.__num_size ? (c.__num_size = this->__resize(c.__num, b_length + 1, c.__num_length)) : a_length) :
                        (a_length + 1 > c.__num_size ? (c.__num_size = this->__resize(c.__num, a_length + 1, c.__num_length)) : b_length);

    c.__num_length = 0;
    unsigned short res, t = 0;
    for(int i = 0; i < min_length; ++i) {
        res = a.__num[i] + b.__num[i] + t;
        t = res / 10;
        c.__num[c.__num_length++] = res % 10;
    }
    if(a_length > b_length) {
        for (int i = min_length; i < a_length; ++i) {
            res = a.__num[i] + t;
            t = res / 10;
            c.__num[c.__num_length++] = res % 10;
        }
    } else if(a_length < b_length) {
        for (int i = min_length; i < b_length; ++i) {
            res = b.__num[i] + t;
            t = res / 10;
            c.__num[c.__num_length++] = res % 10;
        }
    }
    if(t) {
        c.__num[c.__num_length++] = t;
    }
}

void BigInteger::__subtract(const BigInteger& a, const BigInteger& b, BigInteger& c) {
    int a_length = a.__num_length, b_length = b.__num_length;
    if(c.__num_size < a_length) {
        c.__num_size = this->__resize(c.__num, a_length, c.__num_size);
    }
    c.__num_length = 0;
    short res, t = 0;
    for(int i = 0; i < b_length; ++i) {
        res = a.__num[i] - b.__num[i] - t;
        t = 0;
        c.__num[c.__num_length++] = res >= 0 ? res : (t = 1, res + 10);
    }
    if(a_length != b_length) {
        for (int i = b_length; i < a_length; i++) {
            res = a.__num[i] - t;
            t = 0;
            c.__num[c.__num_length++] = res >= 0 ? res : (t = 1, res + 10);
        }
    }
    c.__trim();
}

void BigInteger::__multiply(const BigInteger& a, const BigInteger& b, BigInteger& c) {
    int a_length = a.__num_length, b_length = b.__num_length;
    BigInteger ans;
    ans.__num_size = this->__newsize(ans.__num, a_length + b_length + 1);
    ans.__num_length = a_length + b_length;
    unsigned short t;
    for(int i = 0; i < a_length; ++i) {
        t = 0;
        for(int j = 0; j < b_length; ++j) {
            ans.__num[i + j] += a.__num[i] * b.__num[j] + t;
            t = ans.__num[i + j] / 10;
            ans.__num[i + j] %= 10;
        }
        ans.__num[b_length + i] = t;
    }
    ans.__trim();
    c.swap(ans);
}

void BigInteger::__divide_mod_bi(const BigInteger& a, const BigInteger& b, BigInteger& divider, BigInteger& remainder) {
    BigInteger temp, cp_a(a);
    temp.__num_size = this->__newsize(temp.__num, a.__num_length + b.__num_length + 1);
    remainder.swap(cp_a);
    temp.__flag = remainder.__flag = true;

    int pre_len = divider.__num_length;
    divider.__num_length = a.__num_length - b.__num_length + 1;

    if (divider.__num_length > divider.__num_size) {
        divider.__num_size = this->__resize(divider.__num, divider.__num_length + 1, pre_len);
    }

    for (int i = divider.__num_length - 1; i >= 0; i--) {
        memset(temp.__num, 0, sizeof(i + b.__num_length));
        for (int j = 0; j < b.__num_length; j++) {
            temp.__num[j + i] = b.__num[j];
        }
        temp.__num_length = b.__num_length + i;
        while (remainder.compare(temp) >= 0) {
            divider.__num[i]++;
            this->__subtract(remainder, temp, remainder);
        }
    }
    divider.__trim();
}

void BigInteger::__divide_mod_li(const BigInteger& a, const long long b, BigInteger& divider, BigInteger& remainder) {
    long long t = 0;
    divider.__num_length = a.__num_length;
    divider.__num_size = this->__newsize(divider.__num, divider.__num_length + 1);
    for (int i = divider.__num_length - 1; i >= 0; i--) {
        divider.__num[i] = (t * 10 + a.__num[i]) / b;
        t = (t * 10 + a.__num[i]) % b;
    }
    divider.__trim();
    BigInteger ans(t);
    remainder.swap(ans);
}