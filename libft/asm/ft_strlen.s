section .text
global _ft_strlen
_ft_strlen:

.main:
	mov rcx, -1
	mov rsi, rdi
	mov al, 0
	repne scasb
	sub rdi, rsi
	dec rdi
	mov rax, rdi
	ret
