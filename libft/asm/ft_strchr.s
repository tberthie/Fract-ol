section .text
global _ft_strchr
extern _ft_strlen

_ft_strchr :

.main:
	push rsi
	push rdi
	call _ft_strlen
	pop rdi
	pop rsi
	cmp rsi, 0
	je .end
	mov rcx, rax
	mov rax, rsi
	cld
	repne scasb
	test rcx, rcx
	jz .ret
	mov rax, rdi
	dec rax
	ret
.end:
	add rdi, rax
	mov rax, rdi
	ret
.ret:
	mov rax, 0
	ret
