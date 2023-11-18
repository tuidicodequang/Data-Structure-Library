#include <iostream>
#include "stacklib.h"

int main() {
    // Tạo một đối tượng Stack
    Stack stack(5);

    // Thêm các phần tử vào Stack
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    // In ra Stack ban đầu
    std::cout << "Stack ban dau: ";
    stack.PrintStack();

    // Chuyển đổi Stack thành một mảng
    int* arr = stack.ToArray();
    std::cout << "Mang chua cac phan tu trong Stack: ";
    for (int i = 0; i < stack.Size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;

   

    // Kiểm tra xem Stack đã đầy chưa
    if (stack.IsFull()) {
        std::cout << "Stack da day" << std::endl;
    }
    else {
        std::cout << "Stack chua day" << std::endl;
    }

    // Thay đổi sức chứa của Stack
    stack.Resize(10);
    std::cout << "Stack sau khi thay doi suc chua: ";
    stack.PrintStack();

    // Lấy tất cả các phần tử trong Stack
    int* allElements = stack.GetAllElements();
    std::cout << "Tat ca cac phan tu trong Stack: ";
    for (int i = 0; i < stack.Size(); i++) {
        std::cout << allElements[i] << " ";
    }
    std::cout << std::endl;
    delete[] allElements;

    // Xóa một phần tử trong Stack dựa trên chỉ số
    stack.RemoveByIndex(2);
    std::cout << "Stack sau khi xoa phan tu theo chi so: ";
    stack.PrintStack();

    // Đảo ngược thứ tự các phần tử trong Stack
    stack.Reverse();
    std::cout << "Stack sau khi dao nguoc: ";
    stack.PrintStack();

    // Kiểm tra xem Stack có đối xứng không
    if (stack.IsSymmetric()) {
        std::cout << "Stack doi xung" << std::endl;
    }
    else {
        std::cout << "Stack khong doi xung" << std::endl;
    }

    return 0;
}