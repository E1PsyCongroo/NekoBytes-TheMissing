#ifndef __OS_H__
#define __OS_H__

#define MAX_PROC 4

typedef struct {
    int  remainingStep; // A process will run remainingStep steps
    char charToOutput;  // A process will write this character to console by doing a syscall
} Process; // Process's Context

enum {
    SYS_EXIT,  // Process exits
    SYS_WRITE, // Write to console with a character
    SYS_EXEC,  // Execute a new process with a character
};
// If you know what we are doing, you can implement the exec syscall by yourself
// You can also implement other syscalls if you want
// You can do this as a lab exercise

typedef struct {
    unsigned int syscall;
    char arg;
} Syscall;

void init();
int process_count();
int spawn_process(int var1, char var2);
Process *process_schedule();
Syscall process_step(Process *proc);
void process_exit(Process *proc);

#endif