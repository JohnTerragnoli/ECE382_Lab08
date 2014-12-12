//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
// Name:	JP Terragnoli
// File:	main.c
// Date:	Fall 2014
// Purp:	Sensing objects around the robot.  Lights up left,
//			center, and right LEDs respectively.
//-----------------------------------------------------------------

#include "msp430g2553.h"
#include "A_header.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {


//starts the car moving forward.
	moveForward();

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0|BIT6;												// Set the red LED as output

	initMotors();

	while(1) {


//conditions for when to move forward
		if(leftSensor()==CLOSE_WALL&&rightSensor()==CLOSE_WALL&&centerSensor()==SPACE){
				moveForward();

		}

		//conditions for when to pivot left
		if(leftSensor()==SPACE&&rightSensor()==CLOSE_WALL&&centerSensor()==CLOSE_WALL){
			turnLeft();
			leftOnBackward();
		}

		//conditions for when to pivot right.
		if(leftSensor()==CLOSE_WALL&&rightSensor()==SPACE&&centerSensor()==CLOSE_WALL){
			turnRight();
			rightOnBackward();
		}

	} // end infinite loop

} // end main
