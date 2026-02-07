/*
文件名；02_string_func.c
功能；指针实现strlen/strcpy/strcmp
作者；Helen
日期：2026/1/25
*/
#include <stdio.h>
#include <assert.h>
//模拟strlen；计算字符长度
int my_strlen(const char *str){
    assert(str!=NULL);
    int len=0;
    while(*str!='\0'){
        len++;
        str++;
    }
    return len;
}
//模拟strcpy字符串拷贝
char *my_strcpy(char*dest,const char *src){
    assert(dest!=NULL&&src!=NULL);
    char *temp=dest;
    while(*dest++=*src++){
        ;//空循环体
    }
    return temp;
}
//模拟strcmp；字符串比较
int my_strcmp(const char *str1,const char *str2){
    assert(str1!=NULL&&str2!=NULL);
    while(*str1==*str2&&*str1!='\0'){
        str1++;
        str2++;
    }
    return *str1-*str2;
}
//模拟strcat:字符串拼接
char *my_strcat(char*dest,const char *src){
    assert(dest!=NULL&&src!=NULL);
    char *temp=dest;
    while(*dest){
        *dest++;
    }
    while(*src){
    *dest++=*src++;
    }
    *dest='\0';
     return temp;
}
int main(){
    char str1[]="hello world";
    printf("===测试my_strlen===\n");
    printf("字符串；%s,长度；%d\n",str1,my_strlen(str1));
    
    char dest[20]={0};
    char src[]="C language";
    printf("\n===测试my_strcpy===\n");
    my_strcpy(dest,src);
    printf("拷贝后；%s\n",dest);
    char str2[]="abc";
    char str3[]="abd";
    char str4[]="abc";

    printf("\n===测试my_strcmp===\n");
    printf("abc vs abd:%d\n",my_strcmp(str2,str3));
    printf("abc vs abc:%d\n",my_strcmp(str2,str4));
    printf("abd vs abc:%d\n",my_strcmp(str3,str2));

    printf("\n===测试my_strcat===\n");
    printf("%s\n",my_strcat(str1,str2));

    return 0;
}