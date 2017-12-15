%define SYSCALL(nb)		0x2000000 | nb
%define WRITE			4

%define BUFF_SIZE		64

section .data
	buffer	times BUFF_SIZE db 0

section .text
global _ft_cat
extern _ft_puts
extern _read

_ft_cat:

.main:
	cmp rdi, 0
	jl .ret
	mov r9, rdi
.read:
	mov rdi, r9
	lea rsi, [rel buffer]
	mov rdx, BUFF_SIZE
	push rdi
	call _read
	pop rdi
	cmp rax, 0
	jle .ret
.output:
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, SYSCALL(WRITE)
	push r9
	syscall
	pop r9
	jmp .read
.ret:
	ret
