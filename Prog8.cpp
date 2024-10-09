#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

// Function to draw a line using Bresenham's Algorithm
void drawLineBresenham(int x0, int y0, int x1, int y1) {
    // Calculate the differences
    int dx = x1 - x0;
    int dy = y1 - y0;

    // Determine the steps needed based on the absolute values of dx and dy
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;  // Calculate the increment in x
    float yIncrement = dy / (float)steps;  // Calculate the increment in y

    // Initialize starting point
    float x = x0;
    float y = y0;

    // Loop through and plot each point along the line
    for (int i = 0; i <= steps; i++) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);  // Plot the point using static_cast
        x += xIncrement;                       // Increment x
        y += yIncrement;                       // Increment y
    }
}

int main() {
    int gd = DETECT, gm;  // Graphics drivers

    // Initialize the graphics system
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    // Define coordinates for the line endpoints
    int x0 = 100, y0 = 100;  // Starting point of the line
    int x1 = 400, y1 = 300;  // Ending point of the line

    // Draw the line using Bresenham's Algorithm
    drawLineBresenham(x0, y0, x1, y1);

    // Hold the window to view the result
    getch();

    // Close the graphics window
    closegraph();
    return 0;
}

