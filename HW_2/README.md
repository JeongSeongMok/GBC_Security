# 어셈블리어 분석

## `hello.asm` - Hello, Wolrd 출력

```
global    _start // public 개념이다.
section   .text // .text는 main역할을 한다.
    _start:
    mov       rax, 1 // syscall 결정 
    mov       rdi, 1 // syscall로 출력하기 위해 설정
    mov       rsi, message // rsi에서 rdx만큼까지 출력 
    mov       rdx, 13 // rsi의 시작주소 = message의 시작주소부터 13byte까지(rdx)
    syscall
    mov       rax, 60 // syscall 결정 exit
    xor       rdi, rdi // rdi=0 즉 syscall = exit 0
    syscall
section   .data // 변수 선언
    message: // meesage라는 db타입 "Hello, Wolrd" 뒤에 10은 enter 00은 null
    db        "Hello, World", 10
```
<br>

## `strlen.asm` - 글자 수 세기
```
BITS 64

section .text
global _start

    strlen:  // strlen이라는 함수 선언
        mov rax,0      //rax = 0            
        .looplabel:
        cmp byte [rdi],0  //rdi의 0번째 글자부터 0과 비교          
        je  .end  //위의 조건문에서 참이 나오면 .end로가서 strlen 종료              
        inc rdi // rdi+=1                     
        inc rax // ras+=1 (글자 수 카운팅)                    
        jmp .looplabel // (반복문)            
        .end:
        ret                      

    _start:
        mov   rdi, msg // rdi에 msg의 첫글자 주소값 저장        
        call  strlen // strlen 함수 호출
        add   al, '0' // strlen 가 끝나면서 rax가 al에 숫자타입으로 저장되므로 아스키코드를 맞춰주기 위해 '0'을 더해줌               
        mov  [len],al // len에 al 저장            
        mov   rax, 1 // rax=1, syscall 결정           
        mov   rdi, 1 // rdi=1, syscall 출력결정 
        mov   rsi, len // 결과값 첫번째 글자 주소를 rsi에 저장       
        mov   rdx, 2  // rdx=2, rsi에서 rdx만큼까지 출력  
        syscall           
        mov   rax, 60  //syscall을 exit로 하기위해 
        mov   rdi, 0 // syscall = exit 0    
        syscall        

section .data
    msg db "hello",0xA,0   // 0xA = 10 과같음     
    len db 0,0xA  
```