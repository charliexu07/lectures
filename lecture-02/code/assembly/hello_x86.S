; To assemble and link this, do the following:
; $ nasm -f elf64 hello_x86.S
; $ ld hello_x86.o -o hello
; $ ./hello
	
section .data                          
    msg db 'Hello World',10 	; 10 is the ascii code for a newline
	
section .text		; code segment
    global _start	; the linker looks for this
	
_start:              
    mov eax, 4		; 4 is the "write" system call
    mov ebx, 1		; 1 means write to "standard output"
    mov ecx, msg	; ecx holds the address of the string
    mov edx, 12		; edx holds the number of bytes to write
    int 80h		; invoke a system call

    mov eax, 1		; 1 is the "exit" system call
    mov ebx, 0		; 0 means success
    int 80h
