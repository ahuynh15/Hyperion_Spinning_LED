.section ".data"
.equ	EECR,0x1F
.equ	EEDR,0x20
.equ	EEARL,0x21
.equ	EEARH,0x22
.equ	EERE,0
.equ	EEPE,1
.equ	EEMPE,2
.equ	EERIE,3

.global ASCII
.global VALUE
.global EEAH
.global EEAL

.section ".text"
.global UART_Get
UART_Get:
	lds		r16,UCSR0A
	sbrs	r16,RXC0
	rjmp	UART_Get
	lds		r16,UDR0
	sts		ASCII,r16
	ret		

.global EEPROM_Write
EEPROM_Write:      
		sbic    EECR,EEPE
		rjmp    EEPROM_Write
		lds		r18,EEAH
		lds		r17,EEAL 
		lds		r16,VALUE 
		out     EEARH, r18      
		out     EEARL, r17			      
		out     EEDR,r16 
		sbi     EECR,EEMPE
		sbi     EECR,EEPE
		ret 

.global EEPROM_Read
EEPROM_Read:					    
		sbic    EECR,EEPE    
		rjmp    EEPROM_Read
		lds		r18,EEAH
		lds		r17,EEAL
		ldi		r16,0x00   
		out     EEARH, r18   
		out     EEARL, r17		   
		sbi     EECR,EERE
		in      r16,EEDR
		sts		ASCII,r16  
		ret
		.end