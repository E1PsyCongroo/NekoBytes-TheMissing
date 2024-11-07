# Lab6 使用工具

## GCC、多文件编译和Makefile

### Task1

1. 使用命令`gcc ./task1.c -o ./task1 -Wall -Werror`编译，会看到两个错误。
2. 错误分别是将`char`赋值给`char*`和返回的`Cource **`与函数声明中的`Course *`不符。
3. 修改：

```patch
--- ./task1.c
+++ ./task1_solution.c
@@ -10,9 +10,9 @@
 struct Course *make_course(int id, char *name) {
     struct Course *new_course = malloc(sizeof(struct Course));
     new_course->id = id;
-    new_course->name = *name;
+    new_course->name = name;

-    return &new_course;
+    return new_course;
 }
 int main() {
     struct Course *cstart = make_course(0x001, "cstart");
```

### Task2

1. 在目录`./zuma`下使用命令`gcc -I./include ./src/linkedlist.c ./src/main.c ./src/zuma.c -o zuma`进行编译。
2. 错误是由引入了两次`zuma.h`头文件（在`zuma.c`的第一行，第一次引入，在第二行包含`linkedlist.h`的时候再次引入）造成的，多个变量被重复声明。
3. 解决办法：
    方法一：

    ```patch
    --- ./zuma/include/zuma.h
    +++ ./zuma/include/zuma_solution.h
    @@ -1,3 +1,5 @@
    +#pragma once
    +
    #include <stdio.h>
    #include <stdlib.h>
    ```

    方法二：

    ```patch
    --- ./zuma/include/zuma.h
    +++ ./zuma/include/zuma_solution.h
    @@ -1,3 +1,6 @@
    +#ifndef __ZUMA_H__
    +#define __ZUMA_H__
    +
    #include <stdio.h>
    #include <stdlib.h>

    @@ -17,4 +20,6 @@
    void set_top(int k);
    void init();
    void solve();
    -void print_all();
    \ No newline at end of file
    +void print_all();
    +
    +#endif
    ```

### Task3 Task4 Task5

见`./zuma/makefile`。

### Task6 Task7

见`./zuma/task67.mk`。这是一个复杂的脚本。基本思想是：

1. 为每个`.c`源文件生成一个`.o`的目标文件。
2. 每个目标文件`.o`的依赖由`gcc -MMD`生成。

一些细节：

1. 通过规则`$(BUILD_DIR)/%.o: ./src/%.c`为每一个`.c`文件生成一个`.o`文件，并且附带一个`.d`的依赖文件来表明依赖。
2. `-include $(DEPS)`用于引入`gcc`生成的依赖，你可以查看`build`目录下的`.d`文件来理解。

### Task8

使用`bear -- make`。

## 调试工具

### Task9

现在你学会了`assert`，尝试在你自己项目中进行防御性编程吧。

### Task10 Task11

错误有三个地方：

```patch
--- ./src/checker.c
+++ ./src/checker_solution.c
@@ -22,13 +22,13 @@
 /* Returns true if the length of PASSWORD is at least 10, false otherwise */
 bool check_length(const char *password) {
     int length = strlen(password);
-    bool meets_len_req = (length <= 10);
+    bool meets_len_req = (length >= 10);
     return meets_len_req;
 }

 /* Returns true if LETTER is in the range [LOWER, UPPER], false otherwise */
 bool check_range(char letter, char lower, char upper) {
-    bool is_in_range = (letter > lower && letter < upper);
+    bool is_in_range = (letter >= lower && letter <= upper);
     return is_in_range;
 }

@@ -59,7 +59,7 @@
 /* Returns true if PASSWORD contains at least one number, false otherwise */
 bool check_number(const char *password) {
     while (*password != '\0') {
-        if (check_range(*password, 0, 9)) {
+        if (check_range(*password, '0', '9')) {
             return true;
         }
         ++password;
```

### Task12

问题在于对一个`NULL`解引用并且赋值。

```patch
--- ./task12.c
+++ ./task12_solution.c
@@ -11,8 +11,6 @@
 }

 void ben(int *arr, int size) {
-    int *ptr = NULL;
-    *ptr = 10;
     jero(arr, size);
 }
```

### Task13

问题在于`alloc_str`函数，它没有为字符串末尾的`'\0'`分配空间。

```patch
--- ./task13.c
+++ ./task13_solution.c
@@ -7,7 +7,9 @@
 #include <string.h>

 char *alloc_str(int len) {
-    return malloc(len*sizeof(char));
+    char *p = (char *)malloc((len+1)*sizeof(char));
+    p[len] = '\0';
+    return p;
 }

 /* Str helper functions */
```
