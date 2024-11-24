#!/bin/bash    

# 检查编译是否成功
make  
if [ $? -ne 0 ]; then  
    echo "编译失败，请检查代码。"  
    exit 1  
fi  

# 使用 valgrind 运行程序并检查内存泄漏  
  
valgrind --leak-check=full --show-leak-kinds=all ./main  

# 检查 Valgrind 的退出状态  
if [ $? -eq 0 ]; then  
    echo "未检测到内存泄漏。"  
else  
    echo "检测到内存泄漏或其他内存错误。"  
fi