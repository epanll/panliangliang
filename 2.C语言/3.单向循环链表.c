#include <stdio.h>
#include <stdlib.h>

typedef struct link_node
{
	int data;
	struct link_node * next;	
}link_t;

//创建链表
link_t *create_link()
{
	link_t * head = (link_t *)malloc(sizeof(link_t));
	if(head == NULL)
	{
		printf("空间申请失败!\n");
		return NULL;
	}

	head->next = head; 		//头结点指向自己

	return head;

}

//判空
int Is_NULL(link_t * head)
{
	return head->next == head;
}

//头增加
int add_link_circle(link_t * head, int data)
{
	link_t * newnode = (link_t *)malloc(sizeof(link_t));
	if(newnode == NULL)
	{
		printf("空间申请失败!\n");
		return -1;
	}

	//存入数据
	newnode->data = data;

	//先操作新节点,再操作head
	newnode->next = head->next;
	head->next = newnode;

	return 0;
}

//打印链表
void print_link(link_t * head)
{
	if(Is_NULL(head))
	{
		printf("表位空,无法打印!\n");
		return;
	}

	link_t * temp = head;	//记录下头结点的位置

	head = head->next;	//跳过头结点
	while(head != temp)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
	printf("\n");

	return;
}


int main()
{
	printf("link_circle \n");

	link_t * link_t0 = create_link();
	if(link_t0 == NULL)
	{
		printf("创建失败!");
		return -1;
	}

	printf("add_link_circle:");
	for(int i = 0; i < 20; i++ )
		add_link_circle(link_t0, i*10);
	print_link(link_t0);

	return 0;
}