#include <stdio.h>
#include <stdlib.h>

//链式栈:链表本身就拥有栈的性质

typedef struct node{
    int data;   //数据
    struct node *next;  //链
}linkstack_t;

//创建
linkstack_t * create_link_stack()
{
    //创建头结点
    linkstack_t *head = malloc(sizeof(linkstack_t));
    if(head == NULL)
    {
        printf("创建节点失败!\n");
        return NULL;
    }

    //初始化
    head->next = NULL;

    return head;
}

//判空
int is_null(linkstack_t *head)
{
    return head->next == NULL;
}

//入栈
void push_link_stack(linkstack_t *head, int data)
{
    linkstack_t *newnode = malloc(sizeof(linkstack_t));
    if(newnode == NULL)
    {
        printf("入栈节点申请失败\n");
        return;
    }

    //存入数据
    newnode->data = data;

    newnode->next = head->next; //先操作新节点
    head->next = newnode;   //后操作头结点

}

//出栈
void pop_link_stack(linkstack_t *head, int *pop_data)
{
    if(is_null(head))
    {
        printf("栈为空,无法执行出栈操作\n");
        return;
    }

    linkstack_t *temp = head->next;

    //获取出栈数据
    *pop_data = temp->data;

    head->next = temp->next;

    free(temp);
}

//获取栈顶数据
void get_top_data(linkstack_t *head, int *top_data)
{
    if(is_null(head))
    {
        printf("栈为空,无法执行获取栈顶数据操作\n");
        return;
    }

    *top_data = head->next->data;

}

//打印
void print_link_stack(linkstack_t *head)
{
    if(is_null(head))
    {
        printf("栈为空,无法执行打印操作\n");
        return;
    }

    printf(" 栈顶 ");
    head = head->next;  //跳过头结点
    while(head != NULL)
    {
        printf(" %-3d ", head->data);
        head = head->next;
    }
    printf("栈底\n");
}

//清空
void clean_link_stack(linkstack_t *head)
{
    if(is_null(head))
    {
        return;
    }

    int pop_data;
    while(head->next != NULL)
    {
        pop_link_stack(head, &pop_data);
    }
}

//销毁
void dis_link_stack(linkstack_t *head)
{
    clean_link_stack(head);
    free(head);
}

int main()
{
    printf("link_stack:\n");

    printf("1.create_link_stack:\n");
    linkstack_t *linkstack = create_link_stack();
    if(linkstack == NULL)
    {
        printf("创建链表失败!\n");
        return -1;
    }

    printf("2.push_link_stack:");
    for(int i = 0; i < 10; i++)
        push_link_stack(linkstack, i*10);
    print_link_stack(linkstack);

    printf("3.pop_link_stack:");
    int pop_data;
    for(int i = 0; i < 3; i++)
    {
        pop_link_stack(linkstack, &pop_data);
        printf(" %d ", pop_data);
    }
    printf("\n");
    print_link_stack(linkstack);

    printf("4.get_top_data:");
    int top_data;
    get_top_data(linkstack, &top_data);
    printf("%d \n", top_data);

    printf("5.clean_link_stack:");
    clean_link_stack(linkstack);
    print_link_stack(linkstack);

    printf("6.dis_link_stack:\n");
    dis_link_stack(linkstack);

    return 0;
}