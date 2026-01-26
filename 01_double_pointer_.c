/*
文件名：01_double_pointer.c
功能：二级指针+指针核心用法，区分二者差异
作者：Helen
日期：2026/1/21
*/
#include <stdio.h>
int main(){
    int a=10;
    int *p=&a;
    int **pp=&p;
    printf("===二级指针===\n");
    printf("a的值:%d\n",a);
    printf("*p(一级解引用):%d\n",*p);
    printf("**p(二级解引用):%d\n",**pp);
    printf("通过二级指针的修改a:");
    **pp=20;
    printf("%d\n\n",a);

    int b=200,c=300,d=400;
    int *p_arr[3]={&b,&c,&d};
    printf("===指针数组===\n");
    for(int i=0;i<3;i++){
        printf("p_arr[%d]指向的值:%d\n",i,*p_arr[i]);
    }
    char *str_arr[3]={"Java","C","Python"};
    printf("\n===指针数组存字符串===\n");
    for(int i=0;i<3;i++){
        printf("str_arr[%d]:%s\n",i,str_arr[i]);
    }
    return 0;

}