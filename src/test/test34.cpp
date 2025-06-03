#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <map>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * @brief 表达式标记类，用于表示表达式中的数字、运算符等元素
 */
class Token {
public:
    enum Type {
        NUMBER,      // 数字
        OPERATOR,    // 二元运算符
        LEFT_PAREN,  // 左括号
        RIGHT_PAREN, // 右括号
        UNARY_OP     // 一元运算符（如负号）
    };

    /**
     * @brief 构造函数
     *
     * @param type 标记类型
     * @param value 运算符值（对于运算符类型）
     * @param num 数字值（对于数字类型）
     */
    Token(Type type, const string& value = "", double num = 0.0) :
            type(type), opValue(value), numValue(num) {}

    /**
     * @brief 获取标记类型
     *
     * @return Type 标记类型
     */
    Type getType() const { return type; }

    /**
     * @brief 获取运算符值（对于运算符类型）
     *
     * @return string 运算符值
     */
    string getOp() const { return opValue; }

    /**
     * @brief 获取数字值（对于数字类型）
     *
     * @return double 数字值
     */
    double getNum() const { return numValue; }

    /**
     * @brief 获取运算符属性（优先级和结合性）
     *
     * @return OpProperty 运算符属性
     */
    struct OpProperty {
        int prec;        // 优先级
        bool rightAssoc; // 是否右结合
    };

    OpProperty getOpProperty() const {
        static const map<string, OpProperty> opMap = {
            {"+", {2, false}}, // 加法
            {"-", {2, false}}, // 减法
            {"*", {3, false}}, // 乘法
            {"/", {3, false}}, // 除法
            {"%", {3, false}}, // 取模
            {"^", {4, true}},  // 幂运算（右结合）
            {"u-", {5, true}}  // 一元负号（右结合）
        };
        return opMap.at(opValue);
    }

private:
    Type type;       // 标记类型
    string opValue;  // 运算符值
    double numValue; // 数字值
};

/**
 * @brief 表达式解析和计算类
 */
class Expression {
private:
    vector<Token> tokens; // 表达式标记
    bool valid;           // 表达式是否有效

    /**
     * @brief 将字符串表达式分解为标记
     *
     * @param expr 字符串表达式
     */
    void tokenize(const string& expr) {
        tokens.clear();
        string numStr;
        auto finishNumber = [&]() {
            if (!numStr.empty()) {
                validateNumber(numStr);
                tokens.emplace_back(Token::NUMBER, "", stod(numStr));
                numStr.clear();
            }
        };

        for (size_t i = 0; i < expr.size(); ++i) {
            char c = expr[i];
            if (isdigit(c) || c == '.') {
                numStr += c;
            } else {
                finishNumber();

                if (c == '-' && (tokens.empty() || tokens.back().getType() == Token::LEFT_PAREN || tokens.back().getType() == Token::OPERATOR || tokens.back().getType() == Token::UNARY_OP)) {
                    // 处理一元负号
                    tokens.emplace_back(Token::UNARY_OP, "u-");
                } else if (c == '(') {
                    tokens.emplace_back(Token::LEFT_PAREN, "(");
                } else if (c == ')') {
                    tokens.emplace_back(Token::RIGHT_PAREN, ")");
                } else if (string("+-*/%^").find(c) != string::npos) {
                    tokens.emplace_back(Token::OPERATOR, string(1, c));
                } else if (!isspace(c)) {
                    throw runtime_error("Invalid character: " + string(1, c));
                }
            }
        }
        finishNumber();
    }

    /**
     * @brief 验证数字格式是否正确
     *
     * @param num 数字字符串
     */
    void validateNumber(const string& num) {
        if (num.empty()) return;

        size_t dotPos = num.find('.');
        if (dotPos != string::npos) {
            if (num.find('.', dotPos + 1) != string::npos) {
                throw runtime_error("Invalid number (multiple dots): " + num);
            }
            if (dotPos == 0 || dotPos == num.length() - 1) {
                throw runtime_error("Invalid number (misplaced dot): " + num);
            }
        }
        if (num[0] == '-' && num.size() == 1) {
            throw runtime_error("Invalid operator position: " + num);
        }
    }

    /**
     * @brief 检查括号是否匹配
     *
     * @return true 括号匹配
     * @return false 括号不匹配
     */
    bool checkBrackets() {
        stack<Token> s;
        for (const auto& t : tokens) {
            if (t.getType() == Token::LEFT_PAREN) {
                s.push(t);
            } else if (t.getType() == Token::RIGHT_PAREN) {
                if (s.empty()) return false;
                s.pop();
            }
        }
        return s.empty();
    }

    /**
     * @brief 判断是否需要弹出运算符
     *
     * @param incoming 当前运算符
     * @param stackTop 栈顶运算符
     * @return true 需要弹出
     * @return false 不需要弹出
     */
    bool shouldPop(const Token& incoming, const Token& stackTop) {
        auto incomingProp = incoming.getOpProperty();
        auto stackProp = stackTop.getOpProperty();

        if (incomingProp.rightAssoc) {
            return incomingProp.prec < stackProp.prec;
        } else {
            return incomingProp.prec <= stackProp.prec;
        }
    }

