#include <stdio.h>

#define size 20

typedef struct node{
	int data[size];
	int last;
}list_t;

//1.创建线性表并赋值
list_t *create_list()
{	
	//申请数组空间
	list_t *list = (list_t *)malloc(sizeof(list_t));

	if(list == NULL)
	{
		printf("空间申请失败!\n");
	} 
	list->last = -1;

	for(int i = 0; i < size; i++)
		list->data[i] = i*10;
	list->last = size - 1;

	return list;
}

//2.从头增加数据
void add_list_front(list_t *list,int data)
{
	for(int i = list->last-1; i >= 0; i--)
		list->data[i+1] = list->data[i];
	
	list->data[0] = data;

}

//3.指定位置增加数据(0< index <= size-1)
void add_list_index(list_t *list, int index, int data)
{
	for(int i = list->last-1; i >= index-1; i--)
		list->data[i+1] = list->data[i];
	
	list->data[index-1] = data;

}

//4.从头删除数据
void del_list_front(list_t *list)
{
	for(int i = 0; i < size - 1; i++)
		list->data[i] = list->data[i+1];
	list->data[size-1] = 0;
}

//5.指定位置删除数据
void del_list_index(list_t *list, int index)
{
	for(int i = index; i < size - 1; i++)
		list->data[i] = list->data[i+1];
	list->data[size-1] = 0;
}

//6.查询数据,返回数据的下表
void search_list(list_t *list, int data)
{
	for(int i = 0; i < size - 1; i++)
		if(list->data[i] == data)
		{
			printf("%3d \n", i);
			return 0;
		}
}

//7.指定位置修改数据
void modfiy_list_index(list_t *list, int index ,int data)
{
	list->data[index] = data;
}

//打印线性表
void print_list(list_t *list)
{
	for(int i = 0; i <= list->last; i++)
		printf("%3d ", list->data[i]);
	
	printf("\n");
}

int main()
{
	list_t *list_t0;
	list_t0 = create_list();
	print_list(list_t0);
	
	add_list_front(list_t0, 5);
	add_list_front(list_t0, 8);
	print_list(list_t0);

	add_list_index(list_t0, 6, 666);
	print_list(list_t0);

	add_list_index(list_t0, 7, 777);
	print_list(list_t0);

	del_list_front(list_t0);
	del_list_front(list_t0);
	print_list(list_t0);

	del_list_index(list_t0, 3);
	print_list(list_t0);
	del_list_index(list_t0, 3);
	print_list(list_t0);

	search_list(list_t0, 10);
	search_list(list_t0, 40);

	modfiy_list_index(list_t0, 1, 1);
	modfiy_list_index(list_t0, 2, 2);
	print_list(list_t0);
	return 0;
}