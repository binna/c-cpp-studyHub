# include <stdio.h>

void InsertSort(int Data[], int Length)
{
	for (int i = 0; i < Length - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int z = j + 1; z <= i + 1; z++)
			{
				if (Data[j] > Data[z])
				{
					int temp = Data[j];
					Data[j] = Data[z];
					Data[z] = temp;
				}
			}
		}
	}
}


int main(void)
{
	int data[] = { 1,5,3,4,2 };
	int size = sizeof(data) / sizeof(int);

	InsertSort(data, size);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", data[i]);
	}

	return 0;
}