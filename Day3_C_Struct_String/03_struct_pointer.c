/*
文件名；03_struct_pointer.c
功能；结构体指针核心用法，区分.和->运算符
作者；Helen
日期；2026/1/25
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student{
    char name[20];
    int age;
    float scores;
};
void modifyStudent(struct Student *p,int new_age,float new_scores){
    p->age=new_age;
    p->scores=new_scores;
    strcpy(p->name,"Li Ming");
}
void printStudent(const struct Student *p){
    printf("姓名；%s.年龄；%d.成绩；%.1f\n",p->name,p->age,p->scores);
}
int main(){
    struct Student s={"Zhang San",17,90.5};
    printf("===初始学生信息===\n");
    printStudent(&s);

    modifyStudent(&s,18,95.0);
    printf("\n===修改后学生信息===\n");
    printStudent(&s);

    struct Student *p_stu=(struct Student *)malloc(sizeof(struct Student));
    if(p_stu==NULL){
        printf("内存申请失败！\n");
        return -1;
    }
    strcpy(p_stu->name,"Wang Hua");
    p_stu->age=19;
    p_stu->scores=88.5;
    printf("\n===动态结构体信息===\n");
    printStudent(p_stu);

    free(p_stu);
    p_stu=NULL;
    return 0;
}