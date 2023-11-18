#ifndef STACKLIB_H
#define STACKLIB_H

#include <iostream>

// �?nh ngh?a l?p Stack
class Stack {
private:
    int* data;      // M?ng l�u tr? c�c ph?n t? trong stack
    int capacity;   // S?c ch?a c?a stack
    int top;        // Ch? s? �?nh c?a stack

public:
    // Kh?i t?o stack v?i s?c ch?a cho tr�?c
    Stack(int capacity);

    // H?y b? stack v� gi?i ph�ng b? nh?
    ~Stack();

    // Th�m m?t ph?n t? v�o �?nh stack
    void Push(int element);

    // Lo?i b? ph?n t? tr�n �?nh stack
    void Pop();

    // Truy c?p ph?n t? tr�n �?nh stack m� kh�ng lo?i b? n�
    int Top() const;

    // Ki?m tra xem stack c� r?ng kh�ng
    bool IsEmpty() const;

    // Tr? v? s? l�?ng ph?n t? hi?n t?i trong stack
    int Size() const;

    // X�a t?t c? c�c ph?n t? trong stack
    void Clear();
    // T?o m?t b?n sao c?a stack
    Stack(const Stack& other);

    // G�n gi� tr? c?a m?t stack cho stack kh�c
    Stack& operator=(const Stack& other);

    // So s�nh hai stack c� b?ng nhau hay kh�ng
    bool operator==(const Stack& other) const;

    // So s�nh hai stack c� kh�c nhau hay kh�ng
    bool operator!=(const Stack& other) const;

    // Chuy?n �?i stack th�nh m?t m?ng
    int* ToArray();
    // In ra t?t c? c�c ph?n t? trong stack
    void PrintStack();

    // Ki?m tra xem stack �? �?y ch�a
    bool IsFull() const;

    // Thay �?i s?c ch?a c?a stack
    void Resize(int newCapacity);

    // L?y t?t c? c�c ph?n t? trong stack
    int* GetAllElements();

    // X�a m?t ph?n t? trong stack d?a tr�n ch? s?
    void RemoveByIndex(int index);

    // �?o ng�?c th? t? c�c ph?n t? trong stack
    void Reverse();

    // Ki?m tra xem stack c� �?i x?ng kh�ng
    bool IsSymmetric() const;

    // T?o m?t b?n sao �?o ng�?c c?a stack
    Stack ReverseCopy() const;

    // Chuy?n �?i stack th�nh queue
    //Queue ConvertToQueue() const;
};

#endif