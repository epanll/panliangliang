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
    link_t *temp = (link_t *)malloc(sizeof(link_t));
    if(temp == NULL)
    {
        printf("节点创建失败!\n");
        return -1;
    }

    //先存入数据
    temp->data = data;

    //先操作新节点,再操作head
    temp->next = head->next;
    head->next = temp;

    return 0;
}

//指定位置增加数据
int add_index_link(link_t *head, int index, int data)
{
    if(index < 0)
    {
        printf("无法插入该位置的数据!\n");
        return -1;
    }

    while(index--)
    {
        head = head->next;
        if(head == NULL)
        {
            printf("位置过大,超出链表范围!\n");
            return -1;
        }
    }

    add_front_link(head, data);

    return 0;
}

//头删
int del_front_link(link_t *head)
{
    //判空
    if(Is_Null(head))
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

//指定位置删除
int del_index_link(link_t *head, int index)
{
    //判空
    if(Is_Null(head))
    {
        printf("链表为空,无法执行删除操作!\n");
        return -1;
    }

    while(index--)
    {
        head = head->next;
        if(head == NULL)			
        {
            printf("位置过大,超出链表范围!\n");
            return -1;
        }
    }

    del_front_link(head);

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

//指定位置修改数据
int change_index_link(link_t *head, int index, int data)
{
    //判空
    if(Is_Null(head) || index < 0)
    {
        printf("链表为空,无法打印!\n");
        return -1;
    }

    while(index--)
    {
		head = head->next;
        if(head == NULL)
        {
            printf("超出链表范围,无法修改!\n");
            return -1;
        }
    }

    head->data = data;

    return 0;
}

//查找数据
int search_link(link_t *head, int data)
{
    int index = 0;
	
    head = head->next;	//跳过头结点
    while(head != NULL)
    {
        index ++;
        if(head->data == data)
        {
            printf("%d is located in spacce : %d \n", data, index);
            return 0;
        }
        head = head->next;
    }

    printf("没有查到该数据!");

    return 0;
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

int main()
{
    printf("link_t:\n");

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

    //指定位置增加
    printf("add_index:");
    add_index_link(link_t0, 5, 555);
    print_link(link_t0);

    //头删
    printf("del_front:");
    for(int i = 0; i < 10; i++)
        del_front_link(link_t0);
    print_link(link_t0);

    //指定位置删除
    printf("del_index:");
    del_index_link(link_t0, 5);
    print_link(link_t0);

    //指定位置修改数据
    printf("chg_index:");
    change_index_link(link_t0, 2, 22);
    print_link(link_t0);

    //查找数据,并返回数据的位置
    printf("search_link:");
    search_link(link_t0, 22);
    //print_link(link_t0);

    //清除链表
    printf("clean_link:");
    clean_link(link_t0);
    print_link(link_t0);

    //销毁链表
    printf("dis_link:");
    dis_link(link_t0);
    //print_link(link_t0);

    return 0;
}