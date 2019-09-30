#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void bubblesort(int *data, int n_data)
{
	for (int i = 0; i < n_data - 1; ++i)
	{
		for (int j = i + 1; j < n_data; ++j)
		{
			if (data[j] < data[i])
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;

			}
		}
	}



}

int main()
{
	const int n_data = 12;
	int data[n_data] = {1,1,2,5,6,4,2,1,3,6,9,12};
	int temp[n_data];

	bubblesort(data, n_data);

	for (int i = 0; i < n_data; ++i)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	int j = 0;
	for (int i = 0; i < n_data; ++i)
	{
		if (data[i] != data[i + 1]) temp[j++] = data[i];
	}

	//temp[j++] = data[n_data - 1];

	for (int i = 0; i < n_data; ++i)
	{
		data[i] = temp[i];
	}

	for (int i = 0; i < j; ++i)
	{
		printf("%d ", data[i]);
	}

	printf("\nnew array size: %d\n", j);

	system("pause");
	return 0;
}