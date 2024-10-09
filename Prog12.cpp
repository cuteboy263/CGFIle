#include <graphics.h>
#include <conio.h>
#include <direct.h> // For delay function
#include <cmath>  // For M_PI

// Function to draw a circle using the Mid-Point Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial decision parameter

    // Draw the initial points in each octant
    while (x <= y) {
        // Points in all octants
        putpixel(xc + x, yc + y, WHITE); // Octant 1
        putpixel(xc - x, yc + y, WHITE); // Octant 2
        putpixel(xc + x, yc - y, WHITE); // Octant 3
        putpixel(xc - x, yc - y, WHITE); // Octant 4
        putpixel(xc + y, yc + x, WHITE); // Octant 5
        putpixel(xc - y, yc + x, WHITE); // Octant 6
        putpixel(xc + y, yc - x, WHITE); // Octant 7
        putpixel(xc - y, yc - x, WHITE); // Octant 8

        x++;

        // Update decision parameter
        if (p < 0) {
            p = p + 2 * x + 1; // Next decision
        } else {
            y--;
            p = p + 2 * x - 2 * y + 1; // Next decision
        }
    }
}

// Function to draw the wooden cart wheel
void drawWoodenWheel(int xc, int yc, int r) {
    // Draw the outer circle of the wheel
    setcolor(BROWN);
    drawCircle(xc, yc, r); // Outer circle

    // Draw the inner circle (hub)
    setcolor(DARKGRAY);
    drawCircle(xc, yc, r / 3); // Inner circle (hub)

    // Draw spokes
    setcolor(BROWN);
    for (int angle = 0; angle < 360; angle += 30) { // 12 spokes (30 degrees apart)
        int x1 = xc + (r / 3) * cos(angle * M_PI / 180); // Start from hub
        int y1 = yc + (r / 3) * sin(angle * M_PI / 180);
        int x2 = xc + r * cos(angle * M_PI / 180); // End at the outer circle
        int y2 = yc + r * sin(angle * M_PI / 180);
        line(x1, y1, x2, y2); // Draw spoke
    }
}

// Function to clear the circle by drawing over it with the background color
void clearCircle(int xc, int yc, int r) {
    setcolor(BLACK); // Background color
    drawCircle(xc, yc, r); // Draw the circle with background color
}

// Function to draw the ground surface with stones
void drawGround(int y) {
    setcolor(GREEN);
    line(0, y, getmaxx(), y); // Draw the ground line
    for (int i = 0; i < getmaxx(); i += 50) { // Draw stones
        setcolor(WHITE);
        int stoneY = y + 5 + rand() % 5; // Random y position for stones
        circle(i + 25, stoneY, 5); // Draw small stones
    }
}

int main() {
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    initgraph(&gd, &gm, (char *)data);

    int x = 200, y = 350; // Initial position of the wheel center
    int radius = 50; // Radius of the wheel
    int speed = 5; // Speed of the wheel movement

    // Display student information
    setcolor(WHITE);
    outtextxy(100, 20, (char *)"Ayush Garg, 03121402022"); // Display name

    while (true) {
        cleardevice(); // Clear the screen
        drawGround(400); // Draw the ground surface

        // Clear the previous position of the wheel
        clearCircle(x, y, radius + 10); 
        
        // Draw the wooden wheel at the new position
        drawWoodenWheel(x, y, radius); 

        // Update the wheel position (moving right)
        x += speed;

        // Reset position if the wheel moves off the screen
        if (x - radius > getmaxx()) {
            x = 0; // Start from the left again
        }

        // Display your name again after clearing the screen
        setcolor(WHITE);
        outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

        delay(30); // Control the speed of the animation
    }

    closegraph();
    return 0;
}
