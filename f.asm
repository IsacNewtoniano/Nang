section .text
global main
extern GetStdHandle
extern WriteFile
extern ExitProcess

main:
    ; HANDLE stdout = GetStdHandle(STD_OUTPUT_HANDLE)
    mov ecx, -11
    call GetStdHandle

    ; WriteFile(stdout, msg, 13, &written, NULL)
    mov rcx, rax
    lea rdx, [rel msg]
    mov r8d, 13
    lea r9, [rel written]

    sub rsp, 32
    mov qword [rsp+32], 0
    call WriteFile
    add rsp, 32

    xor ecx, ecx
    call ExitProcess

section .data
msg:     db "Hello, world!", 13, 10
written: dq 0