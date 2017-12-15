section .text
global _ft_strcpy
extern _ft_strlen
extern _ft_memcpy

_ft_strcpy:

.main:
	mov r10, rdi
	mov rdi, rsi
	call _ft_strlen
	mov rdi, r10
	mov rdx, rax
	inc rdx
	call _ft_memcpy
.end:
	ret
