 #include <stdio.h>
 
 void add_one(int input) {
   input += 1;
 }
 
 // TODO: 创建一个指向输入的指针
 void add_one_pointer(______ input) {
   // TODO: 输入指向的整数加一
   ________ += 1;
 }
 
 int main() {
   // 将 x（整数）赋给 5
   int x = 5;
 
   // 在 x 上调用 add_one
   add_one(x);
 
   // 这一行应该打印 5
   // Why doesn't this work?
   printf("add_one: %d\n", x);
 
   // 让我们尝试使用 add_one_pointer
 
   // TODO: 使用 add_one_pointer 来增加 x
   // Hint: 将 x 的类型与参数的类型进行比较
   //       对于 add_one_pointer
   add_one_pointer(______);
 
   // 这一行应该打印 6
   printf("add_one_pointer: %d\n", x);
 
   return 0;
 }