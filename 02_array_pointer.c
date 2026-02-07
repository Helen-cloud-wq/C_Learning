#include <stdio.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("数组长度:%d\n",len);
    
    int *p=arr;
    printf("\n===地址验证===\n");
    printf("数组名arr的地址:%p\n",arr);
    printf("arr[0]的地址:%p\n",&arr[0]);
    printf("指针p的地址:%p\n",p);

    printf("\n===取值验证===\n");
    printf("arr[2]=%d\n",arr[2]);
    printf("arr指针表示:%d\n",*(arr+2));
    printf("p指针表示:%d\n",*(p+2));
    //访问下标遍历
    printf("遍历结果:");
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    //指针偏移遍历
    printf("遍历结果:");
    for(int i=0;i<len;i++){
        printf("%d ",*p);
        p++;
    }
    return 0;


}