#include <stdio.h>

//  函数声明
int fact(int);

int main(){
    printf("%d",fact(5));
}

//  函数定义
int fact(int n){
    if (n<=1){
        return 1;
    }
    int sum=1,i;
    for(i=1;i<=n;i++){
        sum*=i;
    }
    return sum;
}
