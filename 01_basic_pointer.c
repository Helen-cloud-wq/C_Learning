#include <stdio.h>
int main(){
    int a=10;
    float b=3.14f;
    char c='A';
    printf("变量初始值:a=%d,b=%.2f,c=%c\n",a,b,c);
    
    int *pa=&a;
    float *pb=&b;
    char *pc=&c;
    printf("\n==地址打印==\n");
    printf("a的地址:%p\n",&a);
    printf("pa存放的值:%p\n",pa);
    printf("b的地址:%p\n",&b);
    printf("pb存放的地址:%p\n",pb);
    printf("c的地址:%p\n",&c);
    
    printf("\n==解引用访问值==\n");
    printf("pa指向的值:%d",*pa);
    *pa=20;
    *pb=6.28f;
    *pc='B';
    printf("\n==修改后的值==\n");
    printf("a的值:%d\n",a);
    printf("b的值:%.2f\n",*pb);
    printf("c的值:%c\n",c);
    return 0;


}
