#ifndef __TCB_H__
#define __TCB_H__

#include <stdint.h>

#define TASK_STACK_SIZE	960

typedef struct Tcb Tcb;

struct Tcb{
	Tcb *next;
	char *name;									// Task name	
	uint32_t 	sp;								// Stack pointer (R13)
	uint8_t		virtualStack[TASK_STACK_SIZE];
};

typedef struct {
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r12;
	uint32_t lr;
	uint32_t pc;
	uint32_t xpsr;
} CpuContext;

extern Tcb mainTcb;
extern Tcb task1Tcb;
extern Tcb task2Tcb;
extern Tcb task3Tcb;

extern uint8_t tempStack[TASK_STACK_SIZE];

void taskOne(void);
void taskTwo(void);
void taskThree(void);
void initTcb(void);

#endif	// __TCB_H__
