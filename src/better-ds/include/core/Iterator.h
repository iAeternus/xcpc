/**
 * @brief 迭代器接口
 * @author Ricky
 * @date 2024/6/24
 * @version 1.0
 */
#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator {
public:
    virtual ~Iterator();
    
    // 指向第一个对象
    virtual void first() = 0;
    // 指向下一个对象
    virtual void next() = 0;
    // 当序列中不再有未到达的元素时返回true
    virtual bool isDone() const  = 0;
    // 返回当前位置的对象
    virtual T currentItem() const = 0;
protected:
    Iterator();
};

template<typename T>
Iterator<T>::Iterator() {}

template<typename T>
Iterator<T>::~Iterator() {}

#endif // ITERATOR_H