/*
 * @file mypcb.h
 * @author Akagi201
 * @date 2015/03/15
 *
 * mykernel--Simple simulation of the linux OS  process schedule
 * Kernel internal my_timer_handler
 * 描述了精彩控制块的定义
 */

#ifndef MYPCB_H_
#define MYPCB_H_ (1)

#define MAX_TASK_NUM (10) // max num of task in system
#define KERNEL_STACK_SIZE (1024*8)
#define PRIORITY_MAX (30) //priority range from 0 to 30

/* CPU-specific state of this task */
struct Thread {
    unsigned long ip;
    //point to cpu run address
    unsigned long sp;//point to the thread stack's top address
    //todo add other attrubte of system thread
};
//PCB Struct
typedef struct PCB {
    int pid; // pcb id 
    volatile long state;
    /* -1 unrunnable, 0 runnable, >0 stopped */
    char stack[KERNEL_STACK_SIZE];// each pcb stack size is 1024*8
    /* CPU-specific state of this task */
    struct Thread thread;
    unsigned long task_entry;
    //the task execute entry memory address
    struct PCB *next;
    //pcb is a circular linked list
    unsigned long priority;// task priority ////////
    //todo add other attrubte of process control block
} tPCB;

//void my_schedule(int pid);
void my_schedule(void);

#endif
