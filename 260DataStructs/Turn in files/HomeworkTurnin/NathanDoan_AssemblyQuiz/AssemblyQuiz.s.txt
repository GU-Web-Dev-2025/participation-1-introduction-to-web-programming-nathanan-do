.global _start
.text
_start:
    
    movl    $34,    %r8d    # x = 34
    movl    $27,    %r9d    # y = 27
    movl    $19,    %r10d   # z = 19
    movl    %r9d,   %r11d   # u = y

    movl    %r8d,   %eax    # v = x
    subl    %r10d,  %eax    # v = v - z
    movl    %eax,   %r12d   # v = x - z

    movl    %r8d,   %ebx    # x = x
    subl    %r10d,  %ebx    # x = x - z
    addl    %r9d,   %ebx    # x = x + y
    subl    %r10d,  %ebx    # x = x - z
    movl    %ebx,   %r8d    # x = x - z + y - z

    movl    %r9d,   %ecx    # y = y
    addl    %r8d,   %ecx    # y = y + x
    subl    %r10d,  %ecx    # y = y - z
    movl    %ecx,   %r9d    # y = y + x - z

    movl    %r9d,   %esi    # move y to 2nd argument register
    movl    $fmt,   %edi    # format string
    movl    $0,     %eax    # Clear AL (for varargs calling convention)
    call    printf          # call printf

    movl    $60,    %eax    #syscall exit
    xorl    %edi,   %edi    # status = 0
    syscall

fmt: .asciz "%d\n"