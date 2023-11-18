#ifndef STACKLIB_H
#define STACKLIB_H

#include <iostream>

// Ð?nh ngh?a l?p Stack
class Stack {
private:
    int* data;      // M?ng lýu tr? các ph?n t? trong stack
    int capacity;   // S?c ch?a c?a stack
    int top;        // Ch? s? ð?nh c?a stack

public:
    // Kh?i t?o stack v?i s?c ch?a cho trý?c
    Stack(int capacity);

    // H?y b? stack và gi?i phóng b? nh?
    ~Stack();

    // Thêm m?t ph?n t? vào ð?nh stack
    void Push(int element);

    // Lo?i b? ph?n t? trên ð?nh stack
    void Pop();

    // Truy c?p ph?n t? trên ð?nh stack mà không lo?i b? nó
    int Top() const;

    // Ki?m tra xem stack có r?ng không
    bool IsEmpty() const;

    // Tr? v? s? lý?ng ph?n t? hi?n t?i trong stack
    int Size() const;

    // Xóa t?t c? các ph?n t? trong stack
    void Clear();
    // T?o m?t b?n sao c?a stack
    Stack(const Stack& other);

    // Gán giá tr? c?a m?t stack cho stack khác
    Stack& operator=(const Stack& other);

    // So sánh hai stack có b?ng nhau hay không
    bool operator==(const Stack& other) const;

    // So sánh hai stack có khác nhau hay không
    bool operator!=(const Stack& other) const;

    // Chuy?n ð?i stack thành m?t m?ng
    int* ToArray();
    // In ra t?t c? các ph?n t? trong stack
    void PrintStack();

    // Ki?m tra xem stack ð? ð?y chýa
    bool IsFull() const;

    // Thay ð?i s?c ch?a c?a stack
    void Resize(int newCapacity);

    // L?y t?t c? các ph?n t? trong stack
    int* GetAllElements();

    // Xóa m?t ph?n t? trong stack d?a trên ch? s?
    void RemoveByIndex(int index);

    // Ð?o ngý?c th? t? các ph?n t? trong stack
    void Reverse();

    // Ki?m tra xem stack có ð?i x?ng không
    bool IsSymmetric() const;

    // T?o m?t b?n sao ð?o ngý?c c?a stack
    Stack ReverseCopy() const;

    // Chuy?n ð?i stack thành queue
    //Queue ConvertToQueue() const;
};

#endif