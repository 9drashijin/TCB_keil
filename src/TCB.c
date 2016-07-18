#include "TCB.h"

Tcb mainTcb;
Tcb task1Tcb;
Tcb task2Tcb;
Tcb *readyQueue;
Tcb *runningQueue;

uint8_t tempStack[TASK_STACK_SIZE];

CpuContext *cc;

void taskOne(void){
	while(1){}
}
void taskTwo(void){
	while(1){}
}

/**
 * Must call this function first
 */
void initTcb() {
	mainTcb.name = "main_thread";
	mainTcb.sp = 0x12345678;
	
	task1Tcb.name = "task_1";
	cc = (CpuContext *)(((uint32_t)(&task1Tcb.virtualStack[TASK_STACK_SIZE])) - sizeof(CpuContext));
	task1Tcb.sp = (uint32_t)cc;
	
	cc->r4   = 0x44444444;
	cc->r5   = 0x55555555;
	cc->r6   = 0x66666666;
	cc->r7   = 0x77777777;
	cc->r8   = 0x88888888;
	cc->r9   = 0x99999999;
	cc->r10  = 0xaaaaaaaa;
	cc->r11  = 0xbbbbbbbb;
	cc->r0   = 0xabababab;
	cc->r1   = 0x11111111;
	cc->r2   = 0x22222222;
	cc->r3   = 0x33333333;
	cc->r12  = 0xcccccccc;
	cc->lr   = 0xFFFFFFF9;
	cc->pc   = (uint32_t)taskOne;
	cc->xpsr = 0x01000000;
	
	runningQueue = &mainTcb;
	readyQueue = &task1Tcb;
	
	task2Tcb.name = "task_2";
	cc = (CpuContext *)(((uint32_t)(&task2Tcb.virtualStack[TASK_STACK_SIZE])) - sizeof(CpuContext));
	task2Tcb.sp = (uint32_t)cc;
	
	cc->pc   = (uint32_t)taskTwo;
	cc->xpsr = 0x01000000;
	
}

// Study the code in AsssemblyModule.s and take note of what
// how each instruction performs its job. You need that knowledge
// to do the following:
//
// 1) Create a new assembly file called 'SaveRegisters.s'.
// 2) Write a code in assembly [in (1)] to:
//    - load SP with the value in 'task1Tcb.sp'
//    - push all registers, except R13 to the stack
// 3) Name that function as 'saveRegs'
// 4) From main() call: 
//    - initTcb()
//    - saveRegs()
// 5) Verify that the registers are in 'task1Tcb.virtualStack'
// 6) Submit your work by pushing it to GitHub
