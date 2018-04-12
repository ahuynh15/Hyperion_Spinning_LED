#include <asf.h>
// Delay Library
#include <util/delay.h>

/*
1. Allow the user to specify the length of the input and provide characters
2. Loop through the characters and display each letter in the display
*/

// Variables
char* message = "HELLO"; // This variable will store the message that will be displayed

// Constants
const double DELAY_MS = 10000.00; // Adjust this variable to adjust the delay between each frame

// Delays the program if needed
void delay () {
	_delay_ms(DELAY_MS);
}

// Displays the character with the LED
// For each "frame", change the LEDs to the new pattern
// Each frame is given in hex
void displayCharacter (char character) {
	
	//Look for the pattern for the character the user wants to display
	switch (character)
	{
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
			PORTD = 0x7F;
			delay();
			PORTD = 0x24;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x36;
			delay();
			break;
		case 'C':
			//3D 41 41 41 22
			PORTD = 0x3D;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x22;
			delay();
			break;
		case 'D':
			//7F 41 41 41 3D
			PORTD = 0x7F;
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
			PORTD = 0x7F;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			break;
		case 'G':
			//3D 41 49 49 2D
			PORTD = 0x3D;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x2D;
			delay();
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
			PORTD = 0x41;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x7F;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x41;
			delay();
			break;
		case 'J':
			//02 01 01 01 7D
			PORTD = 0x02;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x7D;
			delay();
			break;
		case 'K':
			//7F 08 14 22 41
			PORTD = 0x7F;
			delay();
			PORTD = 0x08;
			delay();
			PORTD = 0x14;
			delay();
			PORTD = 0x22;
			delay();
			PORTD = 0x41;
			delay();
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
			PORTD = 0x7F;
			delay();
			PORTD = 0x20;
			delay();
			PORTD = 0x18;
			delay();
			PORTD = 0x20;
			delay();
			PORTD = 0x7F;
			delay();
			break;
		case 'N':
			//7F 10 08 04 7F
			PORTD = 0x7F;
			delay();
			PORTD = 0x10;
			delay();
			PORTD = 0x08;
			delay();
			PORTD = 0x04;
			delay();
			PORTD = 0x7F;
			delay();
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
			PORTD = 0x7F;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x30;
			delay();
			break;
		case 'Q':
			//3D 41 45 43 3F
			PORTD = 0x3D;
			delay();
			PORTD = 0x41;
			delay();
			PORTD = 0x45;
			delay();
			PORTD = 0x43;
			delay();
			PORTD = 0x3F;
			delay();
			break;
		case 'R':
			//7F 48 48 48 37
			PORTD = 0x7F;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x37;
			delay();
			break;
		case 'S':
			//31 49 49 49 46
			PORTD = 0x31;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x46;
			delay();
			break;
		case 'T':
			//40 40 7F 40 40
			PORTD = 0x40;
			delay();
			PORTD = 0x40;
			delay();
			PORTD = 0x7F;
			delay();
			PORTD = 0x40;
			delay();
			PORTD = 0x40;
			delay();
			break;
		case 'U':
			//7D 01 01 01 7D
			PORTD = 0x7D;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x7D;
			delay();
			break;
		case 'V':
			//7C 02 01 02 7C
			PORTD = 0x7C;
			delay();
			PORTD = 0x02;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x02;
			delay();
			PORTD = 0x7C;
			delay();
			break;
		case 'W':
			//7F 02 0C 02 7F
			PORTD = 0x7F;
			delay();
			PORTD = 0x02;
			delay();
			PORTD = 0x0C;
			delay();
			PORTD = 0x02;
			delay();
			PORTD = 0x7F;
			delay();
			break;
		case 'X':
			//63 14 08 14 63
			PORTD = 0x63;
			delay();
			PORTD = 0x14;
			delay();
			PORTD = 0x08;
			delay();
			PORTD = 0x14;
			delay();
			PORTD = 0x63;
			delay();
			break;
		case 'Y':
			//60 18 07 18 60
			PORTD = 0x60;
			delay();
			PORTD = 0x18;
			delay();
			PORTD = 0x07;
			delay();
			PORTD = 0x18;
			delay();
			PORTD = 0x60;
			delay();
			break;
		case 'Z':
			//43 45 49 51 61
			PORTD = 0x43;
			delay();
			PORTD = 0x45;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x51;
			delay();
			PORTD = 0x61;
			delay();
			break;
		case ' ':
			//00 00 00 00 00
			PORTD = 0x00;
			delay();
			PORTD = 0x00;
			delay();
			PORTD = 0x00;
			delay();
			PORTD = 0x00;
			delay();
			PORTD = 0x00;
			delay();
			break;
		case '.':
			//00 01 00 - Special Case (3 frames)
			PORTD = 0x00;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x00;
			delay();
			break;
		case '?':
			//30 40 45 48 30
			PORTD = 0x30;
			delay();
			PORTD = 0x40;
			delay();
			PORTD = 0x45;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x30;
			delay();
			break;
		case '!':
			//00 7E 00 - Special Case (3 frames)
			PORTD = 0x00;
			delay();
			PORTD = 0x7E;
			delay();
			PORTD = 0x00;
			delay();
			break;
		case '0':
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
		case '1':
			//11 21 7F 01 01
			PORTD = 0x11;
			delay();
			PORTD = 0x21;
			delay();
			PORTD = 0x7F;
			delay();
			PORTD = 0x01;
			delay();
			PORTD = 0x01;
			delay();
			break;
		case '2':
			//31 43 45 49 31
			PORTD = 0x31;
			delay();
			PORTD = 0x43;
			delay();
			PORTD = 0x45;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x31;
			delay();
			break;
		case '3':
			//22 49 49 49 36
			PORTD = 0x22;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x36;
			delay();
			break;
		case '4':
			//78 08 08 08 7F
			PORTD = 0x78;
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
		case '5':
			//79 49 49 49 46
			PORTD = 0x79;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x46;
			delay();
			break;
		case '6':
			//3D 49 49 49 26
			PORTD = 0x3D;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x26;
			delay();
			break;
		case '7':
			//41 42 44 48 70
			PORTD = 0x41;
			delay();
			PORTD = 0x42;
			delay();
			PORTD = 0x44;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x70;
			delay();
			break;
		case '8':
			//36 49 49 49 36
			PORTD = 0x36;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x49;
			delay();
			PORTD = 0x36;
			delay();
			break;
		case '9':
			//30 48 48 48 3F
			PORTD = 0x30;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x48;
			delay();
			PORTD = 0x3F;
			delay();
			break;
	}

	// Add an empty frame to separate letters from each other
	PORTD = 0x00;
	delay();

}

int main (void)
{
	//Set all pins on PORT D to output
	DDRD = 0xFF;

	//Initialize the board
	board_init();

	//Continuously loop through the characters of the message
	while(1) {
		for(int i = 0; i < sizeof(message)/sizeof(char) ; i++) {
			displayCharacter(message[i]);
		}
	}
}