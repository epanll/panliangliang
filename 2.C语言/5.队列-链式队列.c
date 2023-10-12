#include <stdio.h>
#include <stdlib.h>

//链式队列

typedef struct node {
    int data;   //数据
    struct node *next;  //数据链
}node_t;

typedef struct queue{
    node_t * head;  //队列头指针 
    node_t * tail;  //队列尾指针
}link_queue_t;

//创建
link_queue_t * create_link_queue()
{
    //队列申请头结点
    node_t *head = malloc(sizeof(node_t));
    if(head == NULL)
    {
        printf("队列头结点申请失败!\n");
        return NULL;
    }

    //头结点初始化
    head->next = NULL;

    //队列头尾标志空间申请
    link_queue_t *link_queue = malloc(sizeof(link_queue_t));
    if(link_queue == NULL)
    {
        printf("标志空间申请失败!\n");
        return NULL;
    }

    //初始化头尾指针
    link_queue->head = head;
    link_queue->tail = head;

    return link_queue;
}

//判空
int is_null(link_queue_t *link_queue)
{
    return link_queue->head == link_queue->tail;
}

//入队(尾入,利用尾指针增加)
void in_link_queue(link_queue_t * link_queue, int data)
{
    //新节点申请空间
    node_t *newnode = malloc(sizeof(node_t));
    if(newnode == NULL)
    {
        printf("新节点空间申请失败!");
        return;
    }

    //存入数据
    newnode->data = data;

    //插入新节点
    newnode->next = link_queue->tail->next;
    link_queue->tail->next = newnode;

    //修改尾节点指向
    link_queue->tail = newnode;
}

//出队(头出,获取出队数据)
void out_link_queue(link_queue_t *link_queue, int *out_data)
{
    if(is_null(link_queue))
    {
        printf("队列为空,无法执行出队操作!\n");
        return;
    }

    node_t *temp = link_queue->head->next;

    //获取数据
    *out_data = temp->data;

    //出队
    link_queue->head->next = temp->next;
    free(temp);

    //如果队列为空要找回尾指针的指向,因为最后一个数的空间被释放了
    if(link_queue->head->next == NULL)
    {
        link_queue->tail = link_queue->head;
    }
}

//打印
void print_link_queue(link_queue_t *link_queue)
{
    if(is_null(link_queue))
    {
        printf("队列为空,无法执行打印操作!\n");
        return;
    }

    node_t * head = link_queue->head;

    //跳过头结点
    head = head->next;
    printf(" 队头-> ");
    while(head != NULL)
    {
        printf(" %-3d ", head->data);
        head = head->next;
    }
    printf(" ->队尾\n");

}

//获取队列长度
void get_len_link_queue(link_queue_t *link_queue, int *len_queue)
{
    if(is_null(link_queue))
    {
        printf("队列为空,队列长度为0!\n");
        return;
    }

    node_t * head = link_queue->head;

    *len_queue = 0;
    //跳过头结点
    head = head->next;
    while(head != NULL)
    {
        (*len_queue) ++;    //一定要记住 ++ 的优先级比 指针*的 高
        //printf(">>>%d \n", *len_queue);
        head = head->next;
    }
    
}

//清空
void clean_link_queue(link_queue_t *link_queue)
{
    int out_data;
    while(!is_null(link_queue))
    {
		out_link_queue(link_queue, &out_data);
    }
}

//销毁
void dis_link_queue(link_queue_t *link_queue)
{
    clean_link_queue(link_queue);

    //先释放头结点空间,再释放头尾指针操作空间
    free(link_queue->head);
    free(link_queue);
}


int main()
{
    printf("link_queue:\n\n");

    printf("1.create_link_queue:\n");
    link_queue_t * link_queue = create_link_queue();
    if(link_queue == NULL)
    {
        printf("创建失败\n");
        return -1;
    }

    printf("2.in_link_queue:");
    for(int i = 0; i < 10; i++)
        in_link_queue(link_queue, i*10);
    print_link_queue(link_queue);

    printf("3.out_link_queue:\n");
    int out_data;
    for(int i = 0; i < 3; i++)
    {
        out_link_queue(link_queue, &out_data);
        printf("-> %d \n", out_data);
    }
    print_link_queue(link_queue);

    printf("4.get_len_link_queue:");
    int len_queue;
    get_len_link_queue(link_queue, &len_queue);
    printf(" %d \n", len_queue);

    printf("5.clean_link_queue:");
    clean_link_queue(link_queue);
    print_link_queue(link_queue);

    printf("6.dis_link_queue:");
    dis_link_queue(link_queue);

    return 0;
}