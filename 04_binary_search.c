/*
文件名:04_binary_search.c
功能:二分查找
作者:Helen
日期:2026/1/20
*/
#include <stdio.h>
int search(int* nums,int numsSize,int target){
    int left=0;
    int right=numsSize-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}
int main(){
    int nums[]={1,2,3,4,5,6,7};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int target;
    scanf("%d",&target);
    int result=search(nums,numsSize,target);
    if (result != -1) {
        printf("目标值 %d 的下标是：%d\n", target, result);
    } else {
        printf("目标值 %d 不存在于数组中\n", target);
    }
    return 0;
}