#pragma once
#include <iostream>
#include <string>
#include "stdlib.h"
#include "math.h"
using namespace std;

class Node_tree
{
private:
	int data;
	Node_tree* left;
	Node_tree* right;

public:
	Node_tree() { data = 0; left = nullptr, right = nullptr; };
	void setData(int adata) { data = adata; };
	void setLeft(Node_tree* aleft) { left = aleft; };
	void setRight(Node_tree* aright) { right = aright; };
	int getData() { return data; };
	Node_tree* getLeft() { return left; };
	Node_tree* getRight() { return right; };
};

class Tree 
{
private:
	int size;
	int index;
	Node_tree* root;
	Node_tree* treearray;
	Node_tree* temp;
	Node_tree* ptr;
public:
	Tree();
	Node_tree* getRoot();
	void setSize(int size);
	void addNode(int data);
	void addNode(int data, Node_tree* leaf);
	bool leftFull();
	void Preorder(Node_tree* node);
	void Inorder(Node_tree* node);
	void Postorder(Node_tree* node);
};

Tree::Tree() {
	root = nullptr;
	temp = new Node_tree();
	ptr = new Node_tree();
	index = 0;
}

Node_tree* Tree::getRoot() {
	return root;
}

void Tree::setSize(int s) {
	size = s;
	treearray = new Node_tree[size];
}

void Tree::addNode(int data) {
	temp->setData(data);
	temp->setLeft(nullptr);
	temp->setRight(nullptr);
	if (root == nullptr) {
		root = temp;
		treearray[index] = root;
		treearray[index].setData(root->getData());
		treearray[index].setLeft(root->getLeft());
		treearray[index].setRight(root->getRight());
	}
	else {
		ptr->setData(treearray[(int)(index / 2)].getData());
		ptr->setLeft(treearray[(int)(index / 2)].getLeft());
		ptr->setRight(treearray[(int)(index / 2)].getRight());
		
		if (ptr->getLeft() == nullptr) {
			ptr->setLeft(temp);
			cout << "left";
		}
		else {
			ptr->setRight(temp);
			cout << "right";
		}

		index++;
		treearray[index].setData(temp->getData());
		treearray[index].setLeft(temp->getLeft());
		treearray[index].setRight(temp->getRight());
	}
	for (int i = 0; i < size; i++)
	{
		cout << treearray[i].getData() << endl;
	}

}

	
	//if (data <= leaf->getData()) {
	//	if (leaf->getLeft() != nullptr)
	//		addNode(data, leaf->getLeft());
	//	else {
	//		Node_tree* n = new Node_tree();
	//		n->setData(data);
	//		leaf->setLeft(n);
	//	}
	//}
	//else {
	//	if (leaf->getRight() != nullptr)
	//		addNode(data, leaf->getRight());
	//	else {
	//		Node_tree* n = new Node_tree();
	//		n->setData(data);
	//		leaf->setRight(n);
	//	}
	//}


void Tree::Preorder(Node_tree* node)
{
	if (node)
	{
		cout << node->getData() << " ";
		Preorder(node->getLeft());
		Preorder(node->getRight());
	}
}

void Tree::Postorder(Node_tree* node)
{
	if (node)
	{
		Postorder(node->getLeft());
		Postorder(node->getRight());
		cout << node->getData() << " ";
	}
}

void Tree::Inorder(Node_tree* node)
{
	if (node)
	{
		Inorder(node->getLeft());
		cout << node->getData() << " ";
		Inorder(node->getRight());
	}
}
