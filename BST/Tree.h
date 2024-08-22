#ifndef TREE_H_EXISTS
#define TREE_H_EXISTS
#include "Node.h"

class Tree 
{
	public:
		Node* root;
		~Tree();
		Tree(int rootVal);
		Tree();
		void addNode(Node* parent, int val);
		void inOrder(Node* n);
		Node* insert(Node* parent, Node* helper, int value);
		void prune(Node* n);
		void bounded_inOrder(int min, int max, Node* n);

		//void deforest(Node* );
		void print();


};
#endif
