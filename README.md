ECE382_Lab08
============

#Prelab

![alt tag](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Photos/Prelab/Flowchart.JPG "Lab08 flowchart")



**Things to Remember**

1. Try to use the same maze as where distances were measured.  This will help with shadows and performance of the car
2. Use the distances recorded in Lab07 to determine how far the car will turn in the other direction.  There should be different "rings" which each require a different action if crossed.  
3. Each ring will respond with a pulse in the appropriate direction.  The length of the pulse will be determined by how close the boundary is to the robot.  
4. With the outer rings, the car should still be moving forward while turning.  
5. If this "ring" theory proves to be too difficult, then I will just have one ring, and will return true/false for the sensing methods.  


**Pseudocode**

```
//initialize the MSP430
//initialize the sensors
//initialize the motors
//make sure to create methods for the above processess. 

while(1){
//initialize variables for distanceLeft, distanceCenter, and distanceLeft.
//call the methods for sensing, have them return values for the above variables.


//Do the actual comparing and decision making.  
//if right and left below threshold, center is not, move forward.
//if right and center below threshold, left is not, turn left.
//if left and center below threshold, right is not, turn right.  
//if right and left above threshold, center is not, turn right.
//if right and center above threshold, left is not, move forward.
//if left and center above threshold, right is not, move forward.  
//if nothing below threshold, move forward.  
//if right below inner ring and left is not, center is not, pulse left
//if left below inner ring and right is not, center is not, pulse right

}

```

#Required Functionality
##Building Process

1. I began with the code for basic functionality in Lab07.  This code made the LEDs light up when sensors on their respective sides lit up.  This would happen when a certain voltage was provided by the robot sensors.  This voltage was provided in analog (obviously) and it is converted into digital by the MSP430.  These digital representations of the incoming voltage can be used to determine how far away the object is being picked up by the sensor.  
2. Next, I used my data from A Functionality in Lab07, where I characterized the strength each sensor recieves at certain distances.  I used the "6 inch away" distance, which is about the amount of space on either side of the car when it is riding straight down the middle of the first maze hallway.  I made this voltage the threshold voltage, or a value to be compared to and decide an action.  
3. Next, I made the sensor methods for left, center, and right from lab07 return char types.  These char types were 0 and 1 for SPACE and WALL respectively.  When the voltage supplied to the MSP430 is above the threshold, that method for that side will respond with a "WALL" or a 1.  Back in the main method, I planned to make if statements using these returned values from the methods to determine which motors to turn on when.  
4. Next, I created the if statements.  I only made 3, conditions for when to turn left, right, and go straight.  For each if statement I checked all three directions to see if they were "WALL" or "SPACE". For example, if the left side was with a wall and the center was in front of a wall, and the right was with SPACE, then the computer would call the "turnRight()" method.  
5. After applying these changes, I was able to get Basic Functionality fairly easily.  I have it on recording; there is a link below.  I just had to make sure that the robot started in the middle and that it was facing relatively straight.  
This was achieved on 12/11/14 at 2146.  The video can be seen [here](https://www.youtube.com/watch?v=71__KVbQkKA&feature=youtu.be). 

Code used to achieve this functionality:
 
[Main.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_Functionality.c)

[header.h](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_header.hs)

[implementation.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_imp.c)


#B Functionality



This was achieved on 12/12/14 at 0541.  The video can be seen [here](https://www.youtube.com/watch?v=4BudPom_3LY&feature=youtu.be). 

Code used to achieve this functionality:
 
[Main.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_Functionality.c)

[header.h](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_header.hs)

[implementation.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_imp.c)  

#A Functionality
This was achieved on 12/12/14 at 0644.  This video can be seen [here](https://www.youtube.com/watch?v=EWXs4pQ-Gy8&feature=youtu.be). 

Code used to achieve this functionality:
 
[Main.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_Functionality.c)

[header.h](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_header.hs)

[implementation.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab08/master/1.%20Code/A_imp.c)


#Documentation:

##Prelab:
  none
