#include "stacklib.h"

// Định nghĩa lớp stack và các phương thức

// khởi tạo stack với sức chứa cho trước
Stack::Stack(int capacity) {
    this->capacity = capacity;
    data = new int[capacity];
    top = -1;   // khởi tạo đỉnh của stack là -1 để đánh dấu stack rỗng
}

// Hủy bỏ stack 
Stack::~Stack() {
    delete[] data;
}

// Thêm một phần tử vào đỉnh stack
void Stack::Push(int element) {
    if (top == capacity - 1) {
        std::cout << "Stack overflow!\n";
        return;
    }
    top++;
    data[top] = element;
}

// loại bỏ phần tử trên đỉnh stack
void Stack::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return;
    }
    top--;
}

// Truy cập phần tử trên đỉnh stack mà không loại bỏ nó
int Stack::Top() const {
    if (IsEmpty()) {
        std::cout << "Stack is empty!\n";
        return -1;
    }
    return data[top];
}

// Kiểm tra rỗng
bool Stack::IsEmpty() const {
    return (top == -1);
}

// Trả về số lượnng phần tử hiện tại của stack
int Stack::Size() const {
    return (top + 1);
}

// Xóa tất cả các phần tử  trong stack
void Stack::Clear() {
    top = -1;   // Đánh dấu stack rỗng bằng cách đặt đỉnh là -1
}
// tạo bản sao của stack
Stack::Stack(const Stack& other) {
    capacity = other.capacity;
    top = other.top;
    data = new int[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// Gán giá trị của một stack cho stack khác
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

// Chuyển đổi stack thành một mảng
int* Stack::ToArray() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
 }
// In ra tất cả các phần tử trong stack
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

// Kiểm tra xem stack đầy  chưa
bool Stack::IsFull() const {
    return (top == capacity - 1);
}

// Thay đổi sức chứa củaa stack
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

// Lấy tất cả các phần tử trong stack
int* Stack::GetAllElements() {
    int* arr = new int[top + 1];
    for (int i = 0; i <= top; i++) {
        arr[i] = data[i];
    }
    return arr;
}

// Xóa một phần tử trong stack dựa trên chỉ số
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

// Đảo ngược phần tử trong stack
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

// kiểm tra đối xứng
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
    Stack reversedStack(capacity);  //tạo một mảng để lưu giá trị đảo ngược
    int* tempData = new int[top + 1];  // Tạo một mảng tạm để lưu trữ dữ liệu hiện tại của stack

    // Sao chép dữ liệu hiện tại vào mảng tạm
    for (int i = 0; i <= top; i++) {
        tempData[i] = data[i];
    }

    // Đẩy các phần tử từ cuối đến đầu vào reversedStack
    for (int i = top; i >= 0; i--) {
        reversedStack.Push(tempData[i]);
    }

    delete[] tempData;  // Giải phóng bộ nhớ mảng tạm

    return reversedStack;  // trả về bản sao đảo ngược của stack
}