#include <stdio.h>

//  C中的控制流

int main(int argc,char* argv[]){
    //  条件分支
    //  if else
    if(argc == 1){
        printf("args = NULL\n");
    }else if(argc == 2){
        printf("args = %d\n",argc-1);
        printf("argv:%s\n",argv[1]);
    }else{
        printf("args = %d\n",argc-1);
    }

    printf("\n");

    //switch
    switch (argc)
    {
    case 1:
        printf("args = NULL\n");
        break;
    case 2:
        printf("args = %d\n",argc-1);
        printf("argv:%s\n",argv[1]);
        break;
    default:
        printf("args = %d\n",argc-1);
        break;
    }

    //  三元表达式
    argc == 2? printf("yes\n\n") : printf("no\n\n");

    //  循环结构
    int i=10;
    while(i!=0){
        printf("%d ",i);
        i--;
    }printf("\n");

    do{
        printf("%d ",i);
        i++;
    }while(i<10);
    printf("\n");

    for(i=0;i<10;i++){
        printf("%d ",i);
    }printf("\n\n");

    //  跳转控制语句
    /**
     * @param break 跳出循环或者是跳出switch语句
     * @param continue 跳过下面的步骤重新开始下一次循环
     */
    printf("goto语句示范:\n");
    int go = 0;
    lable:
    printf("%d ",go);
    if(go < 3){
        go++;
        goto lable;
    }
    printf("\n");
}

