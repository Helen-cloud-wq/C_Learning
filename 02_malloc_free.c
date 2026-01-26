/*
文件名：02_malloc_free_.c
功能：malloc/calloc/realloc/free核心用法，避免内存泄漏/野指针坑
作者:Helen
日期:2026/1/22
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n=5;
    int *p=NULL;
    p=(int*)malloc(n*sizeof(int));
    if(p==NULL){
        printf("malloc申请内存失败！\n");
        return -1;
    }
    printf("===malloc(未初始化)===\n");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        printf("p[%d]=%d\n",i,p[i]);
    }
    int *p_new=(int*)realloc(p,8*sizeof(int));
    if(p_new==NULL){
        printf("realloc扩容失败！\n");
        free(p);
        p=NULL;
        return -1;
    }
    p=p_new;
    for(int i=5;i<8;i++){
        p[i]=i+1;
    }
    printf("\n===realloc（扩容为8个）===\n");
    for(int i=0;i<8;i++){
        printf("p[%d]=%d\n",i,p[i]);
    }
    free(p);
    p=NULL;
    int *q=(int*)calloc(4,sizeof(int));
    if(q==NULL){
        printf("calloc申请内存失败!\n");
        return -1;
    }
    printf("\n===calloc(自动初始化0)===\n");
    for(int i=0;i<4;i++){
        printf("q[%d]=%d\n",i,q[i]);
    }
    free(q);
    q=NULL;
    return 0;

}
/*动态内存核心是申请，判空，使用，释放，置空*/