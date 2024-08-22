#include <iostream>

//Implementing with a queueu instead of a Heap class + Stack class to save space//

//Swap by ref//
void swap(int* A, int* B)
{
        int temp = *(A);
        *(A) = *(B);
        *(B) = temp;
};


void heapify(int* heap, int size, int index, int* steps, int* swaps)
{
	//This is a root-at-position-0 implementation because it's easier
	int* root = heap + 0;

	//Default: assume the value at index is bigger than both children	
	int biggest = index;

	int left = 2 * index + 1;
	int right = 2 * index + 2;

	
	if (left < size && *(heap + left) > *(heap + biggest))
	{
		biggest = left;
	}

	if (right < size && *(heap + right) > *(heap + biggest))
	{
		biggest = right;
	}
	
	if (biggest != index)
	{
		swap((root + index), (root + biggest));
		*(swaps) += 1;
		heapify(heap, size, biggest, steps, swaps);
	}
	
	*(steps) += 1;
};


void heapsort(int* heap, int size, int* steps, int* swaps)
{
   	int limit = (size / 2) - 1;
   	
       	//Build heap//	
	for (int a = limit; a > -1; a--)
	{
	    heapify(heap, size, a, steps, swaps);
	}

	
	//Sorting//
	for (int b = (size - 1); b > -1; b--)
	{
	
		int* root = heap;
		swap(root, (root + b));
		heapify(heap, b, 0, steps, swaps);
	}
};




void printArray(int* heap, int size)
{
	
    for (int i = 0; i < size; ++i)
    {
	    std::cout << *(heap + i) << "  ";
    }
    std::cout << "\n";
};

