%define SYSCALL(nb)		0x2000000 | nb

section .text
global _ft_puts
_ft_puts:

.main:
	mov ecx, 0
	lea rsi, [rdi]
	mov rax, SYSCALL(4)
	mov rdi, 1
	mov rdx, 0

.loop:
	cmp byte [rsi+rdx], 1
	jl .ret
	inc rdx
	jmp .loop

.ret:
	mov byte [rsi+rdx], 10
	inc rdx
	syscall
	mov rax, 1
	ret
