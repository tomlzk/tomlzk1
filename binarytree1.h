#ifndef _TREE_H_

struct TreeNode;
typedef struct TreeNode *position;
typedef struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
position Find(int number, SearchTree T);
position FindMin(SearchTree T);
position FindMax(SearchTree T);
position insert(int number, SearchTree T);
position Delete(int number, SearchTree T);
int Height(SearchTree T);
int Max(int a, int b);
static position SingleRotateWithLeft(SearchTree k2);
static position SingleRotateWithRight(SearchTree k2);
static position DoubleRotateWithLeft(SearchTree k3);
static position DoubleRotateWithRight(SearchTree k3);
position print(SearchTree T);

#endif

struct TreeNode
{
    int number;
    position left;
    position right;
    int height;
};
