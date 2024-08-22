#include "Node.h"
#include <iostream>


Node::Node()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	isLeaf = true;
	value = -1;
};


Node::Node(Node* parentNode, int val)
{
	parent = parentNode;
	value = val;
};


void Node::setValue(int val)
{
	value = val;
};


void Node::setLeft(Node* l)
{
	left = l;
};


void Node::setRight(Node* r)
{
	right = r;
};


void Node::print()
{
	int l = 0;
	int r = 0;

	if(left != nullptr)
	{
		l = left->getValue();
	}
	
	if(right != nullptr)
	{
		r = right->getValue();
	}

	std::cout << "\nValue: " << value << "     L: " << l << "     R: " << r << std::endl;
};


Node* Node::getLeft()
{
	return left;
};


Node* Node::getRight()
{
	return right;
};


Node* Node::getParent()
{
	return parent;
}


int Node::getValue()
{
	return value;
};
