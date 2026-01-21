#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("原数组：");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int *left=arr;
    int *right=arr+len-1;
    int temp;
    while(left<right){
        temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
    printf("逆序数组：");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}