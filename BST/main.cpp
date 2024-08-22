#include <iostream>
#include "Tree.h"
#include <fstream>


int main()
{
	int nodes[300];
	int nodeVal;
	int min;
	int max;
	std::ifstream inFile;
	inFile.open("input.txt");

	for(int i = 0; i < 300; i++)
	{
		inFile >> nodeVal;
		nodes[i] = nodeVal;
	}

	inFile.close();


	Tree* t = new Tree(nodes[0]);
	
	for(int i = 1; i < 300; i++)
	{
		t->addNode(t->root, nodes[i]);
	}
	
	
	std::cout << "\n===== * In Order Traversal * =====\n" << std::endl;
	t->inOrder(t->root);
	std::cout << "\n\n===== *~* BOUNDED In Order Traversal *~*\n";
	std::cout << "Input Lower Bound: ";
	std::cin >> min;
	
	if(min < 0)
	{
		min = 0;
	}

	bool success = false;
	int triesLeft = 3;

	while(success == false && triesLeft > 0)
	{
		std::cout << "\nInput Upper Bound: ";
	        std::cin >> max;

		if(max > min)
		{
			success = true;
			t->bounded_inOrder(min, max, t->root);
			std::cout << "\n\n";
		}
		else
		{
			std::cout << "\n\nError. Upper Bound must be greater than Lower Bound ( " << min << " )\n";
			std::cout << "Try again.\n\n";
			triesLeft--;
		}
	}


	delete t;
	return 0;
};

