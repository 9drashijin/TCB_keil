								PRESERVE8
                THUMB

; Global data
                AREA    MyCode, CODE, READONLY
saveReg		  	  PROC
                EXPORT  saveReg
								IMPORT	mainTcb
								IMPORT	task1Tcb
								IMPORT  runningQueue
								IMPORT  readyQueue
							
								
;							  ldr    r0,  =0xabababab
;							  ldr    r1,  =0x11111111
;					 		  ldr    r2,  =0x22222222
;							  ldr    r3,  =0x33333333
;							  ldr    r4,  =0x44444444
;							  ldr    r5,  =0x55555555
;							  ldr    r6,  =0x66666666
;							  ldr    r7,  =0x77777777
;							  ldr    r8,  =0x88888888
;							  ldr    r9,  =0x99999999
;							  ldr    r10, =0xaaaaaaaa
;							  ldr    r11, =0xbbbbbbbb
;							  ldr    r12, =0xcccccccc
;							  ldr    lr,  =0xdddddddd
;							  push	{r0}
;							  bx		 lr
								
								
								push   {r4-r11}

								ldr    r0,  =runningQueue   ; mov address of runningQ(mainTcb) to r0
								ldr    r1,  [r0]		    		; deref runningQ, then content mov to r1
								ldr    r2,  [r1,#4]		    	; value of mainTcb sp 0x12345678

								str	   sp,  [r1,#4]		    	; Store the sp value

								ldr    r0,  =readyQueue     ; mov address of taskOne to r0
								ldr    r1,  [r0]						; deref readyQ, then content mov to r1
								ldr    lr,  [r1,#4]					; value of taskOne move to lr

								ldr    r0,  [lr,#32]				; should get 0xabababab
								ldr    r1,  [lr,#36]				; should get 0x11111111
								ldr    r2,  [lr,#40]				; should get 0x22222222
								ldr    r3,  [lr,#44]				; should get 0x33333333
								ldr    r4,  [lr,#0]					; should get 0x44444444
								ldr    r5,  [lr,#4]					; should get 0x55555555
								ldr    r6,  [lr,#8]					; should get 0x66666666
								ldr    r7,  [lr,#12]				; should get 0x77777777
								ldr    r8,  [lr,#16]				; should get 0x88888888
								ldr    r9,  [lr,#20]				; should get 0x99999999
								ldr    r10, [lr,#24]				; should get 0xaaaaaaaa
								ldr    r11, [lr,#28]				; should get 0xbbbbbbbb
								ldr    r12, [lr,#48]				; should get 0xcccccccc
								;ldr    lr,  [r12,#52]
								ldr    pc,  [lr,#56]				; Load back the pc address
								bx 	   lr										; branch back

                ENDP
									
								END
									