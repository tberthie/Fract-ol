section .text
global _ft_strcmp
extern _ft_strlen
_ft_strcmp:

.main:
	push rdi
	push rsi
	call _ft_strlen
	pop rsi
	pop rdi
	inc rax
	mov rcx, rax
	repe cmpsb
	je .ok
	mov rax, 1
	ret
.ok:
	mov rax, 0
	ret
