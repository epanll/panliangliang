#include <stdio.h>
#include <stdlib.h>

//顺序栈

typedef struct stack_order{
    int *data;  //数据域
    int size;   //栈空间大小
    int top;    //标记栈顶位置
}stack_t;

//创建
stack_t *create_stack(int size)
{
    //申请栈标志空间
    stack_t *stack = malloc(sizeof(stack_t));
    if(stack == NULL)
    {
        printf("栈标志空间申请失败!\n");
        return NULL;
    }

    //申请栈区数据空间
    stack->data = malloc(sizeof(int)*size);
    if(stack->data == NULL)
    {
        printf("数据空间申请失败\n");
        return NULL;
    }

    //初始化size和top
    stack->size = size;
    stack->top = -1;

    return stack;
}

//判空
int is_null(stack_t * stack)
{
    return stack->top == -1;
}

//判满
int is_full(stack_t * stack)
{
    return stack->top == stack->size - 1;
}

//入栈
int push_stack(stack_t * stack, int push_data)
{
    if(is_full(stack))
    {
        printf("栈区已满,无法入栈\n");
        return -1;
    }

    stack->data[stack->top+1] = push_data;

    stack->top++;

    return 0;
}

//出栈
int pop_stack(stack_t * stack, int *pop_data)
{
    if(is_null(stack))
    {
        printf("栈为空,无法执行出栈操作\n");
        return -1;
    }

    *pop_data = stack->data[stack->top];

    stack->top--;

    return 0;
}

//获取栈顶数据
int get_top_stack(stack_t * stack, int *top_data)
{
    if(is_null(stack))
    {
        printf("栈为空,无法执行获取栈顶数据操作\n");
        return -1;
    }

    *top_data = stack->data[stack->top];

    return 0;
}

//打印
void print_stack(stack_t * stack)
{
    if(is_null(stack))
    {
        printf("栈为空无法打印\n");
        return;
    }

    printf(" 栈顶 ");
    for(int i = stack->top; i >= 0; i--)
        printf(" %-3d ", stack->data[i]);
    printf(" 栈底\n");

    return;
}

//清空
void clean_stack(stack_t * stack)
{
    stack->top = -1;
    return;
}

//销毁
void dis_stack(stack_t * stack)
{
    free(stack->data);
    free(stack);
    return;
}

int main()
{
	printf("stack_t:\n");

    printf("1.create_stack:\n");
    stack_t *stack_t0 = create_stack(10);
    if(stack_t0 == NULL)
    {
        printf("创建栈区失败\n");
        return -1;
    }

    printf("2.push_stack:\n");
    for(int i = 0; i < 10; i++)
        push_stack(stack_t0, i*10);
    print_stack(stack_t0);

    int pop_data;
    printf("3.pop_static:\n");
    for(int i = 0; i < 3; i++)
    {
        pop_stack(stack_t0, &pop_data);
        print_stack(stack_t0);
    }

    int top_data;
    printf("4.get_top_stack: ");
    get_top_stack(stack_t0, &top_data);
    printf(" top_data:%d \n", top_data);

    printf("5.clean_stack:");
    clean_stack(stack_t0);
    print_stack(stack_t0);

    printf("6.dis_stack:\n");
    dis_stack(stack_t0);

    return 0;
}