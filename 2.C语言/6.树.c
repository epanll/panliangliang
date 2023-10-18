#include <stdio.h>
#include <stdlib.h>

//树

typedef struct node{
    int data;   //存放编号
    struct node *lchild;    //左子树
    struct node *rchild;    //右子树
}tree_t;

//创建
tree_t *create_tree(int num)
{
    //限制树节点的个数
    if(num > 10)
    {
        return NULL;
    }

    //申请空间
    tree_t *root = malloc(sizeof(tree_t));
    if(root == NULL)
    {
        printf("节点空间申请失败!\n");
        return NULL;
    }

	//存入数据
	root->data = num;

    //左子树申请
    root->lchild = create_tree(num*2);

    //右子树申请
    root->rchild = create_tree(num*2 + 1);

    return root;
}

//先序遍历
void pre_tree(tree_t *root)
{
    if(root == NULL)
    {
        return;
    }

    printf(" %-3d ", root->data);

    pre_tree(root->lchild);

    pre_tree(root->rchild);

}

//中序遍历
void mid_tree(tree_t *root)
{
    if(root == NULL)
    {
        return;
    }

    mid_tree(root->lchild);
    
    printf(" %-3d ", root->data);

    mid_tree(root->rchild);
}

//后续遍历
void post_tree(tree_t *root)
{
	if(root == NULL)
    {
        return;
    }

    post_tree(root->lchild);

    post_tree(root->rchild);

    printf(" %-3d ", root->data);
}

//层次遍历
void level_tree(tree_t *root)
{
    //创建临时顺序队列(尾入头出)
    tree_t *queue[20];
    int head = 0;
    int tail = 0;

    tree_t *temp; 
    
    //(尾入)存入数据
    queue[tail++] = root;

    while(head != tail)
    {
        //头出
        temp = queue[head++];

        printf(" %-3d ", temp->data);

        //判断出队节点是否存在左子树,有,入队
        if(temp->lchild != NULL)
        {
            queue[tail++] = temp->lchild;
        }

        //判断出队节点是否存在右子树,有,入队
        if(temp->rchild != NULL)
        {
            queue[tail++] = temp->rchild;
        }

    }

    printf("\n");

    return;

}

//销毁函数
void dis_tree(tree_t *root)
{
	if (root == NULL)
	{
		return;
	}

	free(root->lchild);
	free(root->rchild);
	free(root);
}

int main()
{
    printf("tree:\n\n");

    printf("1.create_tree: ");
    tree_t *root = create_tree(1);
    if(root == NULL)
        printf("创建失败\n");
    printf("\n");

    printf("2.pre_tree: ");
    pre_tree(root);
    printf("\n");

    printf("3.mid_tree: ");
    mid_tree(root);
    printf("\n");

    printf("4.post_tree: ");
    post_tree(root);
    printf("\n");

    printf("5.level_tree: ");
    level_tree(root);
 
	printf("6.dis_tree: ");
	dis_tree(root);
	printf("\n");

    return 0;
}



























































