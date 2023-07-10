#include<stdio.h>
#include"binarytree1.h"
#include<stdlib.h>
int main()
{
    position T = NULL;
    T = insert(6, T);
    print(T);
    printf("\n");
    T = insert(3, T);
    print(T);
    printf("\n");
    T = insert(2, T);
    print(T);
    printf("\n");
    T = insert(1, T);
    print(T);
    printf("\n");
    MakeEmpty(T);
    
    return 0;
}

//制作空表
SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

position Find(int number, SearchTree T)
{
    if(T == NULL)
    {
        return NULL;
    }
    if(number < T->number)
    {
        return Find(number, T->left);
    }
    else if (number > T->number)
    {
        return Find(number, T->right);
    }
    else
    {
        return T;
    }
}
position FindMin(SearchTree T)
{
    if(T == NULL)
    {
        return NULL;
    }
    else if(T->left == NULL)
    {
        return T;
    }
    else
    {
        return FindMin(T->left);
    }
}

position FindMax(SearchTree T)
{
    if(T == NULL)
    {
        return NULL;
    }
    else if(T->right == NULL)
    {
        return T;
    }
    else
    {
        return FindMax(T-> right);
    }
}

position insert(int number, SearchTree T)
{
    if(T == NULL)
    {
        T = (position)malloc(sizeof(struct TreeNode));
        T->number = number;
        T->left = NULL;
        T->right = NULL;
        T->height = 0;
    }
    else if(number < T->number)
    {
        T->left = insert(number, T->left);
        if(Height(T->left) - Height(T->right) == 2)
            if(number < T->left->number)
            {
                T = SingleRotateWithLeft(T);
            }
            else
            {
                T = DoubleRotateWithLeft(T);
            }
    }
    else if(number > T->number)
    {
        T->right = insert(number, T->right);
        if(Height(T->right) - Height(T->left) == 2)
            if(number > T->right->number)
            {
                T = SingleRotateWithRight(T);
            }
            else
            {
                T = DoubleRotateWithRight(T);
            }
    }
    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}

position Delete(int number, SearchTree T)
{
    position TmpCell;
    if(T == NULL)
    {
        perror("no find number");
    }
    else if(number < T->number)
    {
        T->left = Delete(number, T->left);
    }
    else if(number > T->number)
    {
        T->right = Delete(number, T->right);
    }
    else if(T->right && T->left)
    {
        TmpCell = FindMin(T->right);
        T->number = TmpCell->number;
        T->right = Delete(T->number, T->right);
    }
    else
    {
        TmpCell = T;
        if(T->left == NULL)
        {
            T = T->right;
        }
        else if(T->right == NULL)
        {
            T = T->right;
        }
    }
    return T;
}

int Height(SearchTree T)
{
    if(T == NULL)
    {
        return -1;
    }
    else
    {
        return T->height;
    }
}

int Max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

static position SingleRotateWithLeft(SearchTree k2)
{
    position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    return k1;
}

static position SingleRotateWithRight(SearchTree k2)
{
    position k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    return k1;
}

static position DoubleRotateWithLeft(SearchTree k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}


static position DoubleRotateWithRight(SearchTree k3)
{
    k3->right = SingleRotateWithLeft(k3->right);
    return SingleRotateWithRight(k3);
}

position print(position T)
{
    if(T == NULL)
    {
        return NULL;
    }
    if(T->left)
    {
        print(T->left);
    }

    printf("%d\n", T->number);

    if(T->right)
    {
        print(T->right);
    }
}