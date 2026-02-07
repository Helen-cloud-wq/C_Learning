/*
文件名；01_string_pointer.c
功能；指针操作字符串核心用法，区分char*和char[]
作者；Helen
日期；2026/1/25
*/
#include <stdio.h>
int main(){

    char str_arr[]="hello C";
    printf("===char[]字符数组===\n");
    printf("原始字符串；%s\n",str_arr);
    char *p_arr=str_arr;
    *p_arr='H';
    *(p_arr+6)='c';
    printf("修改后字符串；%s\n",str_arr);

    char *str_ptr="hello C";
    printf("\n===char*字符指针===\n");
    printf("字符串(内容；%s\n",str_ptr);
    char *p_ptr=str_ptr;
    printf("遍历字符串（指针）；");
    while(*p_ptr!='\0'){
        printf("%c",*p_ptr);
        p_ptr++;
    }
    printf("\n");
    //模拟strlen
    int len=0;
    char *p_len=str_arr;
    while(*p_len!='\0'){
        len++;
        p_len++;
    }
    printf("\n字符串长度(不含\\0):%d\n",len);
    return 0;
}