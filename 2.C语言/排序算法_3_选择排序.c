#include <stdio.h>

//选择排序

int selection_sort(int *array, int size)
{
	int i, j, min, temp;
    for(i = 0; i < size; i++)
    {
        min = i;
        for(j = i + 1; j < size; j++)
        {
            if(array[min] < array[j])
                min = j;
        }

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

int main()
{
	int buf[10] = { 11, 0 ,8 , 7, 34, 99, 16, 22, 9, 55 };
	int size = sizeof(buf) / sizeof(int);
	printf("before:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	selection_sort(buf, size);
	printf("_after:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	return 0;
}