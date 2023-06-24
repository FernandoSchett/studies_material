/*
File:           factorial.asm
Last changed:   24/06/2023 15:00
Purpose:        calculate factorial of a number input by the user
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:  nasm -f elf64 factorial.asm
                 gcc -no-pie -o factorial factorial.o  
	HowToExecute:  ./factorial
*/ 

section .data
  str1 db "Enter a number to calculate the factorial: ", 10, 0
  str2 db "The factorial is equal to %llu", 10, 0
  fmt db "%llu", 0

  result dq 1

section .bss
  num resq 1

section .text
  extern printf, scanf
  global main

  main:
    call readNum
    call readNumScanf
    call calculate
    call printResult
    call exitProgram

  readNum:
    mov rdi, str1  
    mov rax, 0     
    call printf    
    ret

  readNumScanf:
    mov rdi, fmt   
    mov rsi, num   
    mov rax, 0     
    call scanf     
    ret

  ; Calculate the factorial of the number
  calculate:
    mov rax, [num]
    cmp rax, 1
    jle endCalculate
    call factorialLoop
    ret

  factorialLoop:
    mov rax, [result]
    mov rbx, [num]
    mul rbx
    mov [result], rax
    dec qword [num]
    jmp calculate

  endCalculate:
    ret

  ; Print the result of the factorial
  printResult:
    mov rdi, str2  ; format string
    mov rsi, [result]  
    mov rax, 0     ; variadic functions require this to be set to 0
    call printf    
    ret

  ; Exit the program
  exitProgram:
    mov eax, 60
    xor edi, edi
    syscall
