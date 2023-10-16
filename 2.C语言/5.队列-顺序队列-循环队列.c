#include <stdio.h>
#include <stdlib.h>

//顺序队列:顺序队列会造成空间的浪费,前面数据出队后,要想保证队列数据空间的不浪费
//必须将后面的数据全部向前移动,造成的时间浪费是不可容忍的,因此采用循环队列实现
//双下标操作,head指向要出队数据的位置,tail指向要入队数据的位置

//难点在于:队列如何判空 判满

//使用不完全填满数组的技巧解决

typedef struct queue
{
    int * data;     //队列数据空间
    int size;       //数组大小
    int head;       //出队数据 下标
    int tail;       //入队数据 下标
}queue_t;

//创建
queue_t *create_queue(int size)
{
    //申请队列标识空间
    queue_t *queue = malloc(sizeof(queue_t));
    if(queue == NULL)
    {
        printf("队列标识符空间申请失败\n");
        return NULL;
    }

    //申请数据存储空间,注意是size + 1,不完全填满数组
    queue->data = malloc((size + 1) * sizeof(int));
    if(queue->data == NULL)
    {
        printf("数据存储空间申请失败\n");
        return NULL;
    }

    //初始化
    queue->size = size + 1;
    queue->head = 1;
    queue->tail = 0;

    return queue;
}

//判满
int is_full(queue_t *queue)
{
    return (queue->tail + 2) % queue->size == queue->head;
}

//判空
int is_null(queue_t *queue)
{
    return (queue->tail + 1)% queue->size == queue->head;
}

//入队
void in_queue(queue_t *queue, int data)
{
    //判满
    if(is_full(queue)) 
    {
        printf("队列已满,数据: %d 无法执行入队操作\n", data);
        return;
    }

    //修改tail
    queue->tail = (queue->tail + 1) % queue->size;

    //数据入队
    queue->data[queue->tail] = data;

    return;
}

//出队
void out_queue(queue_t *queue, int *out_queue_data)
{
    //判空
    if(is_null(queue))
    {
        printf("队列为空,数据无法执行出队操作");
        return;
    }

    *out_queue_data = queue->data[queue->head];

    queue->head = (queue->head + 1) % queue->size;

    return;
}

//打印
void print_queue(queue_t *queue)
{
    //判空
    if(is_null(queue))
    {
        printf("队列为空,无法执行打印操作\n");
        return;
    }

    printf(" queue->head:%d \n", queue->head);
    printf(" queue->tail:%d \n", queue->tail);

    printf(" 队头:");
    if(queue->head < queue->tail)
    {
        for(int i = queue->head; i <= queue->tail; i ++)
            printf("% -3d ", queue->data[i]);
    }
    else                    //打印这块暂时想不出来更好的方法
    {
        for(int i = queue->head; i < queue->size; i ++)
            printf("% -3d ", queue->data[i]);
        
        for(int i = 0; i <= queue->tail; i ++)
            printf("% -3d ", queue->data[i]);
    }
    printf(" 队尾\n");

    return;
}

//获取队列长度
void get_len_queue(queue_t *queue, int *len_queue)
{
    //判空
    if(is_null(queue))
    {
        printf("队列为空,len = 0\n");
        return;
    }

    *len_queue = (queue->tail + queue->size + 1 - queue->head) % queue->size;

    return;
}

//清空
void clean_queue(queue_t *queue)
{
    int out_data;
    while(!is_null(queue))
    {
        out_queue(queue, &out_data);
    }
}

//销毁
void dis_queue(queue_t *queue)
{
    clean_queue(queue);

    free(queue->data);
    free(queue);

}

int main()
{
	printf("Circular_queue:\r\n\n");

	printf("1.create_queue:\n\n");
	queue_t *queue = create_queue(10);
	if(queue == NULL)
    {
        printf("创建队列失败\n");
        return -1;
    }

    printf("2.in_queue:");
    for(int i = 0; i < 11; i++)
    {
        in_queue(queue, i*10);
    }
    print_queue(queue);
    printf("\n");

    printf("3.out_queue: ");
    int out_queue_data;
    for(int i = 0; i < 3; i++)
    {
        out_queue(queue, &out_queue_data);
        printf(" %d ", out_queue_data);
    }
    printf("\n");
    print_queue(queue);
    printf("\n");
    
#if 0  //测试超出size后的数据插入情况
    in_queue(queue, 0);
    print_queue(queue);
    in_queue(queue, 1);
    print_queue(queue);
    in_queue(queue, 2);
    print_queue(queue);
    in_queue(queue, 3);
    print_queue(queue);
#endif

    printf("4.get_len_queue: ");
    int len_queue;
    get_len_queue(queue, &len_queue);
    printf("%d \n\n", len_queue);

    printf("5.clean_queue:\n");
    clean_queue(queue);
    print_queue(queue);
    printf("\n");

    printf("6.dis_queue:\n");
    dis_queue(queue);

    return 0;
}