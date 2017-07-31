#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode* lchild, * rchild;
}BiTreeNode;

/**创建二叉树结点**/
BiTreeNode* CreatBiTreeNode(char x)
{
    BiTreeNode* node = (BiTreeNode* )malloc(sizeof(BiTreeNode));
    node->data = x;
    node->lchild = node->rchild = NULL;
    return node;
}

/**创建二叉树(先序输入)**/
BiTreeNode* CreatBiTree()
{
    char x;
    BiTreeNode* root;
    scanf("%c", &x);
    getchar();
    if (x == '0')
        root = NULL;
    else
    {
        root = (BiTreeNode* )malloc(sizeof(BiTreeNode));
        root->data = x;
        root->lchild = CreatBiTree();
        root->rchild = CreatBiTree();
    }
    return root;
}

/**在指定结点左孩子处插入新结点**/
void Insert_lBt(BiTreeNode* parent, char x)
{
    BiTreeNode* ptr = CreatBiTreeNode(x);
    if (ptr->lchild)
    {
        ptr->lchild = parent->lchild;
        parent->lchild = ptr;
    }
    else
        parent->lchild = ptr;
}

/**在指定结点右孩子处插入新结点**/
void Insert_rBt(BiTreeNode* parent, char x)
{
    BiTreeNode* ptr = CreatBiTreeNode(x);
    if (ptr->rchild)
    {
        ptr->rchild = parent->rchild;
        parent->rchild = ptr;
    }
    else
        parent->rchild = ptr;
}

/**先序遍历非递归**/
void Pre_Bt(BiTreeNode* Bt)
{
    int Ss_top = 0;
    BiTreeNode* ptr = Bt;
    BiTreeNode* Ss[1000];
    while (Ss_top >= 0)
    {
        while (ptr)
        {
            printf("%c ", ptr->data);
            if (ptr->rchild)
                Ss[Ss_top++] = ptr->rchild;
            ptr = ptr->lchild;
        }
        if (Ss_top-- > 0)
            ptr = Ss[Ss_top];
    }
    printf("\n");
}

/**先序遍历递归**/
void Pre_BtRec(BiTreeNode* Bt)
{
    if(Bt)
    {
        printf("%c",Bt->data);
        Pre_BtRec(Bt->lchild);
        Pre_BtRec(Bt->rchild);
    }
}

/**中序遍历非递归**/
void In_Bt(BiTreeNode* Bt)
{
    int Ss_top = 0;
    BiTreeNode* ptr = Bt;
    BiTreeNode* Ss[1000];
    while (Ss_top >= 0)
    {
        while (ptr)
        {
            Ss[Ss_top++] = ptr;
            ptr = ptr->lchild;
        }
        if (Ss_top-- > 0)
        {
            ptr = Ss[Ss_top];
            printf("%c", ptr->data);
            ptr = ptr->rchild;
        }
    }
    printf("\n");
}

/**中序遍历递归**/
void In_BtRec(BiTreeNode* Bt)
{
    if(Bt)
    {
        In_BtRec(Bt->lchild);
        printf("%c",Bt->data);
        In_BtRec(Bt->rchild);
    }
}

/**后序遍历非递归**/
void Post_Bt(BiTreeNode* Bt)
{
    int Ss1_top = 0, Ss2_top = 0, Ss2[1000], flag;
    BiTreeNode* ptr = Bt;
    BiTreeNode* Ss1[1000];
    while (Ss1_top >= 0)
    {
        while (ptr)
        {
            Ss1[Ss1_top++] = ptr;
            Ss2[Ss2_top++] = 0;
            ptr = ptr->lchild;
        }
        if (Ss1_top-- > 0)
        {
            flag = Ss2[--Ss2_top];
            ptr = Ss1[Ss1_top];
            if (!flag)
            {
                Ss1[Ss1_top++] = ptr;
                Ss2[Ss2_top++] = 1;
                ptr = ptr->rchild;
            }
            else
            {
                printf("%c", ptr->data);
                ptr = NULL;
            }
        }
    }
    printf("\n");
}

/**中序遍历递归**/
void Post_BtRec(BiTreeNode* Bt)
{
    if(Bt)
    {
        Post_BtRec(Bt->lchild);
        Post_BtRec(Bt->rchild);
        printf("%c",Bt->data);
    }
}

/**根据二叉树先序和中序遍历生成二叉树**/
BiTreeNode* CreatBTFromPreIn(char* Pre, char* In, int len)
{
    BiTreeNode* root = (BiTreeNode* )malloc(sizeof(BiTreeNode));
    if (len <= 0)
    {
        root = NULL;
        return root;
    }
    root = CreatBiTreeNode(*Pre);
    int i;
    for (i = 0; i < len; ++i)
        if (*Pre == *(In+i))
            break;
    root->lchild = CreatBTFromPreIn(Pre+1, In, i);
    root->rchild = CreatBTFromPreIn(Pre+1+i, In+i+1, len-i-1);
    return root;
}

int main()
{
    char Pre[1000], In[1000];
    scanf("%s%s", Pre, In);
    BiTreeNode* root = (BiTreeNode* )malloc(sizeof(BiTreeNode));
    root = CreatBTFromPreIn(Pre, In, strlen(Pre));
    Post_Bt(root);
    return 0;
}