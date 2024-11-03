/**
 * @brief 智能Iterator指针，自动析构迭代器指针
 * @author Ricky
 * @date 2024/6/24
 * @version 1.0
 */
#ifndef ITERATOR_PTR_H
#define ITERATOR_PTR_H

#include "Iterator.h"

template<typename T>
class IteratorPtr {
public:
    IteratorPtr(Iterator<T>* i = nullptr);
    virtual ~IteratorPtr();

    IteratorPtr(const IteratorPtr&) = delete;
    IteratorPtr& operator=(const IteratorPtr&) = delete;
    IteratorPtr(IteratorPtr&&) noexcept = delete;
    IteratorPtr& operator=(IteratorPtr&&) noexcept = delete;

    Iterator<T>* operator->();
    Iterator<T>& operator*();

    static IteratorPtr& makePtr(Iterator<T>* i = nullptr);

private:
    Iterator<T>* m_i;
};

template<typename T>
IteratorPtr<T>::IteratorPtr(Iterator<T>* i) : m_i(i) {}

template<typename T>
IteratorPtr<T>::~IteratorPtr() {
    delete m_i;
}

template<typename T>
Iterator<T>* IteratorPtr<T>::operator->() {
    return m_i;
}

template<typename T>
Iterator<T>& IteratorPtr<T>::operator*() {
    return *m_i;
}

template<typename T>
IteratorPtr<T>& makePtr(Iterator<T>* i) {
    return IteratorPtr<T>(i);
}

#endif // ITERATOR_PTR_H