section .text
global _ft_strcat

_ft_strcat:

.main:
	mov rbx, rsi
	mov rax, rdi
	mov rcx, 0
.end:
	cmp byte [rdi], 0
	je .len
	inc rdi
	jmp .end
.len:
	cmp byte [rbx], 0
	je .ret
	inc rcx
	inc rbx
	jmp .len
.ret:
	inc rcx
	rep movsb
	ret
