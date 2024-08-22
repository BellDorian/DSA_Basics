void quicksort(int* dataset, int lowIndex, int highIndex, int* steps, int* swaps);
int partition(int* dataset, int lowIndex, int highIndex, int* steps, int* swaps);
void swap(int* i, int* j, int* swaps);


void quicksort(int* dataset, int lowIndex, int highIndex, int* steps, int* swaps)
{
	if(lowIndex < highIndex)
	{
		int indexOf_partition = partition(dataset, lowIndex, highIndex, steps, swaps);
		*(steps) += 1;
		int belowSplit = indexOf_partition - 1;
		int aboveSplit = indexOf_partition + 1;
		
		quicksort(dataset, lowIndex, belowSplit, steps, swaps);
		*(steps) += 1;
		quicksort(dataset, aboveSplit, highIndex, steps, swaps);
		*(steps) += 1;
	}

};


int partition(int* dataset, int lowIndex, int highIndex, int* steps, int* swaps)
{
	int pivot = *(dataset + highIndex);
	int i = lowIndex - 1;

	for(int j = lowIndex; j <= highIndex - 1; j++)
	{
		*(steps) += 1;
		int* j_pos = (dataset + j);

		if(pivot > *(j_pos))
		{
			i++;
			int* i_pos = (dataset + i);
			swap(i_pos, j_pos, swaps);
		}
	}

	swap((dataset + i + 1), (dataset + highIndex), swaps);
	return (i + 1);
};

void swap(int* i, int* j, int* swaps)
{
	*(swaps) += 1;
	int temp = *(i);
	*(i) = *(j);
	*(j) = temp;
};
