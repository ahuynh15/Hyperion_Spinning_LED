#define F_CPU 16000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#include <asf.h>
// Delay Library
#include <util/delay.h>
#include <avr/eeprom.h>

unsigned char ASCII;

void UART_Get(void);
void delay(void);
void displayCharacter(char);
void get_input(char*, int);

//USART Functions
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);

/*
1. Allow the user to specify the length of the input and provide characters
2. Loop through the characters and display each letter in the display
*/

// Constants
const double DELAY_MS = 10.00; // Adjust this variable to adjust the delay between each frame

int main (void)
{
	int TEXT_LENGTH = 5;
	char TEXT[TEXT_LENGTH];
	//Set all pins on PORT B and C to output
	DDRB = 0b00111111;
	DDRC = 0b00000001;

	eeprom_read_block((void *)&TEXT, (const void *)0, TEXT_LENGTH); //reads the eeprom on load

	//Initialize the board
	board_init();
	//Initialize the USART
	USART_init();
	ASCII = '\0';
	while(1) {
 		ASCII = USART_receive();
 		if(ASCII == '`'){
 			USART_putstring("Type 5 characters\n");
 			get_input(TEXT, TEXT_LENGTH);
			USART_putstring("\n\rWord set to ");
			for(int i = 0; i < TEXT_LENGTH; i++){
				USART_send(TEXT[i]); // putstring didn't like char arrays
			}
			USART_putstring("\n\r");
 		}
		for(int i = 0; i < TEXT_LENGTH; i++){
			displayCharacter(TEXT[i]);
		}
	}
}

// Delays the program if needed
void delay () {
	_delay_ms(DELAY_MS);
}

