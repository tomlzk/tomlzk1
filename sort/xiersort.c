#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int m = 100;
    int array[m];
    for (int i = 0; i < m; i++)
    {
        array[i] = rand() % 100;
        printf("%d\n", array[i]);
    }
    printf("\n");

    int gap = m / 3 + 1;

    int i = 0;
    int j = 0;
    int k = 0;

    while (gap > 0)
    {
        for (i = 0; i < gap; i++)
        {
            for (j = i; j < m - gap; j = j + gap)
            {
                k = j;
                int temp = array[k + gap];
                while (k >= 0 && array[k] > temp)
                {
                    array[k + gap] = array[k];
                    k = k - gap;
                }
                array[k + gap] = temp;
            }
        }

        gap = gap / 2;
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}