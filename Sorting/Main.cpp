#include "Main.h"
void runMedium(bool print);
void runSmall(bool print);
void runLarge();
void runXL();

int main()
{
	srand(777);
	int value;
	int prints = 0;

	//int* i_small = new int[100];
        //int* h_small = new int[100];
        //int* q_small = new int[100];

	/*int* i_large = new int[5000];
        int* h_large = new int[5000];
        int* q_large = new int[5000];*/
	
	/*int* i_XL = new int[10000];        
	int* h_XL = new int[10000];
	int* q_XL = new int[10000];*/

	runSmall(true);
	runMedium(true);
	runLarge();
	runXL();
	return 0;
}

void runSmall(bool print)
{
  	int* i_small = new int[100];
        int* h_small = new int[100];
        int* q_small = new int[100];

	int value;
	int prints = 0;

        std::cout << "\n ========== 100 Integer Sorting Input ========== \n";
        for(int i = 0; i < 100; i++)
        {
                value = (rand() % 10000) + 1;
                *(i_small + i) = value;
                *(h_small + i) = value;
                *(q_small + i) = value;

                if(print == true)
		{
			if(prints % 20 == 0)
			{
				//std::cout << "\n";
			}

			if(value < 10)
			{
				std::cout << "   ";
			}
			else if(value < 100)
			{
				std::cout << "  ";
			}
			else if(value < 1000)
			{
				std::cout << " ";
			}
			else
			{

			}

			//std::cout << value << "  ";
			prints++;
		}
        }

        std::cout << "\n~ Insertion Sort (100) ~\n---------------------";
        insertionSort(100, i_small, print);
        std::cout << "\n~ Heapsort (100) ~\n--------------------";
        runHeapsort(100, h_small, print);
	std::cout << "\n~Quicksort (100) ~ \n--------------------";
	runQuicksort(100, q_small, print);
	std::cout << "\n";

        delete[] i_small;
        delete[] h_small;
        delete[] q_small;
};


void runMedium(bool print)
{
	int prints = 0;
	int value = 0;

	int* i_medium = new int[1000];
        int* h_medium = new int[1000];
        int* q_medium = new int[1000];
        std::cout << "\n\n ========== 1,000 Integer Sorting Input ========== \n";
        for(int i = 0; i < 1000; i++)
        {
                value = (rand() % 1000) + 1;
                *(i_medium + i) = value;
                *(h_medium + i) = value;
                *(q_medium + i) = value;

                if(print == true)
		{
			if(prints % 40 == 0)
			{
				//std::cout << "\n";
			}

			if(value < 10)
			{
				std::cout << "   ";
			}
			else if(value < 100)
			{
				std::cout << "  ";
			}
			else if(value < 1000)
			{
				std::cout << " ";
			}
			else
			{

			}

			//std::cout << value << "  ";
			prints++;
		}
        }

        std::cout << "\n~ Insertion Sort (1k) ~\n--------------------";
        insertionSort(1000, i_medium, print);
        std::cout << "\n~ Heapsort (1k) ~\n---------------------";
        runHeapsort(1000, h_medium, print);
        std::cout << "\n~ Quicksort (1k) ~\n--------------------";
        runQuicksort(1000, q_medium, print);
	std::cout << "\n";

        delete[] i_medium;
        delete[] h_medium;
        delete[] q_medium;	
}

void runLarge()
{
        int* i_large = new int[5000];
        int* h_large = new int[5000];
        int* q_large = new int[5000];

        int value;
        int prints = 0;

        std::cout << "\n ========== 5,000 Integer Sorting Input ========== \n";
        for(int i = 0; i < 5000; i++)
        {
                value = (rand() % 20000) + 1;
                *(i_large + i) = value;
                *(h_large + i) = value;
                *(q_large + i) = value;

		/*if(prints % 20 == 0)
                {
                        std::cout << "\n";
                }

                if(value < 10)
                {
                        std::cout << "   ";
                }
                else if(value < 100)
                {
                        std::cout << "  ";
                }
                else if(value < 1000)
                {
                        std::cout << " ";
                }
                else
                {

                }

                std::cout << value << "  ";
                prints++;*/
        }

        std::cout << "~ Insertion Sort (5k) ~\n--------------------";
        insertionSort(5000, i_large, false);
        std::cout << "\n~ Heapsort (5k) ~\n--------------------";
        runHeapsort(5000, h_large, false);
        std::cout << "\n~ Quicksort (5k) ~\n--------------------";
        runQuicksort(5000, q_large, false);
        std::cout << "\n";

        delete[] i_large;
        delete[] h_large;
        delete[] q_large;
};

void runXL()
{
        int* i_XL = new int[10000];
        int* h_XL = new int[10000];
        int* q_XL = new int[10000];

        int value;
        int prints = 0;

        std::cout << "\n ========== 10,000 Integer Sorting Input ========== \n";
        //We're not supposed to print the 10k values for this function//
	
	for(int i = 0; i < 10000; i++)
        {
                value = (rand() % 20000) + 1;
                *(i_XL + i) = value;
                *(h_XL + i) = value;
                *(q_XL + i) = value;

                /*if(prints % 20 == 0)
                {
                        std::cout << "\n";
                }

                if(value < 10)
                {
                        std::cout << "   ";
                }
                else if(value < 100)
                {
                        std::cout << "  ";
                }
                else if(value < 1000)
                {
                        std::cout << " ";
                }
                else
                {

                }

                std::cout << value << "  ";
                prints++;*/
        }

        std::cout << "~ Insertion Sort (10k) ~\n--------------------";
        insertionSort(10000, i_XL, false);
        std::cout << "\n~ Heapsort (10k) ~\n--------------------";
        runHeapsort(10000, h_XL, false);
        std::cout << "\n~ Quicksort (10k) ~\n--------------------";
        runQuicksort(10000, q_XL, false);
	std::cout << "\n";

        delete[] i_XL;
        delete[] h_XL;
        delete[] q_XL;
};

