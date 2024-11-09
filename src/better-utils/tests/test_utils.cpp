#include "test_utils.h"
#include "NoSuchUnitTestException.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <limits>

namespace TestUtils {

UnitTest::UnitTest(const std::string& name, const std::function<void(void)>& testCase) : 
        name(name), testCase(testCase) {}

std::string UnitTest::getName() const {
    return this->name;
}

void UnitTest::start() const {
    try {
        auto start_time = std::chrono::high_resolution_clock::now();  
        testCase();
        auto end_time = std::chrono::high_resolution_clock::now();  
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        std::cout << GREEN_COLOR << '[' << name << "] Test success in " << elapsed_ms << "ms" << DEFAULT_COLOR << std::endl;
    } catch(const std::exception& ex) {
        std::cout << RED_COLOR << '[' << name << "] Test failed! Exception: " << ex.what() << DEFAULT_COLOR << std::endl;
    } catch (...) {
        std::cout << RED_COLOR << '[' << name << "] Test failed! Unknown exception." << DEFAULT_COLOR << std::endl;
    }
}

UnitTestGroup::UnitTestGroup(const std::string& groupName, const std::vector<UnitTest>& group) :
        groupName(groupName), group(group) {}

void UnitTestGroup::addTest(const UnitTest& unitTest) {
    group.push_back(unitTest);
}

void UnitTestGroup::startFirst(const std::string& name) const {
    for(const auto& unitTest : group) {
        if(unitTest.getName() == name) {
            unitTest.start();
            break;
        }
    }
    throw NoSuchUnitTestException("Unit test name [" + name + "] not found.");
}

void UnitTestGroup::startAll() const {
    std::cout << "================= " << groupName << " =================" << std::endl;
    for(const auto& unitTest : group) {
        unitTest.start();
    }
}

User::User() : 
        username(), password() {}

User::User(const std::string& username, const std::string& password) : 
        username(username), password(password) {}

std::string User::getUsername() const {
    return this->username;
}

std::string User::getPassword() const {
    return this->password;
}

bool User::operator==(const User& other) const {
    return this->username == other.username && this->password == other.password;
}

bool User::operator!=(const User& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const User& aUser) {
    out << "User{username=" << aUser.username << ", password=" << aUser.password << '}';
    return out;
}

Random::Random() : 
        generator(std::random_device{}()), distribution(0, std::numeric_limits<int>::max()) {}

Random::Random(long seed) :
        generator(seed), distribution(0, std::numeric_limits<int>::max()) {}

void Random::seed(long seed) {
    generator.seed(seed);
}

int Random::nextInt() {
    return distribution(generator);
}

int Random::nextInt(int lower, int upper) {
    std::uniform_int_distribution<int> range_distribution(lower, upper - 1);  
    return range_distribution(generator);
}

long long Random::nextLong() {
    std::uniform_int_distribution<long> long_distribution(0, std::numeric_limits<long>::max());  
    return long_distribution(generator);  
}

long long Random::nextLong(long long lower, long long upper) {
    std::uniform_int_distribution<long> range_distribution(lower, upper - 1);  
    return range_distribution(generator);
}

double Random::nextDouble() {
    std::uniform_real_distribution<double> double_distribution(0.0, 1.0);  
    return double_distribution(generator);
}

bool Random::nextBoolean() {
    std::uniform_int_distribution<int> bool_distribution(0, 1);  
    return bool_distribution(generator) == 1;
}

float Random::nextFloat() {
    std::uniform_real_distribution<float> float_distribution(0.0f, 1.0f);  
    return float_distribution(generator);
}

int* Random::nextIntArray(std::size_t n, int lower, int upper) {
    int* arr = new int[n];
    for(std::size_t i = 0; i < n; ++i) {
        arr[i] = nextInt(lower, upper);
    }
    return arr;
}

Random rnd(static_cast<long>(time(nullptr)));

} // end of namespace TestUtils