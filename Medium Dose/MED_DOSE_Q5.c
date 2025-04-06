#include <stdio.h>
#include <math.h>


/* logic is:
At first ,3 angles in 3D form given is degrees is converted into radians and then the radian angles are divided
into half, these half angles are converted to quaternious system 4D by using trigonametric formulas. */

// Convert degrees to radians
double degToRad(double degrees) {
    return degrees * M_PI / 180.0;
}

// Main function
void main() {
    
    // Input Euler angles: roll (X), pitch (Y), yaw (Z)
    double roll_deg, pitch_deg, yaw_deg;
    printf("Enter roll (X) in degrees: ");
    scanf("%lf", &roll_deg);
    printf("Enter pitch (Y) in degrees: ");
    scanf("%lf", &pitch_deg);
    printf("Enter yaw (Z) in degrees: ");
    scanf("%lf", &yaw_deg);

    // Convert to radians
    double roll = degToRad(roll_deg);
    double pitch = degToRad(pitch_deg);
    double yaw = degToRad(yaw_deg);

    // Compute half angles
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);

    // Compute quaternion components

    // By the  given formulas above.
    double w = cr * cp * cy + sr * sp * sy;
    double x = sr * cp * cy - cr * sp * sy;
    double y = cr * sp * cy + sr * cp * sy;
    double z = cr * cp * sy - sr * sp * cy;

    // Output the quaternion
    printf("\nMartian Rotation System (Quaternion):\n");
    printf("w = %.6f\n", w);
    printf("x = %.6f\n", x);
    printf("y = %.6f\n", y);
    printf("z = %.6f\n", z);

    
}
