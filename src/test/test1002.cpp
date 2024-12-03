class X {
public:
    virtual ~X() {}
};

class XX : public X {
public:
    ~XX() {}
};

class A final {
public:
    ~A() {} // 可能更省开销？
};

