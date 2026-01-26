/*
文件名：03_pointer_func.c
功能：指针作为参数函数（修改外部变量）+指针作为返回值（返回动态数组）
作者：Helen
日期：2026/1/22
*/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void add10(int *arr,int len){
    for(int i=0;i<len;i++){
        arr[i]+=10;
    }
}
int *createArr(int len){
    int *p=(int*)calloc(len,sizeof(int));
    if(p==NULL){
        printf("创建动态数组失败！\n");
        return NULL;
    }
    for(int i=0;i<len;i++){
        p[i]=i+1;
    }
    return p;
}
int main(){
    //交换两个外部变量
    int x=10,y=20;
    printf("===指针参数：交换两数===\n");
    printf("交换前：x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("交换后：x=%d,y=%d\n\n",x,y);
    //修改外部数组
    int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("===指针参数：修改外部数组===\n");
    printf("修改前：");
    for(int i=0;i<len;i++){
        printf("%d",arr[i]);
    }
    add10(arr,len);
    printf("\n修改后：");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    //函数返回动态数组
    int *dyn_arr=createArr(6);
    printf("===指针返回值：动态数组===\n");
    if(dyn_arr!=NULL){
        printf("动态数组：");
        for(int i=0;i<6;i++){
            printf("%d ",dyn_arr[i]);
        }
        free(dyn_arr);
        dyn_arr=NULL;
    }
    return 0;
}