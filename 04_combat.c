#include <stdio.h>
#include <stdlib.h>
void reverse(int *arr,int length){
    int *left=arr;
    int *right=arr+length-1;
    while(left<right){
        int temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}
int check(int target,int *arr,int length){
    int left=0;
    int right=length-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
    
}
int main(){
    printf("请输入数组长度:\n");
    int len;
    scanf("%d",&len);
    int *p=NULL;
    p=(int*)malloc(len*sizeof(int));
    printf("请输入数组的值:\n");
    for(int i=0;i<len;i++){
        scanf("%d",p+i);
    }
    reverse(p,len);
    printf("===逆序数组===\n");
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n请输入目标值:\n");
    int t;
    scanf("%d",&t);
    int result=check(t,p,len);
    printf("目标值的下标为:");
    printf("%d ",result);
    free(p);
    return 0;
}