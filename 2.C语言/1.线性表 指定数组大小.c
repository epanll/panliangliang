#include <stdio.h>
#include <stdlib.h>     //1.malloc 库

#define SIZE 20			//2.宏定义大写

typedef struct node{
	int data[SIZE];
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
		return NULL;	//3.失败判断
	} 
	list->last = -1;

	return list;
}

//判空函数
int Is_empty(list_t *list)
{
	return list->last == -1;
}

//判满函数
int Is_full(list_t *list)
{	
	return list->last == SIZE - 1;
}

//2.从头增加数据
int add_list_front(list_t *list,int data)
{
    if(Is_full(list))
	{
		printf("表已满,不能执行增加数据操作 \n");
		return -1;
	}

	for(int i = list->last; i >= 0; i--)
		list->data[i+1] = list->data[i];
	
	list->data[0] = data;

	list->last++;

	return 0;
}

//3.指定位置增加数据(0< index <= list->last,保证空间利用的充分,不能跳跃修改还没有存入数据的空间)
int add_list_index(list_t *list, int index, int data)
{
	if (Is_full(list) || index < 0 || index > (list->last + 1))
	{
		printf("表已满,不能执行增加数据操作 \n");
		return -1;
	}

	for(int i = list->last; i >= index-1; i--)
		list->data[i+1] = list->data[i];
	
	list->data[index-1] = data;

	list->last++;

	return 0;
}

//4.从头删除数据
int del_list_front(list_t *list)
{
	if (Is_empty(list))
	{
		printf("表为空,不能执行删除数据操作 \n");
		return -1;
	}

	for(int i = 0; i < list->last; i++)
		list->data[i] = list->data[i+1];

	list->last--;

	return 0;
}

//5.指定位置删除数据
int del_list_index(list_t *list, int index)
{
	if (Is_empty(list) || index < 0 || index > (list->last + 1))
	{
		printf("指定位置错误,不能执行删除数据操作 \n");
		return -1;
	}

	for(int i = index - 1; i < list->last; i++)
		list->data[i] = list->data[i+1];
	
	list->last--;

	return 0;

}

//6.查询数据,返回数据的下表
int search_list(list_t *list, int data)
{
	if (Is_empty(list))
	{
		printf("表位空,无法执行查找操作 \n");
		return -1;
	}

	for(int i = 0; i < list->last; i++)
		if(list->data[i] == data)
		{
			printf("data is locate in num:%d  space\n", i+1);
			return 0;
		}

	//如果没有找到,提醒
	printf("没有该数据 \n");

	return 0;
}

//7.指定位置修改数据
int modfiy_list_index(list_t *list, int index ,int data)
{
	if (Is_empty(list) || index < 1 || (index > list->last + 1))
	{
		printf("位置错误,无法修改数据");
		return -1;
	}

	list->data[index - 1] = data;

	return 0;
}

//打印线性表
void print_list(list_t *list)
{
	if (Is_empty(list))
	{
		printf("表位空,数据无法打印 \n");
	}

	for(int i = 0; i <= list->last; i++)
		printf("%3d ", list->data[i]);
	
	printf("\n");

}

//清空
int clean_list(list_t *list)
{
	list->last = -1;
	return 0;
}

//销毁空间
int dis_list(list_t *list)
{
	free(list);
	list = NULL;

	return 0;
}

int main()
{
	list_t *list_t0;
	list_t0 = create_list();
	
	//从头增加10个数据
	for (int i = 0; i < 10; i++)
		add_list_front(list_t0, i*10);
	print_list(list_t0);

	//指定位置增加数据
	add_list_index(list_t0, 6, 66);
	print_list(list_t0);

	add_list_index(list_t0, 7, 77);
	print_list(list_t0);

	//从头删除数据
	del_list_front(list_t0);
	print_list(list_t0);

	//指定位置删除数据
	del_list_index(list_t0, 1);
	print_list(list_t0);

	//查找数据
	search_list(list_t0, 40);
	
	//指定位置修改数据
	modfiy_list_index(list_t0, 3, 8);
	print_list(list_t0);

	//清空表
	clean_list(list_t0);
	print_list(list_t0);

	//销毁malloc申请空间
	dis_list(list_t0);

	return 0;
}