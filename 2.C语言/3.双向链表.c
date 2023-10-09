#include <stdio.h>

typedef struct node{
    int data;
    struct node *front;     
    struct node *next;
}dblink_t;

//创建
dblink_t *create_dblink()
{
    //申请头结点
    dblink_t *head = (dblink_t *)malloc(sizeof(dblink_t));
    if(head == NULL)
    {
        printf("头结点申请失败!\n");
        return NULL;
    }

    //申请尾节点
    dblink_t *tail = (dblink_t *)malloc(sizeof(dblink_t));
    if(tail == NULL)
    {
        printf("尾结点申请失败!\n");
        return NULL;
    }

    //初始化
    head->next = tail;
    head->front = NULL;

    tail->next = NULL;
    tail->front = head;

    return head;

}

//判空
int is_null(dblink_t * head)
{
    return head->next->next == NULL;
}

//头增
void add_front_dblink(dblink_t * head, int data)
{
    //申请新节点
    dblink_t *newnode = (dblink_t *)malloc(sizeof(dblink_t));
    if(newnode == NULL)
    {
        printf("新结点申请失败!\n");
        return;
    }

    //存入数据
    newnode->data = data;

    //加入链表,先操作新节点
    newnode->front = head;
    newnode->next = head->next;

    head->next->front = newnode;    //插入一个新的节点,有三个节点需要修改关系(或者4条链条需要动)
    head->next = newnode;
    
    return;
} 

//头删
void del_front_dblink(dblink_t * head)
{
    if(is_null(head))
    {
        printf("表为空,无法执行删除操作");
        return;
    }

    //临时节点
    dblink_t *temp = head->next;

    head->next = temp->next;
    temp->next->front = head;

    free(temp);

}

//打印
void print_dblink(dblink_t * head)
{
    if(is_null(head))
    {
        printf("链表为空,无法执行打印操作!\n");
        return;
    }

    //正向打印
    printf("正向:");
    while(head->next->next != NULL)
    {
        head = head->next;
        printf(" %-3d ", head->data);
    }
    printf("\n");

    //反向打印
    printf("反向:");
    while(head->front != NULL)
    {
        printf(" %-3d ", head->data);
        head = head->front;
    }
    printf("\n");

} 

//指定位置修改
void change_dblink(dblink_t * head, int index, int data)
{
    if(is_null(head) || index < 0)
    {
        printf("表为空或位置过小,无法执行修改操作\n");
        return;
    }

    while(index--)
    {
        head = head->next; 
		if(head->next->next == NULL)
		{
			printf("修改数据，指定位置过大!\n");
			return;
		}
    }

    head->data = data;

    return;
}

//查找
void search_dblink(dblink_t * head, int data)
{
    if(is_null(head))
    {
        printf("链表为空,无法执行查找操作!\n");
        return;
    }

    int temp = 0;
    while(head->next->next != NULL)
    {
        head = head->next;
        temp ++;
        if(head->data == data)
        {
            printf("%d is located in space %d \n", data, temp);
            return;
        }
    }

    printf("%d 不存在该链表中!\n", data);
    return;
}

//清空
void clean_dblink(dblink_t * head)
{
    while(head->next->next != NULL)
    {
        del_front_dblink(head);
    }
}

//销毁
void dis_dblink(dblink_t * head)
{
    clean_dblink(head);
    free(head->next);
    free(head);
}

int main()
{
    printf("dblink:\n");

    //创建
    printf("create_dblink:\n");
    dblink_t * dblink_t0 = create_dblink();
    if(dblink_t0 == NULL)
    {
        printf("创建失败\n");
        return -1;
    }

    //头增
    printf("add_front:\n");
    for(int i = 0; i < 20; i++)
    add_front_dblink(dblink_t0, i*10);
    print_dblink(dblink_t0);

    //头删
    printf("del_front:\n");
    for(int i = 0; i < 10; i++)
    del_front_dblink(dblink_t0);
    print_dblink(dblink_t0);

    //指定位置修改
    printf("change_dblink:\n");
    change_dblink(dblink_t0, 6, 666);
    print_dblink(dblink_t0);

    //查找数据
    printf("search_dblink:\n");
    search_dblink(dblink_t0, 666);
    search_dblink(dblink_t0, 777);

    //清空链表
    printf("clean_dblink:\n");
    clean_dblink(dblink_t0);
    print_dblink(dblink_t0);

    //销毁链表
    dis_dblink(dblink_t0);
    
    return 0;
}


























































