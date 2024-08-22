#include "Network.h"
#include <iostream>

Network::Network()
{
	ref = new Node(0,0);
	studentCount = 0;
	courseCount = 0;
	nodeCount = 0;
};


Network::~Network()
{
	if(nodeCount == 0)
	{
		deleteEmpty();
	}
	else
	{
		deleteFilled();
	}
};


void Network::deleteEmpty()
{
	//This method is called IFF there are 0 nodes inside of the network//
	delete ref;

};


void Network::deleteFilled()
{
	//This method is called IFF there is at least 1 node inside of the Network//
	Node* row = ref;
	Node* helper;
	Node* temp;
	Node* t = ref;


	//Go to bottom row//
	while(row->down != nullptr)
	{
		row = row->down;
	}

	
	//Do this until row == ref//
	while(row->up != nullptr)
	{
		//Make helper the rightmost node in the row//
		helper = row;

		while(helper->right != nullptr)
		{
			helper = helper->right;
		}

		//Delete each node in this row now//
		while(helper->left != nullptr)
		{
			temp = helper->left;
			delete helper;
			nodeCount--;
			helper = temp;
		}

		//Now helper is the column header (row)//
		row = row->up;
		delete helper;
		courseCount--;
		nodeCount--;
	}

	//When the above while loop exits, row == ref and we are at the column header row//
	//Make row the rightmost node in the row//

	while(row->right != nullptr)
	{
		row = row->right;
	}

	while(row != nullptr)
	{
		temp = row->left;
		delete row;
		row = temp;
		studentCount--;
		nodeCount--;
	}
};


void Network::addNode(int s, int c, int g)
{
	bool studentExists = false;
	bool courseExists = false;
	bool stop = false;
	bool quit = false;
	Node* helper = ref;
	Node* rowHelper = ref;
	Node* tempr = ref;
	Node* tempc = ref;

	//Figure out if the header column for the new node exists//
	while(helper != nullptr && stop == false)
	{
		if(helper->student == s)
		{
			studentExists = true;
			stop = true;
		}
		else if(helper->student > s)
		{
			stop = true;
		}
		else
		{
			tempc = helper;
			helper = helper->right;
		}
	}

	//Figure out if the header row for the new node exists//
	while(rowHelper != nullptr && quit == false)
	{
		if(rowHelper->course == c)
		{
			courseExists = true;
			quit = true;
		}
		else if(rowHelper->course > c)
		{
			quit = true;
		}
		else
		{
			tempr = rowHelper;
			rowHelper = rowHelper->down;
		}
	}

	if(studentExists == false)
        {
                Node* newCol = new Node(s,0);
		helper = tempc;
		studentCount++;
		nodeCount++;
                if(helper->student > s)
                {
                        newCol->right = helper;
                        newCol->left = helper->left;

                        Node* temp1 = helper->left;
                        temp1->right = newCol;
                        helper->left = newCol;
                }
                else
                {
                        newCol->left = helper;
                        newCol->right = helper->right;
			Node* t = helper->right;
			
			if(t != nullptr)
			{
				t->left = newCol;
			}
                        helper->right = newCol;
                }
        }

	if(courseExists == false)
	{
		Node* newRow = new Node(0,c);
		rowHelper = tempr;
		courseCount++;
		nodeCount++;
		if(rowHelper->course > c)
		{
			newRow->down = rowHelper;
			newRow->up = rowHelper->up;

			Node* temp3 = rowHelper->up;
			temp3->down = newRow;
			rowHelper->up = newRow;
		}
		else
                {
                        newRow->up = rowHelper;
                        newRow->down = rowHelper->down;

			Node* t = rowHelper->down;
			if(t != nullptr)
			{
				t->up = newRow;
			}
                        rowHelper->down = newRow;
                }
	}

	Node* ptr = ref;

	while(ptr->student != s)
	{
		ptr = ptr->right;
	}

	while(ptr->course < c && ptr->down != nullptr)
	{
		ptr = ptr->down;
	}

	Node* n = new Node(s, c, g);
	nodeCount++;
	if(ptr->course > c)
	{
		n->down = ptr;
		n->up = ptr->up;

		Node* temp4 = ptr->up;
		temp4->down = n;
		ptr->up = n;
	}
	else
	{
		n->up = ptr;
		n->down = ptr->down;
		ptr->down = n;
	}

	ptr = ref;
	
	while(ptr->course != c)
	{
		ptr = ptr->down;
	}

	while(ptr->student < s && ptr->right != nullptr)
	{
		ptr = ptr->right;
	}

	if(ptr->student > s)
	{
		n->right = ptr;
		n->left = ptr->left;

		Node* temp6 = ptr->left;
		temp6->right = n;
		ptr->left = n;
	}
	else
	{
		n->left = ptr;
		n->right = ptr->right;
		ptr->right = n;
	}

};


//Print the students that are enrolled in each course//
void Network::printRows()
{
	Node* row = ref;
        Node* helper;

        if(ref->down == nullptr)
	{
		return;
	}

	row = ref->down;


	while(row != nullptr)
        {
                helper = row;
		std::cout << "Course #" << helper->course << " : students ";
                //std::cout << "\nThe next course is " << helper->down->course << "\n";

		while(helper->right != nullptr)
                {  
                        helper = helper->right;
			std::cout << helper->student << ", ";
                }
		std::cout << std::endl;
              	row = row->down;
        }
};


//Print the courses that each student takes//
void Network::printColumns()
{

        Node* col = ref;
        Node* helper;

        if(ref->right == nullptr)
        {
                return;
        }

        col = ref->right;


        while(col != nullptr)
        {
                helper = col;
                std::cout << "Student #" << helper->student << " : courses ";

                while(helper->down != nullptr)
                {
                        helper = helper->down;
                        std::cout << helper->course << ", ";
                }
                std::cout << std::endl;
                col = col->right;
        }
};