    /**
     * @brief 将中缀表达式转换为后缀表达式
     *
     * @return vector<Token> 后缀表达式标记
     */
    vector<Token> infixToPostfix() {
        vector<Token> output;
        stack<Token> operatorStack;

        for (const auto& token : tokens) {
            switch (token.getType()) {
            case Token::NUMBER:
                output.push_back(token);
                break;

            case Token::LEFT_PAREN:
                operatorStack.push(token);
                break;

            case Token::RIGHT_PAREN: {
                while (!operatorStack.empty() && operatorStack.top().getType() != Token::LEFT_PAREN) {
                    output.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                if (operatorStack.empty()) throw runtime_error("Mismatched parentheses");
                operatorStack.pop(); // Remove left paren
                break;
            }

            case Token::OPERATOR:
            case Token::UNARY_OP:
                while (!operatorStack.empty() && operatorStack.top().getType() != Token::LEFT_PAREN && shouldPop(token, operatorStack.top())) {
                    output.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(token);
                break;

            default:
                throw runtime_error("Unexpected token type");
            }
        }

        while (!operatorStack.empty()) {
            if (operatorStack.top().getType() == Token::LEFT_PAREN) {
                throw runtime_error("Mismatched parentheses");
            }
            output.push_back(operatorStack.top());
            operatorStack.pop();
        }

        return output;
    }

    /**
     * @brief 计算后缀表达式的值
     *
     * @param postfix 后缀表达式标记
     * @return double 计算结果
     */
    double evaluatePostfix(const vector<Token>& postfix) {
        stack<double> stack;
        for (const auto& token : postfix) {
            switch (token.getType()) {
            case Token::NUMBER:
                stack.push(token.getNum());
                break;

            case Token::OPERATOR:
            case Token::UNARY_OP: {
                string op = token.getOp();
                if (op == "u-") {
                    double a = stack.top();
                    stack.pop();
                    stack.push(-a);
                } else {
                    if (stack.size() < 2) throw runtime_error("Insufficient operands");
                    double b = stack.top();
                    stack.pop();
                    double a = stack.top();
                    stack.pop();
                    if (op == "+")
                        stack.push(a + b);
                    else if (op == "-")
                        stack.push(a - b);
                    else if (op == "*")
                        stack.push(a * b);
                    else if (op == "/") {
                        if (b == 0) throw runtime_error("Division by zero");
                        stack.push(a / b);
                    } else if (op == "%")
                        stack.push(fmod(a, b));
                    else if (op == "^")
                        stack.push(pow(a, b));
                    else
                        throw runtime_error("Unknown operator: " + op);
                }
                break;
            }

            default:
                throw runtime_error("Unexpected token in postfix");
            }
        }
        if (stack.size() != 1) throw runtime_error("Malformed expression");
        return stack.top();
    }

public:
    /**
     * @brief 构造函数，初始化表达式解析器
     *
     * @param expr 字符串表达式
     */
    explicit Expression(const string& expr) :
            valid(false) {
        try {
            string filtered;
            remove_copy_if(expr.begin(), expr.end(), back_inserter(filtered),
                           [](char c) { return isspace(c); });

            tokenize(filtered);
            valid = checkBrackets();
        } catch (const exception& e) {
            throw runtime_error("Tokenization error: " + string(e.what()));
        }
    }

    /**
     * @brief 检查表达式是否有效
     *
     * @return true 有效
     * @return false 无效
     */
    bool isValid() const { return valid; }

    /**
     * @brief 获取后缀表达式
     *
     * @return vector<Token> 后缀表达式标记
     */
    vector<Token> getPostfix() {
        if (!valid) throw runtime_error("Invalid expression");
        return infixToPostfix();
    }

    /**
     * @brief 计算表达式的值
     *
     * @return double 计算结果
     */
    double evaluate() {
        if (!valid) throw runtime_error("Invalid expression");
        return evaluatePostfix(infixToPostfix());
    }
};

// 测试用例
int main() {
    vector<tuple<string, double>> tests = {
        {"3 + 4*2/(1-5)^2", 3 + 4 * 2 / pow(1 - 5, 2)},
        {"2^3^2", pow(2, pow(3, 2))}, // 512
        {"-5%3", fmod(-5, 3)},        // -2
        {"3.5 + 4.2*(2-5.1)/2", 3.5 + 4.2 * (2 - 5.1) / 2}};

    for (const auto& [expr, expect] : tests) {
        try {
            Expression e(expr);
            if (!e.isValid()) {
                cerr << "Invalid: " << expr << endl;
                continue;
            }
            double result = e.evaluate();
            cout << expr << " = " << result
                 << " (" << (abs(result - expect) < 1e-6 ? "Ok" : "Err") << ")\n";
        } catch (const exception& e) {
            cerr << "Error: " << expr << " => " << e.what() << endl;
        }
    }
    return 0;
}