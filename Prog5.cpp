#include <graphics.h>
#include <conio.h>
#include <stdlib.h>  // For rand() to generate random colors

// Function to draw concentric circles with color boundaries
void drawConcentricCircles(int x, int y, int radius, int step, int boundaryColor) {
    int r = radius;
    setcolor(boundaryColor);  // Set the color for the circle boundary
    while (r > 0) {
        circle(x, y, r);  // Draw the circle with the boundary color
        r -= step;        // Reduce the radius for the next circle
    }
}

// Function to fill the circle with random colors
void fillCircle(int x, int y, int radius) {
    int fillColor = rand() % 15 + 1;  // Generate a random color (1 to 15)
    setfillstyle(SOLID_FILL, fillColor);  // Set the fill style and color
    floodfill(x, y, getcolor());  // Fill the circle with the chosen color
}

int main() {
    int gd = DETECT, gm;         // Graphics drivers
    int x = 320, y = 240;        // Coordinates for circle center
    int radius = 50;             // Initial radius
    int step = 10;               // Step for expanding/shrinking circles
    int key;                     // To store user key input
    int boundaryColor = WHITE;   // Default boundary color for circles

    // Initialize the graphics system
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    // Draw the initial set of concentric circles with the default boundary color
    drawConcentricCircles(x, y, radius, step, boundaryColor);

    // Display instructions and text
    printf("Press 'e' to expand circles (color the boundary), 's' to shrink circles (fill with color), 'q' to quit.\n");
    outtextxy(100, 20, (char *)"Naman Singh, BCA 5 Evening, 02121402022");

    // Main loop to handle key inputs
    while (1) {
        key = getch();   // Get a key press
        cleardevice();   // Clear the screen for the next drawing

        if (key == 'e') {           // Expand the circles and color the boundaries
            radius += step;
            boundaryColor = rand() % 15 + 1;  // Generate random boundary color
        } else if (key == 's') {    // Shrink the circles and fill the inside
            radius -= step;
            if (radius < step) {
                radius = step;      // Avoid negative or zero radius
            }
            fillCircle(x, y, radius);  // Fill the inside of the circle with random color
        } else if (key == 'q') {    // Quit the program
            break;
        }

        // Draw the circles with the current boundary color
        drawConcentricCircles(x, y, radius, step, boundaryColor);
    }

    // Close the graphics system
    closegraph();
    return 0;
}
