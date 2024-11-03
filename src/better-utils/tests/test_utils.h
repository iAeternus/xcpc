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

namespace TestUtils {

constexpr const char GREEN_COLOR[] = "\033[32m"; // 控制台输出绿色
constexpr const char RED_COLOR[] = "\033[31m"; // 控制台输出红色
constexpr const char DEFAULT_COLOR[] = "\033[0m"; // 控制台输出默认颜色

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

private:
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
};

extern Random random;

} // end of namespace TestUtils

#endif // TEST_UTILS_H