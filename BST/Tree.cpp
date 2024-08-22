#include <iostream>
#include "Tree.h"


Tree::Tree()
{
	root = new Node();
};


Tree::Tree(int rootVal)
{
	root = new Node();
	root->setValue(rootVal);
};


void Tree::prune(Node* n)
{
	if(n == nullptr)
	{
		return;
	}

	prune(n->left);
	prune(n->right);

	delete n;
	root = nullptr;
};


Tree::~Tree()
{
	prune(root);
};


Node* Tree::insert(Node* parent, Node* helper, int val)
{
	//
	if (helper->value == -1)
	{
       		return new Node(parent, val);
    	}
	
	if (val < helper->value)
	{
		helper->left = insert(helper, helper->left, val);
	}
	    // if the given key is more than the root node, recur for the right subtree
	else
	{
		root->right = insert(helper, helper->right, val);
    	}
	 
     	return root;
};


void Tree::addNode(Node* parent, int val)
{
       	Node* current = root;
	Node* p = root;
	std::string side = "none";
		
        while(current != nullptr)
        {
                if(val > current->value)
                {
                        p = current;
			current = current->right;
			side = "r";
			
                }
                else if(val < current->value)
                {
                        p = current;
			current = current->left;
			side = "l";
                }
		else
		{
			return;
		}
        }

        Node* n = new Node(parent, val);

	if(side == "r")
	{
		p->right = n;
	}
	else if(side == "l")
	{
		p->left = n;
	}
	else
	{
		std::cout << "\nFUCK\n";
	}	
};




void Tree::inOrder(Node* n)
{
	if(n == nullptr)
	{
		return;
	}
	
	inOrder(n->left);
	std::cout << "  " << n->value << "  ";
	inOrder(n->right);
};


void Tree::bounded_inOrder(int min, int max, Node* n)
{
	if(n == nullptr)
	{
		return;
	}

	bounded_inOrder(min, max, n->left);
	if(n->value > min && n->value < max)
	{
		std::cout << "  " << n->value << "  ";
	}
	bounded_inOrder(min, max, n->right);
};
	
