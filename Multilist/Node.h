#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS
#include <string>

class Node
{
	public:
		int student;
		int course;
		int grade;
		Node* right;
		Node* left;
		Node* up;
		Node* down;

		Node();
		Node(int studentCode, int courseCode);
		Node(int s, int c, int g);
		Node(std::string input);
		void init(int s, int c, int g);
		void print();
		
};

#endif
