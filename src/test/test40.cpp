#include <iostream>

class Test {
    friend int main();
    int i;
    Test(int);

    void g();
    friend Test& f(Test);
};

Test& f(Test);

int main() {
    Test& a = f(0);
    int n = a.i;
    // std::cout << ++a.i << std::endl;
    std::cout << "n = " << ++n << std::endl;
    return 0;
}

Test& f(Test obj) {
    obj.g();
    return obj;
}

Test::Test(int x) {
    ++i = x;
}

void Test::g() {
    std::cout << "Hello\n";
}