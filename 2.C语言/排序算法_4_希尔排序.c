#include <stdio.h>

//希尔排序,看似简单,实则复杂

int shell_sort(int *array, int size)
{
	int D, P, i, temp;
    D = size;
    for(D = size/2; D > 0; D /=2)                 //希尔排序
    {
        for(P = D; P < size; P++)                 //插入排序
        {
            temp = array[P];
            for(i = P; i >= D && temp < array[i-D]; i -= D )
                array[i] = array[i-D];
            array[i] = temp;
        }

    }

}

int main()
{
	int buf[] = { 11, 0 ,8 , 7, 34, 99, 16, 22, 9, 55, 4, 3, 1, 17 };
	int size = sizeof(buf) / sizeof(int);
	printf("before:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	shell_sort(buf, size);
	printf("_after:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	return 0;
}