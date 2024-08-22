#include "heapsort.h"
#include "quicksort.h"
#include <iostream>
#include <cstdlib>

//Quicksort//
void runQuicksort(int elements, int* dataset, bool printSorted)
{
	int stepCount = 0;
        int* swaps = &stepCount;
        int swapCount = 0;
        int* steps = &swapCount;

	int size = elements - 1;

        quicksort(dataset, 0, size, steps, swaps);

	int count = 0;
       	int value;

        if(printSorted == true)
	{
		for(int i = 0; i < elements; i++)
        	{
			value = *(dataset + i);

			if(count % 20 == 0)
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
			count++;
	        }
	}

        std::cout << "\nSwaps: " << *(swaps);
        std::cout << "\nSteps: " << *(steps) << "\n";
};


//Heapsort//
void runHeapsort(int elements, int* dataset, bool printSorted)
{
        int limit = (elements / 2) - 1;

        int stepCount = 0;
        int swapCount = 0;
        int* steps = &stepCount;
        int* swaps = &swapCount;

        for(int last = limit; last > -1; last--)
        {
               heapify(dataset, elements, last, steps, swaps);
        }

        heapsort(dataset, elements, steps, swaps);

 	int value;
	int count = 0;

        if(printSorted == true)
        {

                for(int i = 0; i < elements; i++)
                {
                        value = *(dataset + i);

                        if(count % 20 == 0)
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
                        count++;
                }
        }

        std::cout << "\nSwaps: " << *(swaps);
        std::cout << "\nSteps: " << *(steps) << "\n";	 
};


//Insertion Sort//
void insertionSort(int elements, int* dataset, bool printSorted)
{
       int inside, ref;
       int steps = elements;
       int count = 0;
       int swaps = 0;

       for(int outside = 0; outside < elements; outside++)
        {
                ref = *(dataset + outside);
                inside = outside - 1;

                while(inside > -1 && *(dataset + inside) > ref)
                {
                        *(dataset + inside + 1) = *(dataset + inside);
			swaps++;
                        inside--;
                }

                *(dataset + inside + 1) = ref;
		swaps++;
        }


	int value;

	if(printSorted == true)
	{

		for(int i = 0; i < elements; i++)
		{
			value = *(dataset + i);
			
			if(count % 20 == 0)
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
			count++;
		}
	}

       	std::cout << "\nSwaps: " << swaps;
	std::cout << "\nSteps: " << steps << "\n";
};

