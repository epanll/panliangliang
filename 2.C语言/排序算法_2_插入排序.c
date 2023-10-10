#include <stdio.h>

//选择排序:不停的比较,最终确定插入数据的位置

int insertion_sort(int *array, int size)
{
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = array[i];

#if 0
		for (j = i; j > 0; j--)
		{
			if (temp < array[j - 1])
			{
				array[j] = array[j - 1];  //为插入的数据腾出空间
			}
			else
			{
				break;					  //跳出循环保存j的值
			}
		}
#endif
		for (j = i; j > 0 && temp < array[j - 1]; j--)
		{
			array[j] = array[j - 1];  //为插入的数据腾出空间
		}

		array[j] = temp;
		
	}

	return 0;
}

int main()
{
	int buf[10] = { 11, 0 ,8 , 7, 34, 99, 16, 22, 9, 55 };
	int size = sizeof(buf) / sizeof(int);
	printf("before:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	insertion_sort(buf, size);
	printf("_after:");
	for (int i = 0; i < size; i++)
		printf(" %-3d ", buf[i]);
	printf("\n");

	return 0;
}