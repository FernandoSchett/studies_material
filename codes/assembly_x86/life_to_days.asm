/*
File:           life_to_days.asm
Last changed:   24/06/2023 15:00
Purpose:        get age from user and print it in days         
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:  nasm -f elf64 life_to_days.asm
                   gcc -no-pie -o life_to_days life_to_days.o  
	HowToExecute:  ./life_to_days
*/ 

global main
extern printf
extern scanf

section .bss
    user_years resd 1 
    user_months resd 1 
    user_days resd 1 

section .data
    ask_years db "How many years old are you?", 10, 0
    ask_months db "How many months?", 10, 0
    ask_days db "And how many days?", 10, 0
    int_format db "%d", 0 
    final_msg db "Your age is %d days old", 10, 0 

section .text
main:
   
    push rbp
    mov rbp, rsp

   
    mov rdi, ask_years
    xor rax, rax ; Clear RAX 
    call printf
    

    mov rdi, int_format
    lea rsi, [user_years] ; Load address of user_years into RSI
    xor rax, rax ; Clear RAX 
    call scanf
    
    ; Store the value of years in RBX
    mov ebx, dword [user_years]
    

    mov rdi, ask_months
    xor rax, rax
    call printf
    

    mov rdi, int_format
    lea rsi, [user_months] ; Load address of user_months into RSI
    xor rax, rax
    call scanf
    
    ; Store the value of months in R12D
    mov r12d, dword [user_months]
    

    mov rdi, ask_days
    xor rax, rax
    call printf
    

    mov rdi, int_format
    lea rsi, [user_days] ; Load address of user_days into RSI
    xor rax, rax
    call scanf
    
    ; Multiply by 365
    imul ebx, 365
    
    ; Multiply  by 30
    imul r12d, 30
    
    ; Add up the total number of days
    mov eax, ebx ; Move the number of days in years to EAX
    add eax, r12d ; Add the number of days in months
    add eax, dword [user_days] ; Add the number of days
    
    mov rdi, final_msg
    mov esi, eax ; Move total number of days to ESI
    xor rax, rax
    call printf

    mov rsp, rbp
    pop rbp
    ret
