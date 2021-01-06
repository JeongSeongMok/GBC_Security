global    _start
section   .text
strlen:
mov rax,0
.looplabel:
cmp byte [rdi],0
je  .end
inc rdi
inc rax
jmp .looplabel
.end:
ret
_start:
mov       rax, 1
mov       rdi, 1
mov       rsi, message
mov       rdx, 24
syscall
mov       rsi, [rsp+16]
mov       rdi, [rsp+16]
call strlen
mov       rdx, rax
mov       rax, 1
mov       rdi, 1
syscall
mov       rax, 60
xor       rdi, rdi
syscall
section   .data
message:
db   "Hello, World", 10,  "My name is "
