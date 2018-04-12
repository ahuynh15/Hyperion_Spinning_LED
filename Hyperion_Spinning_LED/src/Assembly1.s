.section ".data"
.equ	U2X0,1
.equ	UBRR0L,0xC4
.equ	UBRR0H,0xC5
.equ	UCSR0A,0xC0
.equ	UCSR0B,0xC1
.equ	UCSR0C,0xC2
.equ	UDR0,0xC6
.equ	RXC0,0x07
.equ	UDRE0,0x05

.global ASCII

.section ".text"
.global UART_Get
UART_Get:
	lds		r16,UCSR0A
	sbrs	r16,RXC0
	rjmp	UART_Get
	lds		r16,UDR0
	sts		ASCII,r16
	ret		