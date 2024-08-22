#ifndef NETWORK_H_EXISTS
#define NETWORK_H_EXISTS

#include "Node.h"

class Network
{
	Node* ref;
	int studentCount;
	int courseCount;
	int nodeCount;
	int cmax, rmax;
	
	public:
		Network();
		~Network();
		
		void deleteEmpty();
		void deleteFilled();
		void addNode(int s, int c, int g);
		void printRows();
		void printColumns();
};

#endif
