#include "queuelib.h"

template <typename T>
QueueLib<T>::QueueLib() : frontPtr(nullptr), backPtr(nullptr), count(0) {}

template <typename T>
QueueLib<T>::~QueueLib() {
    while (frontPtr != nullptr) {
        QueueNode<T>* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
    }
}

template <typename T>
void QueueLib<T>::dequeue() {
    if (frontPtr == nullptr)
        return;
    QueueNode<T>* temp = frontPtr;
    frontPtr = frontPtr->next;
    delete temp;
    count--;
}

template <typename T>
void QueueLib<T>::enqueue(const T& value) {
    QueueNode<T>* newNode = new QueueNode<T>(value);
    if (frontPtr == nullptr) {
        frontPtr = newNode;
        backPtr = newNode;
    }
    else {
        backPtr->next = newNode;
        backPtr = newNode;
    }
    count++;
}

template <typename T>
void QueueLib<T>::push(const T& element) {
    enqueue(element);
}

template <typename T>
T& QueueLib<T>::front() {
    return frontPtr->data;
}

template <typename T>
T& QueueLib<T>::back() {
    return backPtr->data;
}

template <typename T>
bool QueueLib<T>::empty() {
    return count == 0;
}

template <typename T>
size_t QueueLib<T>::size() {
    return count;
}

template <typename T>
template <typename... Args>
void QueueLib<T>::emplace(Args&&... args) {
    T value(std::forward<Args>(args)...);
    enqueue(value);
}

template <typename T>
void QueueLib<T>::swap(QueueLib& other) {
    std::swap(frontPtr, other.frontPtr);
    std::swap(backPtr, other.backPtr);
    std::swap(count, other.count);
}

template <typename T>
void QueueLib<T>::reverse() {
    if (frontPtr == nullptr || frontPtr == backPtr)
        return;

    QueueNode<T>* prevNode = nullptr;
    QueueNode<T>* currentNode = frontPtr;
    QueueNode<T>* nextNode = nullptr;

    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    std::swap(frontPtr, backPtr);
}

template <typename T>
T& QueueLib<T>::getNthElement(size_t n) {
    if (n >= count)
        throw std::out_of_range("Index out of range");

    QueueNode<T>* currentNode = frontPtr;
    for (size_t i = 0; i < n; i++) {
        currentNode = currentNode->next;
    }

    return currentNode->data;
}

template <typename T>
int QueueLib<T>::find(const T& element) {
    QueueNode<T>* currentNode = frontPtr;
    int index = 0;
    while (currentNode != nullptr) {
        if (currentNode->data == element)
            return index;

        currentNode = currentNode->next;
        index++;
    }

    return -1;  // khong tìm thấy
}

template <typename T>
void QueueLib<T>::display() {
    QueueNode<T>* currentNode = frontPtr;
    while (currentNode != nullptr) {
            std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

// Các khởi tạo rõ ràng cho các kiểu dữ liệu nguyên thủy
template class QueueLib<int>;
template class QueueLib<float>;
template class QueueLib<double>;
template class QueueLib<std::string>;
