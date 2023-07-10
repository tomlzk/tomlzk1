#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int * array , int left, int mid, int right);
void mergesort(int * array, int left, int right);

int main()
{
    int num = 10;
    int array[num];
    srand((unsigned int) time(NULL));
    for(int i = 0; i < num; i++)
    {
        array[i] = rand() % 100;
        printf("%d\n", array[i]);
    }
    printf("\n");

    mergesort(array, 0, num);

    for(int i = 0; i < num; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}

void mergesort(int * array, int left, int right)
{
    if(right - left <= 1)
    {
        return;
    }

    int mid = (left + right) / 2;
    mergesort(array, left, mid);
    mergesort(array, mid, right);
    merge(array, left, mid, right);
}

void merge(int * array, int left, int mid, int right)
{
    int index = 0;
    int i = left;
    int j = mid;
    int * temp = (int *)malloc(sizeof(int)*(right - left + 1));
    while(i < mid && j < right)
    {
        if(array[i] < array[j])
        {
            temp[index] = array[i];
            index++;
            i++;
        }
        else
        {
            temp[index] = array[j];
            index++;
            j++;
        }
    }

    while(i < mid)
    {
        temp[index] = array[i];
        index++;
        i++;
    }
    while(j < right)
    {
        temp[index] = array[j];
        index++;
        j++;
    }

    for(i = 0; left < right; i++)
    {
        array[left] = temp[i];
        left++;
    }
    free(temp);
}