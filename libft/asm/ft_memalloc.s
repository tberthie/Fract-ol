section .text
global _ft_memalloc
extern _ft_memset
extern _ft_m

_ft_memalloc:

.main:
	call _ft_m
	mov rsi, rdi
	mov rdi, rax
	mov rdx, 0
	call _ft_memset
	ret
