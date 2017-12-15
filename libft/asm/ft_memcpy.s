section .text
global _ft_memcpy
_ft_memcpy:

.main:
	mov r8, rdi
	mov rcx, rdx
	mov rax, rsi
	cld
	rep movsb
	mov rax, r8
	ret

