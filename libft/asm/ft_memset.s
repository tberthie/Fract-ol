section .text
global _ft_memset
_ft_memset:

.main:
	mov r8, rdi
	push r8
	mov rcx, rsi
	mov rax, rdx
	cld
	rep stosb
	pop r8
	mov rax, r8
	ret
