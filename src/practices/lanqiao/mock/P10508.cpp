/**
 * @see https://www.luogu.com.cn/problem/P10508
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string divideByTwo(const string& num) {
    string result;
    int carry = 0;
    for (char c : num) {
        int current_digit = (c - '0') + carry * 10;
        int quotient = current_digit / 2;
        carry = current_digit % 2;
        if (!result.empty() || quotient != 0) {
            result.push_back(quotient + '0');
        }
    }
    return result.empty() ? "0" : result;
}

int countFactorTwo(const string& num) {
    int count = 0;
    string current = num;
    while (true) {
        if ((current.back() - '0') % 2 != 0) {
            break;
        }
        current = divideByTwo(current);
        count++;
    }
    return count;
}

int main() {
    ifstream file("numlist.txt");
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
        return 1;
    }
    string number;
    int total = 0;
    while (getline(file, number)) {
        total += countFactorTwo(number);
    }
    cout << total << endl;
    return 0;
}