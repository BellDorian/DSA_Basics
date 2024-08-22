#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

class Node 
{
	public:
		Node* left;
		Node* right;
		Node* parent;
		bool isLeaf;
		int value;

		Node();
		Node(Node* parentNode, int val);
		//Node(Node* p, Node* l, Node* r);
		void setLeft(Node* l);
		void setRight(Node* r);
		void setParent(Node* p);
		void setValue(int val);
		void print();
		int getValue();
		Node* getLeft();
		Node* getRight();
		Node* getParent();



};
#endif
