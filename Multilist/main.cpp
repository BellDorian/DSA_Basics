#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include "Network.h"

int main()
{
	Network system;
	std::ifstream inFile;
	std::string input;
	int s, c, g;
	inFile.open("multilist_input.txt");

	//Parse data for node creation//
	while(getline(inFile, input)) 
	{
		std::string s = "";
	        std::string c = "";
        	std::string g = "";

        	int part = 0;
       		char character;
        	int size = sizeof(input) / sizeof(int);

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
        
		//Now convert the substrings to integers//
		std::istringstream iss1(s);
		std::istringstream iss2(c);
		std::istringstream iss3(g);
		int x, y, z;
		iss1 >> x;
		iss2 >> y;
		iss3 >> z;

		system.addNode(x,y,z);
	}

	inFile.close();
	
	std::cout << "\n===== * Student Rosters by Course * =====\n";
	system.printRows();
	std::cout << "\n\n===== * Course Enrollment by Student * =====\n";
	system.printColumns();
	std::cout << "\n\n";

	return 0;
};
