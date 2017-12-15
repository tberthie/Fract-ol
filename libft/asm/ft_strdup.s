section .text
global _ft_strdup
extern _ft_strlen
extern _ft_memcpy
extern _ft_memalloc

_ft_strdup:

.main:
	mov rsi, rdi
	call _ft_strlen
	mov rdx, rax
	mov rdi, rax
	inc rdi
	push rsi
	push rdx
	call _ft_memalloc
	pop rdx
	pop rsi
	mov rdi, rax
	call _ft_memcpy
	ret
