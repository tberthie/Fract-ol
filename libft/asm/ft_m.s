section .text
global _ft_m
extern _malloc

_ft_m:

.main:
	push rdi
	call _malloc
	pop rdi
	je .ko
	ret
.ko:
	mov rdi, -1
	mov rax, 0x2000001
	syscall
	ret
