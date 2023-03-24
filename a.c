//
// Created by 39221 on 2023/3/16.
//
#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

/*
int main(){
    int j = 0;
    int* p = (int*)malloc(4);
    if(p == NULL)
    {
        //打印错误的原因
        printf("%s\n",strerror(errno));
    }
    else
    {
        //正常使用空间
        int i = 0;
        for(i = 0;i < 10;i++)
        {
            *(p + i) = i;
        }
        for(i = 0;i < 10;i++)
        {
            printf("%d ",*(p + i));
        }
    }
    printf("\n");
    realloc(p,4000);

    for(j = 10;j < 30;j++)
    {
        *(p + j) = j;
    }
    for(j = 0;j < 30;j++)
    {
        printf("%d ",*(p + j));
    }
    free(p);
    p = NULL;//
}*/

/*
char* Get(char* p)
{
    p = (char*)malloc(10);
    return p;
}

void Test(void){
    char* str = NULL;
    str = Get(str);
    strcpy(str,"hello,world");
    printf(str);
    free(str);
}

int main(){
    Test();
    return 0;
}*/

/*
struct s{
    int n;
    int arr[0];//未知大小的-柔性数组成员-数组的大小是可以调整的
};

int main(){
    struct s* ps = (struct s*)malloc(sizeof(struct s)+ 5*sizeof(int));
    ps->n = 100;
    printf("%d ",sizeof(struct s));

    int i = 0;
    for(i = 0;i < 5;i++){
        ps->arr[i] = i;
    }
    struct s* ptr = realloc(ps,44);
    if(ptr != NULL){
        ps = ptr;
    }
    for(i = 5;i < 10;i++){
        ps->arr[i] = i;
    }
    for(i = 0;i < 10;i++){
        printf("%d ",ps->arr[i]);
    }
    free(ps);
    ps = NULL;
    return 0;
}*/

struct c{
    int a;
    int* arr;
};

int main(){
    struct c* c = (struct c*)malloc(sizeof(struct c));
    c->arr = malloc(5 * sizeof(int));
    int i = 0;
    for(i = 0;i < 5;i++){
        c->arr[i] = i;
    }
    for(i = 0;i < 5;i++){
        printf("%d ",c->arr[i]);
    }
    printf("\n");
    //调整大小
    int* ptr = realloc(c->arr,10 * sizeof(int));
    if(ptr != NULL){
        c->arr = ptr;
    }
    for(i = 5;i < 10;i++){
        c->arr[i] = i;
    }
    for(i = 0;i < 10;i++){
        printf("%d ",c->arr[i]);
    }
    free(ptr);
    ptr = NULL;
    free(c);
    c = NULL;
    return 0;
}
