#include <msp430.h>
#include "A_header.h"

/*
 * implementation.c
 *
 *  Created on: Nov 20, 2014
 *      Author: C16John.Terragnoli
 *      Description: Contains the defintion of the methods to move the car around.
 *      For: Lab06
 *
 *
 *
 *  Updated on: 7 Dec, 2014
 *      Author: C16John.Terragnoli
 *      Description: Contains the defintion of the methods to move the robot car, and
 *      to test when objects are near the sensors.
 */









//__________________________________________________
//Left Sensor
//check if something is to the left.  If so, then turn on the left LED.
//__________________________________________________
char leftSensor(){
	  // Configure P1.3 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT3;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete									// collect that 10-bit value
	if (ADC10MEM > leftStrength)	{
		P1OUT |= BIT0;
		return 1;
	}
	else					{
		P1OUT &= ~BIT0;
		return 0;
	}
}
//__________________________________________________








//__________________________________________________
//Center Sensor
//check if something is straight ahead.  If so, then turn on both LEDs.
//__________________________________________________
char centerSensor(){
	  // Configure P1.4 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT4;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete									// collect that 10-bit value
	if (ADC10MEM > centerStrength)	{
		P1OUT |= BIT0;
		P1OUT |= BIT6;
		return 1;
	}
	else					{
		P1OUT &= ~BIT0;
		P1OUT &= ~BIT6;
		return 0;
	}
}
//__________________________________________________







//__________________________________________________
//Right Sensor
//check if something is to the right.  If so, then turn on the right LED.
//__________________________________________________
char rightSensor(){
	  // Configure P1.5 to be the ADC input
	ADC10CTL0 = 0;											// Turn off ADC subsystem
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
	ADC10AE0 = BIT5;		 								// Make P1.4 analog input
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

	ADC10CTL0 |= ADC10SC;									// Start a conversion
	while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete									// collect that 10-bit value
	if (ADC10MEM > rightStrength)	{
		P1OUT |= BIT6;
		return 1;
	}
	else					{
		P1OUT &= ~BIT6;
		return 0;
	}

}
//__________________________________________________







//__________________________________________________
//INITIALIZE MOTORS
//__________________________________________________
void initMotors(){
	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	TA1CCR0 = 100;						// set signal period

	TA1CCR1 = 45;
	TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

	TA1CCR2 = 55;
	TA1CCTL2 = OUTMOD_3;					// set TACCTL2 to Set / Reset mode
}
//__________________________________________________


























//__________________________________________________
//FUNCTIONALITY FUNCTIONS
//__________________________________________________

/*
 * Goes forward, makes a full left and right turn, then makes
 *a half left and right turn, will eventually move it backwards.
 */
void basicFunctionality(){
	pauseBoth();
	pauseBoth();
	pauseBoth();

	moveBackward();
	halt();
	__delay_cycles(STRAIGHTTIME);

	moveForward();
	__delay_cycles(STRAIGHTTIME);
	fullTurnLeft();
	moveForward();
	__delay_cycles(STRAIGHTTIME);
	fullTurnRight();
	moveForward();
	__delay_cycles(STRAIGHTTIME);
	halfTurnLeft();
	moveForward();
	__delay_cycles(STRAIGHTTIME);
	halfTurnRight();
	moveForward();
	__delay_cycles(2*STRAIGHTTIME);
}
//__________________________________________________
//__________________________________________________















//__________________________________________________
//REQUIREMENT FUNCTIONS
//__________________________________________________
/*
 * Moves forward indefinitely
 */
void moveForward(){
	bothOn();
}




/*
 * Move it backwards.  DOES NOT WORK
 */
void moveBackward(){
	bothOnBackward();
}




/*
 * Turns the robot 90 to the right.
 */
void fullTurnRight(){
    turnRight();
    __delay_cycles(1.5*STRAIGHTTIME);
}



/*
 * Turns the robot 45 to the right.
 */
void halfTurnRight(){
    turnRight();
    __delay_cycles(HALFTURN);
}



/*
 * Turns the robot 90 to the left.
 */
void fullTurnLeft(){
   turnLeft();
    __delay_cycles(FULLTURN);
}



/*
 * Turns the robot 45 to the left.
 */
void halfTurnLeft(){
	turnLeft();
    __delay_cycles(HALFTURN);
}

/*
 * Stops the robot, whatever direction it is moving.
 */
void halt(){
	stopBoth();
	stopBothBackward();
}
//__________________________________________________
//__________________________________________________






























//_________________________________________________________________
//MEDIUM COMMANDS
//_________________________________________________________________

/*
 * Makes both motors move forwards.
 */
void bothOn(){
	stopBothBackward();
	rightOn();
	leftOn();
}


/*
 * Makes both motors move backwards!
 */
void bothOnBackward(){
	stopBoth();
	leftOnBackward();
	rightOnBackward();
}


/*
 * Stops the car until further notice.
 */
void stopBoth(){
    stopRight();
    stopLeft();
    __delay_cycles(STRAIGHTTIME);
    //rightOn();
    //leftOn();
}


/**
 * Stops the backwards movement.
 */
void stopBothBackward(){
	stopLeftBackward();
	stopRightBackward();
}





/*
 * Pauses the car for one second
 */
void pauseBoth(){
	stopRight();
	stopLeft();
	 __delay_cycles(STRAIGHTTIME);
	rightOn();
	leftOn();
}


/*
 * Sets the car up for any kind of right turn
 */
void turnRight(){
	leftOn();
	stopRight();
}


/*
 * Sets the care up for any kind of left turn.
 */
void turnLeft(){
	rightOn();
	stopLeft();
}
//_________________________________________________________________
//_________________________________________________________________



























//_________________________________________________________________
//VERY BASIC FUNCTIONS
//_________________________________________________________________
/*
 * Stops the right wheen until further notice.
 */
void stopRight(){
    P2DIR &= ~BIT4;
    P2SEL &= ~BIT4;
}



/*
 * Stops the left wheel until further notice.
 */
void stopLeft(){
    P2DIR &= ~BIT2;
    P2SEL &= ~BIT2;
}

/**
 * Stops the right wheel from moving backwards.
 */
void stopRightBackward(){
	P2DIR &= ~BIT5;
	P2SEL &= ~BIT5;
}


/*
 * Stops the left wheel from moving backwards.
 */
void stopLeftBackward(){
	P2DIR &= ~BIT1;
	P2SEL &= ~BIT1;
}



/*
 * Starts the right wheel until further notice.
 */
void rightOn(){
    P2DIR |= BIT4;
    P2SEL |= BIT4;
}


/*
 * Starts the left wheel until further notice.
 */
void leftOn(){
    P2DIR |= BIT2;
    P2SEL |= BIT2;
}

/*
 * Makes the left wheel turn backwards.
 */
void leftOnBackward(){
	P2DIR |=BIT1;
	P2SEL |=BIT1;
}

/*
 * Makes the right wheel turn backwards.
 */
void rightOnBackward(){
	P2DIR |=BIT5;
	P2SEL |=BIT5;
}


//_________________________________________________________________
//_________________________________________________________________
