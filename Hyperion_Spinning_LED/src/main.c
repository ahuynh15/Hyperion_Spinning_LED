#include <asf.h>
// Delay Library
#include <util/delay.h>

/*
1. Allow the user to specify the length of the input and provide characters
2. Loop through the characters and display each letter in the display
*/

// CONSTANTS
const double DELAY_MS = 100.00;

// Delays the program if needed
void delay () {
	_delay_ms(DELAY_MS);
}

// Displays the character with the LED
void displayCharacter (char character) {
	switch (character)
	{
		//F0 F1 F2 F3 F4 - Frame Order (given in hex)
		case 'A':
		//1F 24 44 24 1F
		PORTD = 0x1F;
		delay();
		PORTD = 0x24;
		delay();
		PORTD = 0x44;
		delay();
		PORTD = 0x24;
		delay();
		PORTD = 0x1F;
		delay();
		break;
		case 'B':
		//7F 49 49 49 36
		break;
		case 'C':
		//3D 41 41 41 22
		break;
		case 'D':
		//7F 41 41 41 3D
		break;
		case 'E':
		//7F 49 49 49 49
		PORTD = 0x7F;
		delay();
		PORTD = 0x49;
		delay();
		PORTD = 0x49;
		delay();
		PORTD = 0x49;
		delay();
		PORTD = 0x49;
		delay();
		break;
		case 'F':
		//7F 48 48 48 48
		break;
		case 'G':
		//3D 41 49 49 2D
		break;
		case 'H':
		//7F 08 08 08 7F
		PORTD = 0x7F;
		delay();
		PORTD = 0x08;
		delay();
		PORTD = 0x08;
		delay();
		PORTD = 0x08;
		delay();
		PORTD = 0x7F;
		delay();
		break;
		case 'I':
		//41 41 7F 41 41
		break;
		case 'J':
		//02 01 01 01 7D
		break;
		case 'K':
		//7F 08 14 22 41
		break;
		case 'L':
		//7F 01 01 01 01
		PORTD = 0x7F;
		delay();
		PORTD = 0x01;
		delay();
		PORTD = 0x01;
		delay();
		PORTD = 0x01;
		delay();
		PORTD = 0x01;
		delay();
		break;
		case 'M':
		//7F 20 18 20 7F
		break;
		case 'N':
		//7F 10 08 04 7F
		break;
		case 'O':
		//3D 41 41 41 3D
		PORTD = 0x3D;
		delay();
		PORTD = 0x41;
		delay();
		PORTD = 0x41;
		delay();
		PORTD = 0x41;
		delay();
		PORTD = 0x3D;
		delay();
		break;
		case 'P':
		//7F 48 48 48 30
		break;
		case 'Q':
		//3D 41 45 43 3F
		break;
		case 'R':
		//7F 48 48 48 37
		break;
		case 'S':
		//31 49 49 49 46
		break;
		case 'T':
		//40 40 7F 40 40
		break;
		case 'U':
		//7D 01 01 01 7D
		break;
		case 'V':
		//7C 02 01 02 7C
		break;
		case 'W':
		//7F 02 0C 02 7F
		break;
		case 'X':
		//63 14 08 14 63
		break;
		case 'Y':
		//60 18 07 18 60
		break;
		case 'Z':
		//43 45 49 51 61
		break;
		case ' ':
		//00 00 00 00 00
		break;
		case '.':
		//00 00 01 00 00
		break;
		case '?':
		//30 40 45 48 30
		break;
		case '!':
		//00 00 7E 00 00
		break;
		case '0':
		//3D 41 41 41 3D
		break;
		case '1':
		//11 21 7F 01 01
		break;
		case '2':
		//31 43 45 49 31
		break;
		case '3':
		//22 49 49 49 36
		break;
		case '4':
		//78 08 08 08 7F
		break;
		case '5':
		//79 49 49 49 46
		break;
		case '6':
		//3D 49 49 49 26
		break;
		case '7':
		//41 42 44 48 70
		break;
		case '8':
		//36 49 49 49 36
		break;
		case '9':
		//30 48 48 48 3F
		break;
	}
}

int main (void)
{
	//Set all pins on PORT D to output
	DDRD = 0xFF;
	board_init();
	while(1) {
		displayCharacter('H');
		displayCharacter('E');
		displayCharacter('L');
		displayCharacter('L');
		displayCharacter('O');
	}
}