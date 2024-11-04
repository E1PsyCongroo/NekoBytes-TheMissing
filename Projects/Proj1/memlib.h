#include <unistd.h>

void mem_init(void);
void mem_deinit(void);
/*传入需要扩展的空间的大小incr，在原空间的基础上在堆栈上申请新空间，可以视作连续的空间*/
void *mem_sbrk(int incr);
void mem_reset_brk(void);
/*返回指向当前堆栈最前部的指针*/
void *mem_heap_lo(void);
/*返回指向当前堆栈最后部的指针*/
void *mem_heap_hi(void);
/*返回当前堆大小（单位：字节）*/
size_t mem_heapsize(void);
size_t mem_pagesize(void);
