#include "stacklib.h"

// �?nh ngh?a c�c ph��ng th?c c?a l?p Stack

// Kh?i t?o stack v?i s?c ch?a cho tr�?c
Stack::Stack(int capacity) {
    this->capacity = capacity;
    data = new int[capacity];
    top = -1;   // Kh?i t?o �?nh stack l� -1 �? ��nh d?u stack r?ng
}

// H?y b? stack v� gi?i ph�ng b? nh?
Stack::~Stack() {
    delete[] data;
}

// Th�m m?t ph?n t? v�o �?nh stack
void Stack::Push(int element) {
    if (top == capacity - 1) {
        std::cout << "Stack overflow!\n";
        return;
    }
    top++;
    data[top] = element;
}

// Lo?i b? ph?n t? tr�n �?nh stack
void Stack::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    top--;
}

// Truy c?p ph?n t? tr�n �?nh stack m� kh�ng lo?i b? n�
int Stack::Top() const {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return -1;
    }
    return data[top];
}

// Ki?m tra xem stack c� r?ng kh�ng
bool Stack::IsEmpty() const {
    return (top == -1);
}

// Tr? v? s? l�?ng ph?n t? hi?n t?i trong stack
int Stack::Size() const {
    return (top + 1);
}

// X�a t?t c? c�c ph?n t? trong stack
void Stack::Clear() {
    top = -1;   // ��nh d?u stack r?ng b?ng c�ch �?t �?nh l� -1
}
// T?o m?t b?n sao c?a stack
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// G�n gi� tr? c?a m?t stack cho stack kh�c
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        top = other.top;
        data = new int[capacity];
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// So s�nh hai stack c� b?ng nhau hay kh�ng
bool Stack::operator==(const Stack& other) const {
    if (top != other.top) {
        return false;
    }
    for (int i = 0; i <= top; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

// So s�nh hai stack c� kh�c nhau hay kh�ng
bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}

// Chuy?n �?i stack th�nh m?t m?ng
int* Stack::ToArray() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
 }
// In ra t?t c? c�c ph?n t? trong stack
void Stack::PrintStack() {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    for (int i = top; i >= 0; i--) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Ki?m tra xem stack �? �?y ch�a
bool Stack::IsFull() const {
    return (top == capacity - 1);
}

// Thay �?i s?c ch?a c?a stack
void Stack::Resize(int newCapacity) {
    if (newCapacity <= 0) {
        std::cout << "Invalid capacity!\n";
        return;
    }

    int* newData = new int[newCapacity];
    int elementsToCopy = std::min(top + 1, newCapacity);
    for (int i = 0; i < elementsToCopy; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    if (top >= newCapacity) {
        top = newCapacity - 1;
    }
}

// L?y t?t c? c�c ph?n t? trong stack
int* Stack::GetAllElements() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
}

// X�a m?t ph?n t? trong stack d?a tr�n ch? s?
void Stack::RemoveByIndex(int index) {
    if (index < 0 || index > top) {
        std::cout << "Invalid index!\n";
        return;
    }

    for (int i = index; i < top; i++) {
        data[i] = data[i + 1];
    }
    top--;
}

// �?o ng�?c th? t? c�c ph?n t? trong stack
void Stack::Reverse() {
    int start = 0;
    int end = top;
    while (start < end) {
        int temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        start++;
        end--;
    }
}

// Ki?m tra xem stack c� �?i x?ng kh�ng
bool Stack::IsSymmetric() const {
    int start = 0;
    int end = top;
    while (start < end) {
        if (data[start] != data[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
Stack Stack::ReverseCopy() const {
    Stack reversedStack(capacity);  // T?o m?t Stack m?i �? l�u tr? b?n sao �?o ng�?c
    int* tempData = new int[top + 1];  // T?o m?t m?ng t?m �? sao ch�p d? li?u hi?n t?i c?a Stack

    // Sao ch�p d? li?u t? Stack hi?n t?i v�o m?ng t?m
    for (int i = 0; i <= top; i++) {
        tempData[i] = data[i];
    }

    // �?y c�c ph?n t? t? cu?i �?n �?u v�o reversedStack
    for (int i = top; i >= 0; i--) {
        reversedStack.Push(tempData[i]);
    }

    delete[] tempData;  // Gi?i ph�ng b? nh? c?a m?ng t?m

    return reversedStack;  // Tr? v? b?n sao �?o ng�?c c?a Stack
}
/* // Chuy?n �?i stack th�nh queue
Queue Stack::ConvertToQueue() const {
    Queue queue(capacity);
    int* elements = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        elements[i] = data[i];
    }
    for (int i = top; i >= 0; i--) {
        queue.Enqueue(elements[i]);
    }
    delete[] elements;
    return queue;
}*/