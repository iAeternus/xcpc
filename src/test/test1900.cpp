#include <cstddef>
#include <iostream>

class Person {
public:
    std::string name; // 名字
    int age;          // 年龄
    bool gender;      // 性别

    // construction
    // Person(std::string name, int age, bool gender) {
    //     this->name = name;
    //     this->age = age;
    //     this->gender = gender;
    // }

    Person(std::string name, int age, bool gender) :
            name(name), age(age), gender(gender) {
        std::cout << "construction\n";
    }

    // copy
    Person(const Person& other) :
            name(other.name), age(other.age), gender(other.gender) {
        std::cout << "copy\n";
    }

    // destruction
    ~Person() {
        std::cout << "destruction\n";
    }

    void print() const {
        std::cout << name << ' ' << age << ' ' << gender << std::endl;
    }
};

class Student : public Person {
public:
    long long id; // 学号

    Student(long long id, std::string name, int age, bool gender) :
            Person(name, age, gender), id(id) {}

    ~Student() {
    }
};

class List {
public:
    List();
    virtual ~List();

    virtual int size() const { // 虚函数
        return 0;
    }

    virtual void push_back(int x) = 0; // 把 x 加入到列表的尾部 纯虚函数

    void pop_back();       // 把列表最后一个元素删除

    void clear(); // 清空

    int size_;
};

// 数组实现
class ArrayList : public List {
public:
    ArrayList(int size) {

    }
    ~ArrayList() {
        delete arr_;
    }

    int size() const override {
        return List::size_;
    }

    void push_back(int x) override {
        arr_[List::size_++] = x;
    }


    void pop_back();       // 把列表最后一个元素删除

    void clear(); // 清空

private:
    int* arr_;
};

class LinkedList : public List {
public:
    struct Node {
        int data;
        Node* next;
    };

    LinkedList();
    ~LinkedList();

    void push_back(int x) override {
        // 链表尾插        
    }

private:
    Node* head_;
};

int main() {
    List* l = new ArrayList(11);
    List* l2 = new ArrayList(12);

    l->size();


    delete l2;
    delete l;
}