// Displays the character with the LED
// For each "frame", change the LEDs to the new pattern
// Each frame is given in hex
void displayCharacter (char character) {
	//debug code
	//USART_send(character);
	//USART_putstring("\n\r");
	//Look for the pattern for the character the user wants to display

	unsigned int numFrames = 5;
	unsigned int currentFrameValue = 0;
	unsigned int frames[5] = {0x00,0x00,0x00,0x00,0x00}; 

	switch (character)
	{
		case 'A' | 'a':
			//1F 24 44 24 1F
			frames[0] = 0x1F;
			frames[1] = 0x24;
			frames[2] = 0x44;
			frames[3] = 0x24;
			frames[4] = 0x1F;
			break;
		case 'B' | 'b':
			//7F 49 49 49 36
			frames[0] = 0x7F;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x36;
			break;
		case 'C' | 'c':
			//3E 41 41 41 22
			frames[0] = 0x3E;
			frames[1] = 0x41;
			frames[2] = 0x41;
			frames[3] = 0x41;
			frames[4] = 0x22;
			break;
		case 'D' | 'd':
			//7F 41 41 41 3E
			frames[0] = 0x7F;
			frames[1] = 0x41;
			frames[2] = 0x41;
			frames[3] = 0x41;
			frames[4] = 0x3E;
			break;
		case 'E' | 'e':
			//7F 49 49 49 49
			frames[0] = 0x7F;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x49;
			break;
		case 'F' | 'f':
			//7F 48 48 48 48
			frames[0] = 0x7F;
			frames[1] = 0x48;
			frames[2] = 0x48;
			frames[3] = 0x48;
			frames[4] = 0x48;
			break;
		case 'G' | 'g':
			//3E 41 49 49 2E
			frames[0] = 0x3E;
			frames[1] = 0x41;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x2E;
			break;
		case 'H' | 'h':
			//7F 08 08 08 7F
			frames[0] = 0x7F;
			frames[1] = 0x08;
			frames[2] = 0x08;
			frames[3] = 0x08;
			frames[4] = 0x7F;
			break;
		case 'I' | 'i':
			//41 41 7F 41 41
			frames[0] = 0x41;
			frames[1] = 0x41;
			frames[2] = 0x7F;
			frames[3] = 0x41;
			frames[4] = 0x41;
			break;
		case 'J' | 'j':
			//02 01 01 01 7E
			frames[0] = 0x02;
			frames[1] = 0x01;
			frames[2] = 0x01;
			frames[3] = 0x01;
			frames[4] = 0x7E;
			break;
		case 'K' | 'k':
			//7F 08 14 22 41
			frames[0] = 0x7F;
			frames[1] = 0x08;
			frames[2] = 0x14;
			frames[3] = 0x22;
			frames[4] = 0x41;
		case 'L' | 'l':
			//7F 01 01 01 01
			frames[0] = 0x7F;
			frames[1] = 0x01;
			frames[2] = 0x01;
			frames[3] = 0x01;
			frames[4] = 0x01;
			break;
		case 'M' | 'm':
			//7F 20 18 20 7F
			frames[0] = 0x7F;
			frames[1] = 0x20;
			frames[2] = 0x18;
			frames[3] = 0x20;
			frames[4] = 0x7F;
			break;
		case 'N' | 'n':
			//7F 10 08 04 7F
			frames[0] = 0x7F;
			frames[1] = 0x10;
			frames[2] = 0x08;
			frames[3] = 0x04;
			frames[4] = 0x7F;
			break;
		case 'O' | 'o':
			//3E 41 41 41 3E
			frames[0] = 0x3E;
			frames[1] = 0x41;
			frames[2] = 0x41;
			frames[3] = 0x41;
			frames[4] = 0x3E;
			break;
		case 'P' | 'p':
			//7F 48 48 48 30
			frames[0] = 0x7F;
			frames[1] = 0x48;
			frames[2] = 0x48;
			frames[3] = 0x48;
			frames[4] = 0x30;
			break;
		case 'Q' | 'q':
			//3E 41 45 43 3F
			frames[0] = 0x3E;
			frames[1] = 0x41;
			frames[2] = 0x45;
			frames[3] = 0x43;
			frames[4] = 0x3F;
			break;
		case 'R' | 'r':
			//7F 48 48 48 37
			frames[0] = 0x7F;
			frames[1] = 0x48;
			frames[2] = 0x48;
			frames[3] = 0x48;
			frames[4] = 0x37;
			break;
		case 'S' | 's':
			//31 49 49 49 46
			frames[0] = 0x31;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x46;
			break;
		case 'T' | 't':
			//40 40 7F 40 40
			frames[0] = 0x40;
			frames[1] = 0x40;
			frames[2] = 0x7F;
			frames[3] = 0x40;
			frames[4] = 0x40;
			break;
		case 'U' | 'u':
			//7E 01 01 01 7E
			frames[0] = 0x7E;
			frames[1] = 0x01;
			frames[2] = 0x01;
			frames[3] = 0x01;
			frames[4] = 0x7E;
			break;
		case 'V' | 'v':
			//7C 02 01 02 7C
			frames[0] = 0x7C;
			frames[1] = 0x02;
			frames[2] = 0x01;
			frames[3] = 0x02;
			frames[4] = 0x7C;
			break;
		case 'W' | 'w':
			//7F 02 0C 02 7F
			frames[0] = 0x7F;
			frames[1] = 0x02;
			frames[2] = 0x0C;
			frames[3] = 0x02;
			frames[4] = 0x7F;
			break;
		case 'X' | 'x':
			//63 14 08 14 63
			frames[0] = 0x63;
			frames[1] = 0x14;
			frames[2] = 0x08;
			frames[3] = 0x14;
			frames[4] = 0x63;
			break;
		case 'Y' | 'y':
			//60 18 07 18 60
			frames[0] = 0x60;
			frames[1] = 0x18;
			frames[2] = 0x07;
			frames[3] = 0x18;
			frames[4] = 0x60;
			break;
		case 'Z' | 'z':
			//43 45 49 51 61
			frames[0] = 0x43;
			frames[1] = 0x45;
			frames[2] = 0x49;
			frames[3] = 0x51;
			frames[4] = 0x61;
			break;
		case ' ':
			//00 00 00 00 00
			frames[0] = 0x00;
			frames[1] = 0x00;
			frames[2] = 0x00;
			frames[3] = 0x00;
			frames[4] = 0x00;
			break;
		case '.':
			//00 01 00 - Special Case (3 frames)
			frames[0] = 0x00;
			frames[1] = 0x01;
			frames[2] = 0x00;
			numFrames = 3;
			break;
		case '?':
			//30 40 45 48 30
			frames[0] = 0x30;
			frames[1] = 0x40;
			frames[2] = 0x45;
			frames[3] = 0x48;
			frames[4] = 0x30;
			break;
		case '!':
			//00 7D 00 - Special Case (3 frames)
			frames[0] = 0x00;
			frames[1] = 0x7D;
			frames[2] = 0x00;
			numFrames = 3;
			break;
		case '0':
			//3E 41 41 41 3E
			frames[0] = 0x3E;
			frames[1] = 0x41;
			frames[2] = 0x41;
			frames[3] = 0x41;
			frames[4] = 0x3E;
			break;
		case '1':
			//11 21 7F 01 01
			frames[0] = 0x11;
			frames[1] = 0x21;
			frames[2] = 0x7F;
			frames[3] = 0x01;
			frames[4] = 0x01;
			break;
		case '2':
			//31 43 45 49 31
			frames[0] = 0x31;
			frames[1] = 0x43;
			frames[2] = 0x45;
			frames[3] = 0x49;
			frames[4] = 0x31;
			break;
		case '3':
			//22 49 49 49 36
			frames[0] = 0x22;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x36;
			break;
		case '4':
			//78 08 08 08 7F
			frames[0] = 0x78;
			frames[1] = 0x08;
			frames[2] = 0x08;
			frames[3] = 0x08;
			frames[4] = 0x7F;
			break;
		case '5':
			//79 49 49 49 46
			frames[0] = 0x79;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x46;
			break;
		case '6':
			//3E 49 49 49 26
			frames[0] = 0x3E;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x26;
			break;
		case '7':
			//41 42 44 48 70
			frames[0] = 0x41;
			frames[1] = 0x42;
			frames[2] = 0x44;
			frames[3] = 0x48;
			frames[4] = 0x70;
			break;
		case '8':
			//36 49 49 49 36
			frames[0] = 0x36;
			frames[1] = 0x49;
			frames[2] = 0x49;
			frames[3] = 0x49;
			frames[4] = 0x36;
			break;
		case '9':
			//30 48 48 48 3F
			frames[0] = 0x30;
			frames[1] = 0x48;
			frames[2] = 0x48;
			frames[3] = 0x48;
			frames[4] = 0x3F;
			break;
	}


	//Go through each of the frames and output them on the ports
	for(int i = 0; i < numFrames; i++) {
		currentFrameValue = frames[i];
		//No shift is needed for the PORTB
		PORTB = currentFrameValue;
		//Shift the binary value to the right by 6 for PORTC
		PORTC = currentFrameValue >> 6;
		delay();
	}

	// Add an empty frame to separate letters from each other
	PORTB = 0x00;
	PORTC = 0x00;
	delay();

}

void get_input(char * text, int length){
	for(int i = 0; i < length; i++){
		ASCII = '\0';
		while(ASCII == '\0' || ASCII == '`'){
			ASCII = USART_receive();
		}
		text[i] = ASCII;
		USART_send(ASCII);
		eeprom_write_byte((uint8_t *)i, ASCII);
	}
	return;
}

void USART_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void){
	if((UCSR0A & (1<<RXC0))){
		return UDR0;
	}
	return '\0';
}

void USART_send(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void USART_putstring(char* StringPtr){
	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
		StringPtr++;
	}
}