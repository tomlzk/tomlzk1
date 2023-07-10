#include <time.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
    char *array = (char*) malloc(sizeof(char)*18);
    printf("请输入查询的卡号<长度为1~18>:");
    scanf("%s", array);
    printf("%s", array);
    FILE T;
    return 0;
}

