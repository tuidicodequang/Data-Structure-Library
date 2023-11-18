#include "stacklib.h"

// Ð?nh ngh?a các phýõng th?c c?a l?p Stack

// Kh?i t?o stack v?i s?c ch?a cho trý?c
Stack::Stack(int capacity) {
    this->capacity = capacity;
    data = new int[capacity];
    top = -1;   // Kh?i t?o ð?nh stack là -1 ð? ðánh d?u stack r?ng
}

// H?y b? stack và gi?i phóng b? nh?
Stack::~Stack() {
    delete[] data;
}

// Thêm m?t ph?n t? vào ð?nh stack
void Stack::Push(int element) {
    if (top == capacity - 1) {
        std::cout << "Stack overflow!\n";
        return;
    }
    top++;
    data[top] = element;
}

// Lo?i b? ph?n t? trên ð?nh stack
void Stack::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    top--;
}

// Truy c?p ph?n t? trên ð?nh stack mà không lo?i b? nó
int Stack::Top() const {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return -1;
    }
    return data[top];
}

// Ki?m tra xem stack có r?ng không
bool Stack::IsEmpty() const {
    return (top == -1);
}

// Tr? v? s? lý?ng ph?n t? hi?n t?i trong stack
int Stack::Size() const {
    return (top + 1);
}

// Xóa t?t c? các ph?n t? trong stack
void Stack::Clear() {
    top = -1;   // Ðánh d?u stack r?ng b?ng cách ð?t ð?nh là -1
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

// Gán giá tr? c?a m?t stack cho stack khác
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

// So sánh hai stack có b?ng nhau hay không
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

// So sánh hai stack có khác nhau hay không
bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}

// Chuy?n ð?i stack thành m?t m?ng
int* Stack::ToArray() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
 }
// In ra t?t c? các ph?n t? trong stack
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

// Ki?m tra xem stack ð? ð?y chýa
bool Stack::IsFull() const {
    return (top == capacity - 1);
}

// Thay ð?i s?c ch?a c?a stack
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

// L?y t?t c? các ph?n t? trong stack
int* Stack::GetAllElements() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
}

// Xóa m?t ph?n t? trong stack d?a trên ch? s?
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

// Ð?o ngý?c th? t? các ph?n t? trong stack
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

// Ki?m tra xem stack có ð?i x?ng không
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
    Stack reversedStack(capacity);  // T?o m?t Stack m?i ð? lýu tr? b?n sao ð?o ngý?c
    int* tempData = new int[top + 1];  // T?o m?t m?ng t?m ð? sao chép d? li?u hi?n t?i c?a Stack

    // Sao chép d? li?u t? Stack hi?n t?i vào m?ng t?m
    for (int i = 0; i <= top; i++) {
        tempData[i] = data[i];
    }

    // Ð?y các ph?n t? t? cu?i ð?n ð?u vào reversedStack
    for (int i = top; i >= 0; i--) {
        reversedStack.Push(tempData[i]);
    }

    delete[] tempData;  // Gi?i phóng b? nh? c?a m?ng t?m

    return reversedStack;  // Tr? v? b?n sao ð?o ngý?c c?a Stack
}
/* // Chuy?n ð?i stack thành queue
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