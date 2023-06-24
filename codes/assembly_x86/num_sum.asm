/*
File:           num_sum.asm
Last changed:   24/06/2023 18:42
Purpose:        get two numbers from user and sum it      
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:  nasm -f elf64 num_sum.asm
                   gcc -no-pie -o num_sum num_sum.o  
	HowToExecute:  ./num_sum
*/ 

section .data

str0   db  "Enter an integer: ",10,0 ; Prompt for entering an integer
str1   db  "Enter another integer: ",10,0 ; Prompt for entering another integer
str2   db  "The sum of the values is %d",10,0 ; Output message for the sum

fmt  db  "%d" ; Format specifier for scanf and printf

n1   dd 0 ; First number
n2   dd 0 ; Second number

section .bss

res resb 1 ; Result of the sum

section .text
    global main
    extern printf, scanf
    
    main:
    push    rbp
    mov     rbp, rsp


    mov     rdi, str0 ; Load the address of the first prompt into rdi
    mov     rax, 0 ; Clear rax register
    call    printf ; Call printf to print the prompt

    mov     rdi, fmt ; Load the format specifier into rdi
    mov     rsi, n1 ; Load the address of n1 into rsi
    mov     rax, 0 ; Clear rax register
    call    scanf ; Call scanf to read an integer from input and store it in n1
    
    mov     rdi, str1 ; Load the address of the second prompt into rdi
    mov     rax, 0 ; Clear rax register
    call    printf ; Call printf to print the prompt
    
    mov     rdi, fmt ; Load the format specifier into rdi
    mov     rsi, n2 ; Load the address of n2 into rsi
    mov     rax, 0 ; Clear rax register
    call    scanf ; Call scanf to read an integer from input and store it in n2
    
    mov rax, [n1] ; Move the value of n1 into rax
    add rax, [n2] ; Add the value of n2 to rax
    mov [res], rax ; Move the result to the res variable
    
    mov     rdi, str2 ; Load the address of the sum output message into rdi
    mov     rsi, [res] ; Load the value of res into rsi
    mov     rax, 0 ; Clear rax register
    call    printf ; Call printf to print the sum


    leave ; Restore the previous stack frame
    mov rax, 0 ; Set the return value to 0
    ret ; Return from the main function