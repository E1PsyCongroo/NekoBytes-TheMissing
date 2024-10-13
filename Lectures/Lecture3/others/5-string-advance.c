#include <stdio.h>
#include <string.h>

//  string.h标准库的几个常用函数

int main(){
    char str1[] = "I Can Eat Glass";
    char str2[] = "Neko Bytes";

    printf("str1:%s\nsize:%lu\nstr2:%s\nsize:%lu\n",\
    str1,strlen(str1),str2,strlen(str2));

    //  字符串比较
    int h = strcmp(str1,str2);
    if(h!=0){
        if(h>0){
            printf("str1更大\n");
        }
        else{
            printf("str2更大\n");
        }
    }
    else{
        printf("str1和str2一样大\n");
    }

    //  字符串赋值
    strcpy(str1,"I love windows\n");
    printf("str1:%s",str1);

    return 0;
}
