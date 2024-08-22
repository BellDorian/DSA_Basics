#include "Node.h"
#include <iostream>
#include <sstream>


Node::Node()
{	
	student = 0;
	course = 0;
	grade = 0;
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;	
};


Node::Node(int studentCode, int courseCode)
{
	student = studentCode;
	course = courseCode;
};


Node::Node(int s, int c, int g)
{
	student = s;
	course = c;
	grade = g;
};

void Node::init(int s, int c, int g)
{
	student = s;
	course = c;
	grade = g;
}


Node::Node(std::string input)
{
	std::string s = "";
	std::string c = "";
	std::string g = "";

	int part = 0;
	char character;
	int size = sizeof(input) / sizeof(int);

	//I hate C++ so damn much//
	//Jump through 100 hoops to split the string//
	for(int i = 0; i < size; i++)
	{
		character = input[i];
		if(input[i] != ',' && input[i] != ')' && input[i] != '(')
		{
			if(part <= 1)
			{
				s += character;
			}
			else if(part == 2)
			{
				c += character;
			}
			else
			{
				g += character;
			}
		}
		else
		{
			part++;
		}
	}

	//Now convert the fucking substrings to integers//
	std::cout << "s: " << s << "\nc: " << c << "\ng: " << g << std::endl;
	std::istringstream iss1(s);
	std::istringstream iss2(c);
	std::istringstream iss3(g);
        int x, y, z;
	iss1 >> x;
	iss2 >> y;
	iss3 >> z;

	student = x;
	course = y;
	grade = z;
	


};


void Node::print()
{
	std::cout << "(" << student << ", " << course << ", " << grade << ")" << std::endl;
};

