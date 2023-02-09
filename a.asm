data segment
    num1 dw 1234h;
    num2 dw 4512h;
    sum dd 00000000h;
    carry db 00h;
data ends 

code segment 
    assume cs: code , ds: data
    
    start: mov ax,data
    mov ds,ax 
    mov ax, num1 
    mov bx , num2
    add bx 
    mov sum, ax
    
    
    
code ends
end start 