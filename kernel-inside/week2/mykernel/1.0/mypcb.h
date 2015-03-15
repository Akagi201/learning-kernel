/*
 * @file mypcb.h
 * @author Akagi201
 * @date 2015/03/15
 *
 * mykernel--Simple simulation of the linux OS  process schedule
 * Kernel internal my_timer_handler
 * Kernel internal PCB types
 * 描述了精彩控制块的定义
 */

#define MAX_TASK_NUM        4
#define KERNEL_STACK_SIZE   1024*8

/* CPU-specific state of this task */
struct Thread {
    unsigned long ip;
    unsigned long sp;
};

typedef struct PCB {
    int pid;
    volatile long state;
    /* -1 unrunnable, 0 runnable, >0 stopped */
    char stack[KERNEL_STACK_SIZE];
    /* CPU-specific state of this task */
    struct Thread thread;
    unsigned long task_entry;
    struct PCB *next;
} tPCB;

void my_schedule(void);

