#include <stdio.h>
#include <stdlib.h>
#include "os.h"

/*
In this model, we have a mini Operating System that can run multiple processes.
Each process has a context that contains two variables: remainingStep and charToOutput.
remainingStep is the number of steps that a process will run and then exit by doing a syscall EXIT.
charToOutput is the character that a process will write to the console by doing a syscall WRITE.
在这个模型中，我们模拟了一个简单的操作系统，可以运行多个进程.
每个进程有一个上下文，包含两个变量：remainingStep 和 charToOutput.
程序将运行，并不断发起系统调用，请求操作系统向终端中写入字符 charToOutput.
在写入了 remainingStep 次后, 进程将会使用系统调用 SYS_EXIT 退出。
 */


void run() {
    Process *current;
    while (process_count()) {
        // The Operating System will randomly choose a process to run
        // 操作系统会随机选择一个进程来运行
        current = process_schedule();
        
        // Switch process context and run it until a syscall
        // 切换进程上下文并运行，直到发起系统调用
        Syscall call = process_step(current);
        
        if (call.syscall == SYS_EXIT) {
            // Process exits
            // 进程退出
            process_exit(current);
        } else if (call.syscall == SYS_WRITE) {
            // Write the character from syscall arg to the console
            // 将系统调用参数中的字符写入终端
            putchar(call.arg);
        }
    }
    putchar('\n');
}

int main() {
    // Initialize the Operating System
    // 初始化操作系统
    init();

    // spawn processes
    // 创建进程
    spawn_process(5, 'A');
    spawn_process(5, 'B');
    spawn_process(5, 'C');
    
    // start running
    // 开始运行
    run();
    
    return 0;
}
