section .text
global _ft_abs
_ft_abs:

.main:
	mov rax, rdi
	cmp rax, 0
	jl .neg
	ret
.neg:
	neg rax
	ret
