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
    
    Stack(int capacity); // khởi tạo 1 stack với sức chứa cho trước
    ~Stack();// Hủy bỏ stack và giải phóng bộ nhớ
    void Push(int element);// Thêm một phần tử vào đỉnh của stack
    void Pop(); // loại bỏ phần tử trên đỉnh stack
    int Top() const;    // Truy cập phần tử trên đỉnh stack mà không loại bỏ nó
    bool IsEmpty() const; // Kiểm tra xem stack có rỗng không
    int Size() const; // Trả về số lượnng phần tử hiện tại của stack
    void Clear(); // Xóa tất cả các phần tử  trong stack
    Stack(const Stack& other); // tạo bản sao của stack
    Stack& operator=(const Stack& other);     // Gán giá trị của một stack cho stack khác
    bool operator==(const Stack& other) const;  // So sánh hai stack có bằng nhau hay không
    bool operator!=(const Stack& other) const;   // So sánh hai stack có khác nhau hay không
    int* ToArray();  // Chuyển đổi stack thành một mảng
    void PrintStack();  // In ra tất cả các phần tử trong stack
    bool IsFull() const; // Kiểm tra xem stack đầy  chưa
    void Resize(int newCapacity); // Thay đổi sức chứa củaa stack
    int* GetAllElements();  // Lấy tất cả các phần tử trong stack
    void RemoveByIndex(int index); // Xóa một phần tử trong stack dựa trên chỉ số
    void Reverse(); // đảo ngược thứ tự các phần tử trong stack
    bool IsSymmetric() const; // kiểm tra xem stack có đối xứng không
    Stack ReverseCopy() const; // Tạo 1 bản sau đảo ngược của stack

 
};

#endif