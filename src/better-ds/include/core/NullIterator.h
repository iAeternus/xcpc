/**
 * @brief 空迭代器，在空集上迭代
 * @author Ricky
 * @date 2024/6/24
 * @version 1.0
 */
#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

template<typename T>
class NullIterator : public Iterator<T> {
public:
    explicit NullIterator();

    void first() override;
    void next() override;
    bool isDone() const override;
    T currentItem() const override;
};

template<typename T>
NullIterator<T>::NullIterator() {}

template<typename T>
void NullIterator<T>::first() {}

template<typename T>
void NullIterator<T>::next() {}

template<typename T>
bool NullIterator<T>::isDone() const {
    return true;
}

template<typename T>
T NullIterator<T>::currentItem() const {
    return T();
}

#endif // NULL_ITERATOR_H