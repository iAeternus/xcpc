#include <bits/stdc++.h>

/**
 * 丢弃
 */
void discard() {
    std::cout << "discard\n";
}

/**
 * 装配
 */
void assemble() {
    std::cout << "assemble\n";
}

/**
 * 进入市场
 */
void accessToMarket() {
    std::cout << "access to market\n";
}

/**
 * 调换
 */
void exchange() {
    std::cout << "exchange\n";
}

/**
 * @par p1 是否检验零配件
 * @par p2 零配件是否合格
 * @par p3 是否对组装好的成品进行检测
 * @par p4 成品检测是否合格
 * @par p5 进入市场后的产品是否合格
 * @par p6 是否拆解产品
 */
void func(bool p1, bool p2, bool p3, bool p4, bool p5, bool p6) {
    bool done = false;
    while (!done) {
        if (p1 && !p2) {
            discard();
            done = true;
        } else {
            assemble();
            if (p3) {
                if (p4) {
                    accessToMarket();
                    done = true;
                } else {
                    if (!p6) {
                        discard();
                        done = true;
                    }
                }
            } else {
                accessToMarket();
                if (!p5) {
                    exchange();
                    if (!p6) {
                        discard();
                        done = true;
                    }
                } else {
                    done = true;
                }
            }
        }

        // 拆解，重新循环
        if (p6 && !done) {
            continue;
        }

        break;
    }
}

int main() {
    func(1, 1, 1, 1, 1, 0);
    std::cout << std::endl;
    func(0, 0, 0, 0, 0, 0);
    std::cout << std::endl;
    // func(0, 0, 0, 0, 0, 1);
}