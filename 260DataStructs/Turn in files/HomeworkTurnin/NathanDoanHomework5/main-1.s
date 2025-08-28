
	.global _start
	.text
_start:

	# print the message string before sorting
	mov	$1, %rax
	mov	$1, %rdi
	mov	$message, %rsi
	mov	$16, %rdx
	syscall

	# fill in the code here to sort the string
	# alphabetically from A to Z, keeping the \n
	# at the end of the string

	# You code here...

	# ASM - Bubble sort implementation #
	# If first char > second char, swap

	mov     $0, %rcx              # outer loop counter i = 0

	# loop over indicies 0-13
outer_loop:
    cmp     $14, %rcx             # while i < 14 (0–13)
    jge     end_sort

    mov     $0, %rdx              # inner loop counter j = 0

	# neighboor comparison
inner_loop:
    mov     $14, %r8              # compare limit is 14 - i
    sub     %rcx, %r8
    cmp     %r8, %rdx             # while j < 14 - i
    jge     next_outer

    mov     $message, %rsi
    add     %rdx, %rsi            # rsi = &message[j]
    mov     (%rsi), %al           # al = message[j]
    mov     1(%rsi), %bl          # bl = message[j+1]

    cmp     %bl, %al              # if message[j] > message[j+1]
    jle     no_swap

    # swap: message[j] <-> message[j+1]
    mov     %bl, (%rsi)
    mov     %al, 1(%rsi)

no_swap:
    inc     %rdx                  # j++
    jmp     inner_loop

next_outer:
    inc     %rcx                  # i++
    jmp     outer_loop

end_sort:

	# print the message string after sorting
	mov	$1, %rax
	mov	$1, %rdi
	mov	$message, %rsi
	mov	$16, %rdx
	syscall

	# exit the program
	movq	$60, %rax
	xor	%rdi, %rdi
	syscall

	.data
message:	.ascii "GONZAGABULLDOGS\n"
