%include "io64.inc" 
common x 8 		;Define a global variable
common y 8 		;Define a global variable
common count 8 		;Define a global variable
common array 80 		;Define a global variable

section .data
_L0:	db "if stuff", 0		;Global string
_L1:	db "Else stuff", 0		;Global string
_L2:	db "looping with array", 0		;Global string
_L3:	db "end of loop", 0		;Global string
_L4:	db "Array checking", 0		;Global string

section .text
	global main


main:
	mov rbp, rsp		;SPECIAL RSP to RSB for MAIN only
	mov r8, rsp		;FUNC header RSP has to be at most RBP
	add r8, -56,		;adjust Stack Pointer for Activation record
	mov [r8], rbp		;FUNC header store old BP
	mov [r8+8],rsp		;FUNC header store old SP
	mov rsp, r8		;FUNC header new SP

	mov rbx, 1		;Assignment nunber
	mov rax, 16		;Move the variable into rax
	add rax, rsp		;Add rsp to rax
	mov [rax], rbx		;Assign the value
	mov rbx, 5		;Assignment nunber
	mov rax, y		;Move the variable name to rax
	mov [rax], rbx		;Assign the value
	mov rbx, 10		;Assignment nunber
	mov rax, x		;Move the variable name to rax
	mov [rax], rbx		;Assign the value
	mov rax, x		;Move the variable name to rax
	mov rax, [rax]		;Expression LHS identifier
	mov [rsp + 24], rax		;Store rax for later use
	mov rax, y		;Move the variable name to rax
	mov rbx, [rax]		;Expression RHS identifier
	mov rax, [rsp + 24]		;Get the stored rax value
	cmp rax, rbx		;expr LESSTHAN
	setl al		;set the last byte the rax in the register
	mov rbx ,1		;set rbx to 1
	and rax, rbx		;filter rax
	mov [rsp + 24], rax		;store rax in rsp + offset
	mov rax, [rsp + 24]		;If expression

	CMP rax, 0		;IF compare
	JE _L5		;
	PRINT_STRING _L0		;standard Write a string
	NEWLINE

	JMP _L6
_L5:			;Label target
	PRINT_STRING _L1		;standard Write a string
	NEWLINE

_L6:			;Label target
_L7:			;Label target
	mov rax, count		;Move the variable name to rax
	mov rax, [rax]		;Expression LHS identifier
	mov [rsp + 32], rax		;Store rax for later use
	mov rbx, 10		;Expression RHS number
	mov rax, [rsp + 32]		;Get the stored rax value
	cmp rax, rbx		;expr LESSTHAN
	setl al		;set the last byte the rax in the register
	mov rbx ,1		;set rbx to 1
	and rax, rbx		;filter rax
	mov [rsp + 32], rax		;store rax in rsp + offset
	mov rax, [rsp + 32]		;While expression

	CMP rax, 0		;Loop compare
	JE _L8
	PRINT_STRING _L2		;standard Write a string
	NEWLINE

	mov rbx, 1		;Assignment nunber
	mov rax, count		;Move the variable name to rax
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rax, count		;Move the variable name to rax
	mov rax, [rax]		;Expression LHS identifier
	mov [rsp + 40], rax		;Store rax for later use
	mov rbx, 1		;Expression RHS number
	mov rax, [rsp + 40]		;Get the stored rax value
	add rax, rbx		;add the two values
	mov [rsp + 40], rax		;store rax in rsp + offset
	mov rbx, [rsp + 40]		;Assignment expression
	mov rax, count		;Move the variable name to rax
	mov [rax], rbx		;Assign the value
	JMP _L7		;Jmp back to loop condition
_L8:			;Label target
	PRINT_STRING _L3		;standard Write a string
	NEWLINE

	mov rbx, 10		;Assignment nunber
	mov rax, 5		;Expression LHS number
	mov [rsp + 40], rax		;Store rax for later use
	mov rbx, 2		;Expression RHS number
	mov rax, [rsp + 40]		;Get the stored rax value
	imul rbx		;multi the values
	mov [rsp + 40], rax		;store rax in rsp + offset
	mov rax, [rsp + 40]		;Expression LHS expression
	mov [rsp + 48], rax		;Store rax for later use
	mov rbx, 2		;Expression RHS number
	mov rax, [rsp + 48]		;Get the stored rax value
	xor rdx, rdx		;clear rdx
	idiv rbx		;divide the values
	mov [rsp + 48], rax		;store rax in rsp + offset
	mov rcx, [rsp + 48]		;Array expr
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rbx, 2		;Assignment nunber
	mov rcx, 2		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	PRINT_STRING _L4		;standard Write a string
	NEWLINE

	mov rbx, 1		;Assignment nunber
	mov rcx, 0		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rbx, 2		;Assignment nunber
	mov rcx, 1		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rbx, 3		;Assignment nunber
	mov rcx, 2		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rbx, 0		;Assignment nunber
	mov rcx, 3		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov [rax], rbx		;Assign the value
	mov rcx, 0		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rsi, [rax]		;Write variable
	PRINT_DEC 8, rsi		;standard Write a value
	NEWLINE

	mov rcx, 1		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rsi, [rax]		;Write variable
	PRINT_DEC 8, rsi		;standard Write a value
	NEWLINE

	mov rcx, 2		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rsi, [rax]		;Write variable
	PRINT_DEC 8, rsi		;standard Write a value
	NEWLINE

	mov rcx, 3		;Array number
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rcx, [rax]		;Array identifier
	shl rcx, 3		;Shift internal offset by 3
	mov rax, array		;Move the variable name to rax
	add rax, rcx		;Add array internal offset
	mov rsi, [rax]		;Write variable
	PRINT_DEC 8, rsi		;standard Write a value
	NEWLINE

	mov rbp, [rsp]		;FUNC restore the offset
	mov rsp, [rsp+8]		;FUNC restore the stack pointer
	mov rsp, rbp		;Make stack pointer and offset equal
	xor rax, rax
	ret
