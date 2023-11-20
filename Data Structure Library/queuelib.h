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
    // khởi tạo
    QueueLib();

    // hủy bỏ
    ~QueueLib();

    // Xóa phần tử đầu tiên khỏi hàng đợi
    void dequeue();

    // Tạo giá trị và thêm vào cuối hàng đợi
    void enqueue(const T& value);

    // Thêm một phần tử vào cuối hàng đợi
    void push(const T& element);

    // Xóa phần tử ở đầu hàng đợi
    void pop();

    // Trả về tham chiếu đến phần tử ở đầu hàng đợi
    T& front();

    // Trả về tham chiếu đến phần tử ở cuối hàng đợi
    T& back();

    // Kiểm tra xem hàng đợi có trống hay không
    bool empty();

    // Trả về số lượng phần tử trong hàng đợi
    size_t size();

    // Thêm một phần tử vào cuối hàng đợi bằng cách sử dụng constructor của phần tử.
    template <typename... Args>
    void emplace(Args&&... args);

    // Hoán đổi nội dung của hai hàng đợi
    void swap(QueueLib& other);

    // Đảo ngược hàng đợi
    void reverse();

    // lấy phần tử thứ N
    T& getNthElement(size_t n);

    // Tìm một phần tử và trả về chỉ mục của nó (hoặc -1 nếu không tìm thấy)
    int find(const T& element);
    // Xuất hàng đợi
    void display();


private:
    QueueNode<T>* frontPtr;
    QueueNode<T>* backPtr;
    size_t count;
};

#endif // QUEUELIB_H
