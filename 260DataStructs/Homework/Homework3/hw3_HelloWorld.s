.global _start
.text
_start:

    mov     $1, %rax        # system call 1 is write
    mov     $1, %rdi
    mov     $message, %rsi  # address of string to output
    mov     $130, %rdx
    syscall

    movq    $60, %rax
    xor     %rdi, %rdi
    syscall
message: .ascii "This is a simple test and may not work!\nHowever, I have faith this will print and I can go home.\n"