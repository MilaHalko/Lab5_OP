#pragma once
#include "libraries.h"
int MaxDots = 5;


struct Dot
{
	float latitude;
	float longitude;
	string data;
};

class Node
{
public:
	Node();
	Node* child_1;
	Node* child_2;
	
	void AdjustBounds(Dot);
	float left;
	float top; 
	float right;
	float bottom;

	vector<Dot> dots;
};

Node::Node()
{
	child_1 = nullptr;
	child_2 = nullptr;
	// MBR
	left = 360;
	top = 0;
	right = 0;
	bottom = 180;
}

inline void Node::AdjustBounds(Dot dot)
{
	if (dot.latitude > right) right = dot.latitude;
	if (dot.latitude < left) left = dot.latitude;
	if (dot.longitude > top) top = dot.longitude;
	if (dot.longitude < bottom) bottom = dot.longitude;
}

class Tree
{
public:
	Tree();
	~Tree();

	void insert(string);
private:
	Node* root;
	int switcher;
	
	void ChooseLeaf();
	void Split(Node*);
};

Tree::Tree()
{
	root = nullptr;
	switcher = 0;
}

Tree::~Tree()
{
}

inline void Tree::insert(string data)
{
	ChooseLeaf();
	AdjustBounds();
	// .. 
}

inline void Tree::ChooseLeaf(Node* root, Dot dot)
{
	if (root->child_1 == nullptr && root->child_2 == nullptr)
	{
		if (root->dots.size() <= MaxDots + 1)
		{
			root->dots.push_back(dot);
		}
		else
		{
			Split(root);
		}
	}
	else
	{

	}
}

inline void Tree::Split(Node*)
{
	switcher = (switcher + 1) % 2;

}

inline int is_better(Node* child_1, Node* child_2, Dot dot)
{

}


