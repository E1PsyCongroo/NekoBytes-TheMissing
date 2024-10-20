#include <sys/syscall.h>
#include <unistd.h>

const char str[] = "\033[01;31mHello, OS World\033[0m\n";
const int str_size = sizeof str - 1;

int main(void) {
  asm volatile("movl %0, %%eax\n\t" // 系统调用号：SYS_write
               "movl $1, %%edi\n\t" // 文件描述符：STDOUT_FILENO (标准输出)
               "movq %2, %%rsi\n\t" // 字符串地址
               "movl %3, %%edx\n\t" // 字符串长度
               "syscall"            // 调用系统调用
               :
               : "r"(SYS_write), "r"(STDOUT_FILENO), "r"(str), "r"(str_size)
               : "eax", "edi", "rsi", "edx");
  return 0;
}
