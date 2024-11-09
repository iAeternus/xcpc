/**
 * @brief 测试工具
 * @author Ricky
 * @date 2024/10/18
 * @version 1.0
 */
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <string>
#include <vector>
#include <functional>
#include <random>
#include <memory>
#include <iostream>

namespace TestUtils {

constexpr static std::string GREEN_COLOR = "\033[32m"; // 控制台输出绿色
constexpr static std::string RED_COLOR = "\033[31m"; // 控制台输出红色
constexpr static std::string DEFAULT_COLOR = "\033[0m"; // 控制台输出默认颜色

/**
 * 单元测试
 */
class UnitTest {
public:
    UnitTest(const std::string& name, const std::function<void(void)>& testCase);

    std::string getName() const;
    void start() const;
private:
    std::string name;
    std::function<void(void)> testCase;
};

/**
 * 单元测试组
 */
class UnitTestGroup {
public:
    UnitTestGroup(const std::string& groupName, const std::vector<UnitTest>& group = std::vector<UnitTest>());

    void addTest(const UnitTest& unitTest);
    void startFirst(const std::string& name) const;
    void startAll() const;
private:
    std::string groupName;
    std::vector<UnitTest> group;
};

/**
 * 假设的测试对象
 */
class User {
public:
    User();
    User(const std::string& username, const std::string& password);

    std::string getUsername() const;
    std::string getPassword() const;

    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;

    friend std::ostream& operator<<(std::ostream& out, const User& aUser);
private:
    std::string username;
    std::string password;
};

/**
 * 随机数类
 */
class Random {
public:
    Random();
    Random(long seed);

    void seed(long seed); // 设置新的种子

    int nextInt();
    int nextInt(int lower, int upper); // [lower, upper)
    long long nextLong();
    long long nextLong(long long lower, long long upper); // [lower, upper)
    double nextDouble(); // [0.0, 1.0)
    bool nextBoolean();
    float nextFloat(); // [0.0, 1.0)

    int* nextIntArray(std::size_t n, int lower, int upper);

private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
};

extern Random rnd;

template<typename T>
auto generalToStringFunc = [](const T* const val) -> std::string {
    return val ? std::to_string(*val) : "";
};

/**
 * 断言失败异常
 */
template<typename T>
class AssertionFailedException : public std::exception {
public:
    AssertionFailedException(const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);
    AssertionFailedException(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);
    AssertionFailedException(T* expected, T* actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);

    const char* what() const noexcept override;
private:
    std::unique_ptr<T> expected;
    std::unique_ptr<T> actual;
    std::function<std::string(const T* const)> toStringFunc;
};

template<typename T>
AssertionFailedException<T>::AssertionFailedException(const std::function<std::string(const T* const)>& toStringFunc) :
        expected(nullptr), actual(nullptr), toStringFunc(toStringFunc) {}

template<typename T>
AssertionFailedException<T>::AssertionFailedException(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc) :
        expected(std::make_unique<T>(expected)), actual(std::make_unique<T>(actual)), toStringFunc(toStringFunc) {}

template<typename T>
AssertionFailedException<T>::AssertionFailedException(T* expected, T* actual, const std::function<std::string(const T* const)>& toStringFunc) : 
        expected(expected), actual(actual), toStringFunc(toStringFunc) {}

template<typename T>
const char* AssertionFailedException<T>::what() const noexcept {
    const std::string text = RED_COLOR + "Expected: " + toStringFunc(expected.get()) + " Actual: " + toStringFunc(actual.get()) + DEFAULT_COLOR;
    return text.c_str();
}

/**
 * 自动断言类
 */
// template<typename T>
class Assertions {
public:
    Assertions() = delete;

    template<typename T>
    static void assertEquals(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);

    template<typename T>
    static void assertNull(T* actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);

    template<typename T>
    static void assertAcsOrder(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

    template<typename T>
    static void assertDescOrder(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator = std::less<T>{});

private:
    template<typename T>    
    static bool objectEquals(const T& expected, const T& actual);

    template<typename T>
    static void assertionFailed();

    template<typename T>
    static void assertionFailed(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);

    template<typename T>
    static void assertionFailed(T* expected, T* actual, const std::function<std::string(const T* const)>& toStringFunc = generalToStringFunc<T>);
};

template<typename T>
void Assertions::assertEquals(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc) {
    if(!objectEquals<T>(expected, actual)) {
        assertionFailed<T>(expected, actual, toStringFunc);
    }
}

template<typename T>
void Assertions::assertNull(T* actual, const std::function<std::string(const T* const)>& toStringFunc) {
    if(actual) {
        assertionFailed<T>(nullptr, actual, toStringFunc);
    }
}

template<typename T>
void Assertions::assertAcsOrder(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    for(T* p = arrBegin + 1; p != arrEnd; ++p) {
        if(comparator(*p, *(p - 1))) {
            assertionFailed<T>();
        }
    }
}

template<typename T>
void Assertions::assertDescOrder(T* arrBegin, T* arrEnd, const std::function<bool(const T&, const T&)>& comparator) {
    for(T* p = arrBegin + 1; p != arrEnd; ++p) {
        if(comparator(*p, *(p - 1))) {
            assertionFailed<T>();
        }
    }
}

template<typename T>
bool Assertions::objectEquals(const T& expected, const T& actual) {
    return expected == actual;
}

template<typename T>
void Assertions::assertionFailed() {
    throw AssertionFailedException<T>();
}

template<typename T>
void Assertions::assertionFailed(const T& expected, const T& actual, const std::function<std::string(const T* const)>& toStringFunc) {
    throw AssertionFailedException<T>(expected, actual, toStringFunc);
}

template<typename T>
void Assertions::assertionFailed(T* expected, T* actual, const std::function<std::string(const T* const)>& toStringFunc) {
    throw AssertionFailedException<T>(expected, actual, toStringFunc);
}

/**
 * 打印相关函数
 */
template<typename T> 
std::ostream& printArray(T* arrBegin, T* arrEnd, std::ostream& out = std::cout) {
    out << *arrBegin;
    for(T* p = arrBegin + 1; p < arrEnd; ++p) {
        out << ' ' << *p;
    }
    out << std::endl;
    return out;
}

} // end of namespace TestUtils

#endif // TEST_UTILS_H