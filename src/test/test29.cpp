#include <memory>

class X {
public:
    void func() {

    }
};

int main() {
    std::shared_ptr<X> ptr = std::make_shared<X>();

    ptr->func();
}