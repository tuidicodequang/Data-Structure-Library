#ifndef QUEUELIB_H
#define QUEUELIB_H
#pragma once
#include <iostream>

template <typename T>
class QueueNode {
public:
    T data;
    QueueNode<T>* next;

    QueueNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class QueueLib {
public:
   
    QueueLib();  // khởi tạo
    ~QueueLib();// hủy bỏ
    void dequeue();  // Xóa phần tử đầu tiên khỏi hàng đợi
     void enqueue(const T& value); // Tạo giá trị và thêm vào cuối hàng đợi
    void push(const T& element);   // Thêm một phần tử vào cuối hàng đợi
       T& front();    // Trả về tham chiếu đến phần tử ở đầu hàng đợi
    T& back();// Trả về tham chiếu đến phần tử ở cuối hàng đợi
    bool empty();  // Kiểm tra xem hàng đợi có trống hay không
    size_t size();// Trả về số lượng phần tử trong hàng đợi

    template <typename... Args> // Thêm một phần tử vào cuối hàng đợi bằng cách sử dụng constructor của phần tử.
    void emplace(Args&&... args);
    void swap(QueueLib& other); // Hoán đổi nội dung của hai hàng đợi
    void reverse(); // Đảo ngược hàng đợi
    T& getNthElement(size_t n);// lấy phần tử thứ N
    int find(const T& element);// Tìm một phần tử và trả về chỉ mục của nó (hoặc -1 nếu không tìm thấy)
    void display();   // Xuất hàng đợi


private:
    QueueNode<T>* frontPtr;
    QueueNode<T>* backPtr;
    size_t count;
};

#endif // QUEUELIB_H
