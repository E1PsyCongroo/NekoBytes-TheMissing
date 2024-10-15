#include "os.h"
#include <stdlib.h>
#include <time.h>

void init() {
    srand(time(NULL));
}

Process procArray[MAX_PROC];
Process *runningProcess[MAX_PROC];

unsigned int procCount = 0;

int process_count() {
    return procCount;
}

int spawn_process(int var1, char var2) {
    if (procCount >= MAX_PROC) {
        return -1;
    } else {
        // Initialize process 
        Process *proc = &procArray[procCount];
        proc->remainingStep = var1;   // A process will run var1 step(s)
        proc->charToOutput = var2;   // A process will write this character to console
        runningProcess[procCount] = proc;
        procCount ++;
        return 0;
    }
}

Process *process_schedule() {
    int i = rand() % procCount;
    return runningProcess[i];
}

Syscall process_step(Process *proc) {
    Syscall call;
    if (proc->remainingStep > 0) {
        proc->remainingStep --;
        call.syscall = SYS_WRITE;
        call.arg = proc->charToOutput;
    } else {
        call.syscall = SYS_EXIT;
        call.arg = 0;
    }
    return call;
}

void process_exit(Process *proc) {
    for (unsigned int i = 0; i < procCount; i++) {
        if (runningProcess[i] == proc) {
            for (unsigned int j = i; j < procCount - 1; j++) {
                runningProcess[j] = runningProcess[j + 1];
            }
            runningProcess[procCount - 1] = NULL;
            procCount --;
            break;
        }
    }
}
