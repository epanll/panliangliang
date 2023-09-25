#include <stdio.h>
#include <stdlib.h>

typedef struct link_node{
    int data;           //数据
    struct link_node *next;  //指向下一个节点的指针
}link_t;

//创建链表
link_t * create_link()
{
    link_t *head = (link_t *)malloc(sizeof(link_t));
    if(head == NULL)
    {
        printf("创建失败!\n");
        return NULL;
    }

    head->next = NULL;

    return head;
}

//判空
int Is_Null(link_t *head)
{
    return head->next == NULL;
}

//头增
int add_front_link(link_t *head, int data)
{
    link_t *newnode = (link_t *)malloc(sizeof(link_t));
    if(newnode == NULL)
    {
        printf("节点创建失败!\n");
        return -1;
    }

    //先存入数据
	newnode->data = data;

    //先操作新节点,再操作head
	newnode->next = head->next;
    head->next = newnode;

    return 0;
}

//头删
int del_front_link(link_t *head)
{
	//判空
	if (Is_Null(head))
	{
		printf("链表为空,无法执行删除操作!\n");
		return -1;
	}

	link_t *temp;

	temp = head->next;
	head->next = temp->next;

	free(temp);

	return 0;
}

//打印
void print_link(link_t *head)
{
    //判空
    if(Is_Null(head))
    {
        printf("链表为空,无法打印!\n");
        return;
    }

    head = head->next;      //跳过头结点
    while(head != NULL)
    {
        printf(" %d ", head->data);
        head = head->next;
    }

    printf("\n");

    return;
}

//清空链表,将所有的数据删完
int clean_link(link_t *head)
{
    while(!Is_Null(head))
    {
        del_front_link(head);
    }

    return 0;
}

//销毁链表
int dis_link(link_t *head)
{
    //先清空链表
    clean_link(head);

    free(head);

    return 0;
}

//单向链表逆向输出
int reverse_link_1(link_t *head)
{
	//思路创建一个新的临时链表,保存原链表的数据,再将新链表的数据打印输出
	link_t * temp = create_link();
	if (temp == NULL)
	{	
		printf("创建失败");
		return -1;
	}

	head = head->next;
	while (head != NULL)
	{
		add_front_link(temp, head->data);
		head = head->next;
	}

	print_link(temp);

	dis_link(temp);

	return 0;
}

//单向链表逆向输出
int reverse_link_2(link_t *head)
{
	//链表打印结果是一个先进后出,与堆栈的效果类似,可以尝试递归实现
	if (head->next == NULL)
	{
		return 0;
	}

	//重复调用自己
	reverse_link_2(head->next);

	printf(" %d ", head->next->data);
}

int main()
{
    //创建
    link_t *link_t0 = create_link();
    if(link_t0 == NULL)
    {
        return -1;
    }

    //头增
    printf("add_front:");
    for(int i = 0; i < 20; i++)
        add_front_link(link_t0, i*10);
    print_link(link_t0);

	printf("reverse_link_1:");
	reverse_link_1(link_t0);

	printf("reverse_link_2:");
	reverse_link_2(link_t0);
	printf("\n");

    //清除链表
    printf("clean_link:\n");
    clean_link(link_t0);

    //销毁链表
    printf("dis_link:");
    dis_link(link_t0);

    return 0;
}