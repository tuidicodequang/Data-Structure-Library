#ifndef STACKLIB_H
#define STACKLIB_H

#include <iostream>

// định nghĩa lớp stack
class Stack {
private:
    int* data;      // Mảng lưu trữ các phần tử trong stack
    int capacity;   // Sức chứa của stack
    int top;        // Ch? số đỉnh của stack

public:
    // khởi tạo 1 stack với sức chứa cho trước
    Stack(int capacity);

    // Hủy bỏ stack và giải phóng bộ nhớ
    ~Stack();

    // Thêm một phần tử vào đỉnh của stack
    void Push(int element);

    // loại bỏ phần tử trên đỉnh stack
    void Pop();

    // Truy cập phần tử trên đỉnh stack mà không loại bỏ nó
    int Top() const;

    // Kiểm tra xem stack có rỗng không
    bool IsEmpty() const;

    // Trả về số lượnng phần tử hiện tại của stack
    int Size() const;

    // Xóa tất cả các phần tử  trong stack
    void Clear();

    // tạo bản sao của stack
    Stack(const Stack& other);

    // Gán giá trị của một stack cho stack khác
    Stack& operator=(const Stack& other);

    // So sánh hai stack có bằng nhau hay không
    bool operator==(const Stack& other) const;

    // So sánh hai stack có khác nhau hay không
    bool operator!=(const Stack& other) const;

    // Chuyển đổi stack thành một mảng
    int* ToArray();

    // In ra tất cả các phần tử trong stack
    void PrintStack();

    // Kiểm tra xem stack đầy  chưa
    bool IsFull() const;

    // Thay đổi sức chứa củaa stack
    void Resize(int newCapacity);

    // Lấy tất cả các phần tử trong stack
    int* GetAllElements();

    // Xóa một phần tử trong stack dựa trên chỉ số
    void RemoveByIndex(int index);

    // đảo ngược thứ tự các phần tử trong stack
    void Reverse();

    // kiểm tra xem stack có đối xứng không
    bool IsSymmetric() const;

    // Tạo 1 bản sau đảo ngược của stack
    Stack ReverseCopy() const;

    // chuyển đổi stack thành queue
    //Queue ConvertToQueue() const;
};

#endif