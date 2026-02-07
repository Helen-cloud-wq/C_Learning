/*
文件名：04_student_manage.c
功能：
输入 n 个学生的信息（姓名、年龄、成绩）；
按成绩降序排序（指针实现）；
按姓名查找学生（用自定义strcmp）；
打印所有学生信息;
作者：Helen
日期：2026/1/26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
struct Student{
    char name[20];
    int age;
    float score;
};
int my_strcmp(const char *str1,const char *str2){
    assert(str1!=NULL&&str2!=NULL);
    while(*str1==*str2&&*str1!='\0'){
        str1++;
        str2++;
    }
    return *str1-*str2;
}
void sortByScore(struct Student *arr,int n){
    assert(arr&&n>0);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].score<arr[j+1].score){
                struct Student temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int findStudent(struct Student *arr,int n, const char *name){
    assert(arr&&n>0&&name);
    for(int i=0;i<n;i++){
        if(my_strcmp(arr[i].name,name)==0){
            return i;
        }
    }
    return -1;
}
void printAll(struct Student *arr,int n){
    assert(arr&&n>0);
    printf("===学生信息列表（按成绩降序）===\n");
    for(int i=0;i<n;i++){
        printf("第%d个；姓名=%s,年龄=%d,成绩=%.1f\n",
        i+1,arr[i].name,arr[i].age,arr[i].score);
    }
}
int main(){
    int n,idx;
    char find_name[20];
    struct Student *stu_arr=NULL;
    printf("请输入学生数量；");
    scanf("%d",&n);
    stu_arr=(struct Student *)calloc(n,sizeof(struct Student));
    if(stu_arr==NULL){
        printf("内存申请失败！\n");
        return -1;
    }
    for(int i=0;i<n;i++){
        printf("请输入第%d个学生信息（姓名 年龄 成绩）；",i+1);
        scanf("%s %d %f",stu_arr[i].name,&stu_arr[i].age,&stu_arr[i].score);
    }
    sortByScore(stu_arr,n);
    printAll(stu_arr,n);
    printf("\n请输入要查找的学生姓名；");
    scanf("%s",find_name);
    idx=findStudent(stu_arr,n,find_name);
    if(idx==-1){
        printf("未找到学生；%s\n",find_name);
    }else{
        printf("找到学生；姓名=%s,年龄=%d,成绩=%.1f\n",
            stu_arr[idx].name,stu_arr[idx].age,stu_arr[idx].score);

    }
    free(stu_arr);
    stu_arr=NULL;

    return 0;
}
