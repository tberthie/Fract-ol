section .text
global _ft_memcmp
_ft_memcmp:

.main:
	mov rcx, rdx
	repe cmpsb
	je .ok
	mov rax, 1
	ret
.ok:
	mov rax, 0
	ret
