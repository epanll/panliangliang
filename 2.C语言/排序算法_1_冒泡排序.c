#include <stdio.h>

//冒泡排序

int bubble_sort(int *array, int size)
{
    int i, j, flag, temp;
    for(i = size - 1; i >= 0; i--)
    {
        flag = 0;
        for(j = 0; j < i; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }

        if(flag == 0)
            break;          //没有任何交换,说明顺序已经排好,跳出循环
    }

    return 0;
}

int main()
{
    int buf[10] = {11, 0 ,8 , 7, 34, 99, 16, 22, 9, 55};
    int size = sizeof(buf)/sizeof(int);
    printf("before:");
    for(int i = 0; i < size; i++)
        printf(" %d ", buf[i]);
    printf("\n");

    bubble_sort(buf, size);
    printf("_after:");
    for(int i = 0; i < size; i++)
        printf(" %d ", buf[i]);
    printf("\n");

    return 0;
}