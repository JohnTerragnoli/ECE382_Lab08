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
This was achieved on 12/11/14 at 2146.  The video can be seen [here](https://www.youtube.com/watch?v=71__KVbQkKA&feature=youtu.be). 

#B Functionality
This was achieved on 12/12/14 at 0541.  The video can be seen [here](https://www.youtube.com/watch?v=4BudPom_3LY&feature=youtu.be). 

#A Functionality
This was achieved on 12/12/14 at 0644.  This video can be seen [here](https://www.youtube.com/watch?v=EWXs4pQ-Gy8&feature=youtu.be).  


#Documentation:

##Prelab:
  none
