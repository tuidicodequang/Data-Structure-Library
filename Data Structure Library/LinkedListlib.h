#pragma once
// LinkedList.hpp

#ifndef LinkedList_hpp
#define LinkedList_hpp

class Node {
public:
    int data;         // Dữ liệu của Node
    Node* next;       // Con trỏ đến Node kế tiếp

    // Constructor
    Node(int init_data) : data(init_data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;        // Con trỏ đến đầu danh sách
    Node* tail;        // Con trỏ đến cuối danh sách

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Khai báo các phương thức
    Node* CreateNode(int init_data);         // Tạo một Node mới với dữ liệu khởi tạo
    void CreateList();                       // Khởi tạo một danh sách liên kết rỗng
    void AddHead(Node* node);                // Thêm một Node vào đầu danh sách
    void AddTail(Node* node);                // Thêm một Node vào cuối danh sách
    void InsertAfterQ(Node* p, Node* q);     // Chèn một Node sau một Node cho trước
    int RemoveHead(int& x);                  // Xóa Node từ đầu danh sách
    int RemoveTail(int& x);                  // Xóa Node từ cuối danh sách
    void InsertBeforeP(Node* p, Node* q);    // Chèn một Node trước một Node cho trước
    void ReverseList();                      // Đảo ngược danh sách
    Node* GetNode(int index);                // Lấy Node tại một chỉ mục cụ thể
    void PrintList();                        // In ra các phần tử trong danh sách
    Node* Search(int x);                     // Tìm kiếm một Node có dữ liệu cho trước
    int Length();                            // Độ dài của danh sách
    void DestroyList();                      // Hủy bỏ toàn bộ danh sách
};

#endif
