#pragma once
#ifndef Treelib_h
#define Treelib_h

#include<iostream>
using namespace std;
class BST //Cây nhị phân
{

public:
	struct node
	{
		int key;
		node* left;
		node* right;
	};
	node* root;
	BST();												//Ham khoi tao
	~BST();												//Ham huy
	node* CreateLeaf(int key);							//Tạo node lá
	void AddLeaf(node* Ptr, int key);					//Tạo thêm cành lá

	void InorderTraversal(node* Ptr);					//Duyệt cây theo InorderTraversal

	void PreorderTraversal(node* Ptr);					//Duyệt cây theo PreorderTraversal

	void PostorderTraversal(node* Ptr);					//Duyệt cây theo PostorderTraversal

	node* ReturnNode(node* Ptr, int key);				//Trả về trị trí node cần tìm

	int ReturnRootKey();								//Trả về giá trị node gốc
	void PrintChildren(int key);						//Tìm những node con của một node

	int FindSmallest(node* Ptr);						//Tìm node có giá trị nhỏ nhất

	int FindBiggest(node* Ptr);							//Tìm node có giá trị lớn nhất
	void RemoveNode(node*& parent, int key);				//Xóa node
	int TreeHeight(node* Ptr);							//Tính độ cao mảng					


};

#endif 

