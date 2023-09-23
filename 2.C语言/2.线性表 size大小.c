#include <stdio.h>
#include <stdlib.h>

typedef struct  list_szie{
	int *data;			//指向存储数据的空间
	int size;			//指定空间的大小
	int last;			//数组的最后一位
}list_t;

//创建函数
list_t * create_list_size(int size)
{
	list_t * list = (list_t*)malloc(sizeof(list_t));
	if (list == NULL)
	{
		printf("创建失败! \n");
		return NULL;
	}

	list->data = malloc(size*sizeof(int));
	if (list->data == NULL)
	{
		printf("空间申请失败,创建失败! \n");
		return NULL;
	}

	list->size = size;

	list->last = -1;

	return list;
}

//判满函数
int Is_Full(list_t *list)
{
	return list->last == list->size - 1;
}

//判空函数
int Is_Null(list_t *list)
{
	return list->last == -1;
}

//从头增加数据
int add_front_list_size(list_t *list, int data)
{
	if(Is_Full(list))
	{
		printf("空间已满,无法执行从头增加数据操作!\n");
		return -1;
	}

	for(int i = list->last; i >= 0; i--)
		list->data[i+1] = list->data[i];

	list->data[0] = data;

	list->last ++;

	return 0;

}

//指定位置增加数据
int add_index_list_size(list_t *list, int index, int data)
{
	if(Is_Full(list) || index < 1 || index > list->last + 1)
	{
		printf("空间已满,无法执行从头增加数据操作!\n");
		return -1;
	}

	for(int i = list->last; i >= index; i--)
		list->data[i+1] = list->data[i];

	list->data[index] = data;

	list->last ++;

	return 0;

}

//从头删除数据
int del_front_list_size(list_t *list)
{
	if(Is_Null(list))
	{
		printf("表为空,无法执行从头删除操作!\n");
		return -1;
	}

	for(int i = 0; i < list->last; i++)
		list->data[i] = list->data[i+1];
	
	list->last --;

	return 0;

}

//指定位置删除数据
int del_index_list_size(list_t *list, int index)
{
	if(Is_Null(list) || index < 1 || index > list->last+1)
	{
		printf("表为空,无法执行从头删除操作!\n");
		return -1;
	}

	for(int i = index; i < list->last; i++)
		list->data[i] = list->data[i+1];
	
	list->last --;

	return 0;

}

//指定位置修改函数
int change_index_list_size(list_t *list, int index, int data)
{
	if(Is_Null(list) || index < 1 || index > list->last+1)
	{
		printf("位置错误,无法修改对应数据");
		return -1;
	}

	list->data[index - 1] = data;

	return 0;

}

//查找数据,并返回数据的下标
int search_list_size(list_t *list, int data)
{
	if(Is_Null(list))
	{
		printf("表为空,无法查找数据");
		return -1;
	}

	for(int i = 0; i <= list->last; i ++)
		if(list->data[i] == data)
		{
			printf("%d is locate in space %d \n", data, i+1);
			return 0;
		}
	
	//如果没有找到提示操作者
	printf("表中没有该数据!\n");
	
	return 0;
}

//打印
void print_list(list_t *list)
{
	if(Is_Null(list))
	{
		printf("表为空,无法打印!\n");
		return;
	}

	for(int i = 0; i <= list->last; i++)
		printf("%-3d ", list->data[i]);

	printf("\n");

	return;
}

//清空表格
int clean_list_size(list_t *list)
{
	list->last = -1;
	return 0;
}

//销毁释放空间
int dis_list_szie(list_t *list)
{
	free(list->data);
	free(list);
	list = NULL;
	return 0;
}

int main()
{
	printf("list_size:\n");

	list_t * list_t1 ; 
	//创建顺序表
	list_t1 = create_list_size(20);

	//从头增加数据
	for(int i = 0; i < 10; i ++)
	add_front_list_size(list_t1, i*10);
	printf("add_front:");
	print_list(list_t1);
	
	//指定位置增加数据
	add_index_list_size(list_t1, 3, 333);
	printf("add_index:");
	print_list(list_t1);

	//从头删除数据
	del_front_list_size(list_t1);
	printf("del_fornt:");
	print_list(list_t1);

	//指定位置删除数据
	del_index_list_size(list_t1, 10);
	printf("del_index:");
	print_list(list_t1);

	//指定位置修改数据
	change_index_list_size(list_t1, 5, 555);
	printf("chg_index:");
	print_list(list_t1);

	//查找数据并返回下标位置
	search_list_size(list_t1, 555);
	
	//清空表格
	clean_list_size(list_t1);
	print_list(list_t1);
	
	//销毁表格
	dis_list_szie(list_t1);
	print_list(list_t1);

	return 0;
}