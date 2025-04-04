//QUESTION:The Rover, Brick, has a simple task — detect a Red circle marker on the ground, reach its location, and perform a 360-degree turn.

//Caution: You will only get points if the center of the rover is exactly above the marker when performing the turn.
/*
What Happened:
The camera is mounted on top of the rover at the front and top position of the rover.
Brick started from the designated starting line. After covering some distance, its camera detected the marker at coordinates (x, y, -60).
The rover navigated towards the marker and performed the 360-degree turn.
However, instead of turning at the marker, it performed the turn 55 cm behind the actual marker.
Your Task:
Write a program to adjust the rover’s navigation system so that it reaches the correct position and precisely performs the 360-degree turn on the marker.
Hint : 
Try taking a different frame of reference.
Input:
The camera’s detection coordinates (x, y, -60)
Output:
New Position (x_final, y_final, z_final) of the marker w.r.t. new frame of  reference
Write a function to get the distance between the marker and camera before and after changing the navigation reference.
*/

//solution of the ROVER NAVIGATION.

#include <stdio.h>
#include <math.h>

// Function to calculate Euclidean distance
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to adjust the reference frame using trigonometric correction in 2D
void adjustReferenceFrame(double x, double y, double total_offset, double *x_final, double *y_final) {
    double theta = atan2(y, x); // Angle in XY plane
    
    double x_offset = total_offset * cos(theta); // X component
    double y_offset = total_offset * sin(theta); // Y component
    
    *x_final = x + x_offset; // Adjust x position
    *y_final = y + y_offset; // Adjust y position
}

int main() {
    // Given coordinates of the marker in the old reference frame
    double x = 10.0, y = 20.0;
    double camera_x = 0.0, camera_y = 0.0; // Camera's original position
    double total_offset = 55.0; // Rover is stopping 55 cm behind the marker
    
    // Calculate initial distance between camera and marker
    double initialDistance = calculateDistance(camera_x, camera_y, x, y);
    
    // New marker position in adjusted reference frame
    double x_final, y_final;
    adjustReferenceFrame(x, y, total_offset, &x_final, &y_final);
    
    // Calculate new distance between camera and adjusted marker position
    double finalDistance = calculateDistance(camera_x, camera_y, x_final, y_final);
    
    // Output results
    printf("Initial Marker Position: (%.2f, %.2f)\n", x, y);
    printf("New Marker Position: (%.2f, %.2f)\n", x_final, y_final);
    printf("Initial Distance: %.2f cm\n", initialDistance);
    printf("Final Distance: %.2f cm\n", finalDistance);
    
    return 0;
}

