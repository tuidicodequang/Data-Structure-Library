// LinkedList.cpp

#include <iostream>
#include "LinkedListlib.h"

Node* LinkedList::CreateNode(int init_data) {
    return new Node(init_data);
}

void LinkedList::CreateList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::AddHead(Node* node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
}

void LinkedList::AddTail(Node* node) {
    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void LinkedList::InsertAfterQ(Node* p, Node* q) {
    if (q == nullptr) {
        std::cout << "Error: Invalid Node. Cannot insert after nullptr." << std::endl;
        return;
    }

    p->next = q->next;
    q->next = p;

    if (q == tail) {
        tail = p;
    }
}

int LinkedList::RemoveHead(int& removedData)
{
    if (head == nullptr) {
        // Danh sách rỗng
        return -1; // Hoặc bạn có thể ném một exception tại đây
    }

    Node* temp = head;
    removedData = temp->data;
    head = head->next;

    if (head == nullptr) {
        // Danh sách chỉ có một phần tử
        tail = nullptr;
    }

    delete temp;

    return 0;
}

int LinkedList::RemoveTail(int& x) {
    if (head == nullptr) {
        std::cout << "Error: List is empty. Cannot remove tail." << std::endl;
        return -1;
    }

    if (head == tail) {
        return RemoveHead(x);
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    Node* trailingNode = tail;
    x = tail->data;
    tail = current;
    tail->next = nullptr;
    delete trailingNode;

    return 0;
}



void LinkedList::InsertBeforeP(Node* p, Node* q) {
    if (p == nullptr || q == nullptr) {
        std::cout << "Error: Invalid Node. Cannot insert before nullptr." << std::endl;
        return;
    }

    if (q == head) {
        AddHead(p);
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != q) {
        current = current->next;
    }

    if (current == nullptr) {
        std::cout << "Error: Node not found in the list." << std::endl;
        return;
    }

    p->next = q;
    current->next = p;
}

void LinkedList::ReverseList() {
    Node* previous = nullptr;
    Node* current = head;
    Node* following = nullptr;

    while (current != nullptr) {
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }

    tail = head;
    head = previous;
}

Node* LinkedList::GetNode(int index) {
    if (index < 0) {
        std::cout << "Error: Invalid index." << std::endl;
        return nullptr;
    }

    Node* current = head;
    int count = 0;

    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        std::cout << "Error: Index out of range." << std::endl;
        return nullptr;
    }

    return current;
}

void LinkedList::PrintList() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}



Node* LinkedList::Search(int x) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == x) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

int LinkedList::Length() {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void LinkedList::DestroyList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}
