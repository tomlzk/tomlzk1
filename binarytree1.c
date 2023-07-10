#include<stdio.h>
#include"binarytree1.h"
#include<stdlib.h>
int main()
{
    position T = NULL;
    T = insert(6, T);
    insert(3, T);
    insert(2, T);
    insert(1, T);
    print(T);
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
    }
    else if(number < T->number)
    {
        T->left = insert(number, T->left);
    }
    else if(number > T->number)
    {
        T->right = insert(number, T->right);
    }
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