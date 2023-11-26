#include "Treelib.h"
#include<iostream>
using namespace std;
//Ham khởi tạo
BST::BST()
{
	root = NULL;

}
//Ham hủy
BST::~BST() {}
//Tạo node lá
BST::node* BST::CreateLeaf(int key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}
//Tạo thêm cành lá
void BST::AddLeaf(node* Ptr, int key)
{
	if (root == NULL)
	{
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			AddLeaf(Ptr->left, key);
		}
		else
		{
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			AddLeaf(Ptr->right, key);
		}
		else
		{
			Ptr->right = CreateLeaf(key);
		}
	}
	else
	{
		cout << "Gia tri " << key << " da ton tai" << endl;
	}
}
//Duyệt cây theo InorderTraversal
void BST::InorderTraversal(node* Ptr)
{
	if (root != NULL)
	{
		if (Ptr->left != NULL)
		{
			InorderTraversal(Ptr->left);
		}
		cout << Ptr->key << " ";
		if (Ptr->right != NULL)
		{
			InorderTraversal(Ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty";
	}
}

//Duyệt cây theo PostorderTraversal
void BST::PostorderTraversal(node* Ptr)
{
	if (Ptr != NULL)
	{

		PostorderTraversal(Ptr->left);
		PostorderTraversal(Ptr->right);
		cout << Ptr->key << " ";
	}
}

//Duyệt cây theo PreorderTraversal
void BST::PreorderTraversal(node* Ptr)
{
	if (Ptr != NULL)
	{
		cout << Ptr->key << " ";
		PreorderTraversal(Ptr->left);
		PreorderTraversal(Ptr->right);

	}
}
//Trả về trị trí node cần tìm
BST::node* BST::ReturnNode(node* Ptr, int key)
{
	if (Ptr != NULL)
	{
		if (Ptr->key == key)
		{
			return Ptr;
		}
		else
		{
			if (key < Ptr->key)
			{
				return ReturnNode(Ptr->left, key);
			}
			else
			{
				return ReturnNode(Ptr->right, key);
			}
		}

	}
	else
	{
		return NULL;
	}
}
//Trả về giá trị node gốc
int BST::ReturnRootKey()
{
	if (root != NULL)
	{
		return root->key;
	}
	else
	{
		return NULL;
	}
}
//Tìm những node con của một node
void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(root, key);
	if (Ptr != NULL)
	{
		cout << "Parent node= " << Ptr->key << endl;
		Ptr->left == NULL ?
			cout << "Left Child = NULL" << endl :
			cout << "Left Chile = " << Ptr->left->key << endl;
		Ptr->right == NULL ?
			cout << "Right Child = NULL" << endl :
			cout << "Right Child = " << Ptr->right->key << endl;

	}
	else
	{
		cout << "Key " << key << " khong ton tai trong cay";
	}

}
//Tìm node có giá trị nhỏ nhất
int BST::FindSmallest(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is emty" << endl;
		return NULL;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return FindSmallest(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}

}
//Tìm node có giá trị lớn nhất
int BST::FindBiggest(node* Ptr)
{
	if (root == NULL)
	{
		cout << "The tree is emty" << endl;
		return NULL;
	}
	else
	{
		if (Ptr->right != NULL)
		{
			return FindBiggest(Ptr->right);
		}
		else
		{
			return Ptr->key;
		}
	}
}


//Xóa node
void BST::RemoveNode(node*& parent, int key)
{
	if (parent != NULL)
	{
		if (key < parent->key)
		{
			RemoveNode(parent->left, key);
		}
		else if (key > parent->key)
		{
			RemoveNode(parent->right, key);
		}
		else
		{
			// Node with the key to be deleted is found

			// Case 1: Node with no children
			if (parent->left == NULL && parent->right == NULL)
			{
				delete parent;
				parent = NULL;
			}
			// Case 2: Node with one child
			else if (parent->left == NULL)
			{
				node* temp = parent;
				parent = parent->right;
				delete temp;
			}
			else if (parent->right == NULL)
			{
				node* temp = parent;
				parent = parent->left;
				delete temp;
			}
			// Case 3: Node with two children
			else
			{
				int smallestInRightSubTree = FindSmallest(parent->right);
				parent->key = smallestInRightSubTree;
				RemoveNode(parent->right, smallestInRightSubTree);
			}
		}
	}
	else
	{
		cout << "Khong co node can xoa nam trong tree" << endl;
	}
}

//Tính độ cao mảng
int BST::TreeHeight(node* Ptr)
{
	if (Ptr == NULL)
	{
		return 0;
	}

	int leftHeight = TreeHeight(Ptr->left);
	int rightHeight = TreeHeight(Ptr->right);
	return 1 + max(leftHeight, rightHeight);
}




