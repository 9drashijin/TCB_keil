;******************** (C) COPYRIGHT 2015 TARUC *********************************
;* File Name          : AssemblyModule.s
;* Author             : Poh Tze Ven
;* Version            : Ver.0.1
;* Date               : 23-June-2015
;* Description        : Simple functions to demonstrates assembly-c callings. 
;*******************************************************************************
; 
;* Redistribution and use in source and binary forms, with or without modification,
;* are permitted provided that the following conditions are met:
;*   1. Redistributions of source code must retain the above copyright notice,
;*      this list of conditions and the following disclaimer.
;*   2. Redistributions in binary form must reproduce the above copyright notice,
;*      this list of conditions and the following disclaimer in the documentation
;*      and/or other materials provided with the distribution.
;*   3. Neither the name of STMicroelectronics nor the names of its contributors
;*      may be used to endorse or promote products derived from this software
;*      without specific prior written permission.
;*
;* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
;* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
;* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
;* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
;* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
;*******************************************************************************
								PRESERVE8
                THUMB

; Global data
                AREA    MyData, DATA, READWRITE, ALIGN=2
                EXPORT  fourBytes
                EXPORT  twoBytes
                EXPORT  oneByte
fourBytes				DCD     1
twoBytes				DCW     2, 3
oneByte 				DCB     4, 5, 6, 7

                AREA    MyCode, CODE, READONLY
noArgFunc		  	PROC
                EXPORT  noArgFunc
                IMPORT  cFunc
								IMPORT  variableInC

								mov			r0, #0xfa
								mov			r1, #0xce
								
								push	  {r0, r1}						; Look at the stack memory under 'View->Memory 1'
								pop 	  {r0, r1}						; (Note: You must be in Debug mode to see it)
								
								; Put 0xb19face in 'variableInC'
								ldr     r3, =0xb19face
								ldr			r4, =variableInC		; Let R3 points to 'variableInC'
								str  		r3, [r4]						; Store the lower half of R3 to where R4 is pointing to
								; Load value in fourBytes to R3 
								ldr			r3, =fourBytes			; Let R3 points to 'fourBytes'
								ldr			r3, [r3]						; Load the value into R3
								; Store 0xbee in twoBytes
								movw    r3, #0xffee
								ldr 		r4, =twoBytes				; Let R4 points to 'twoBytes'
								strh		r3, [r4]						; Store the lower half of R3 to where R4 is pointing to
																
								push	  {lr}								; Must save LR so that we can return to our caller
								ldr			r0, =cFunc					; Load the address of cFunc()
								blx			r0									; Call (branch-with-link)
																						; Notice that R0 = 0xC0FFEE												
								pop	    {lr}								; Pop our caller's return address
								bx			lr									; Return to our caller
								
                ENDP
									
								END
									