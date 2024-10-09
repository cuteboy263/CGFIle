#include <graphics.h>
#include <iostream>

using namespace std;

// Function to draw a line using the Mid-Point Algorithm
void drawLineMidPoint(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * dy - dx; // Initial decision parameter

    putpixel(x0, y0, WHITE); // Plot the first point

    for (int x = x0; x < x1; x++) {
        if (d > 0) {
            y0++; // Increment y if d > 0
            d += 2 * (dy - dx); // Update d
        } else {
            d += 2 * dy; // Update d
        }
        putpixel(x, y0, WHITE); // Plot the next point
    }
}

// Function to draw a circle using the Mid-Point Algorithm
void drawCircleMidPoint(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r; // Initial decision parameter

    // Draw initial points in all octants
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);

    while (x < y) {
        x++;
        if (d < 0) {
            d = d + 2 * x + 1; // Move to next point in x
        } else {
            y--;
            d = d + 2 * (x - y) + 1; // Move to next point in x and y
        }
        // Draw points in all octants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    // Draw a line
    drawLineMidPoint(100, 100, 300, 200); // Start and end points of the line

    // Draw a circle
    drawCircleMidPoint(400, 200, 50); // Center and radius of the circle

    // Display student information
    setcolor(WHITE);
   outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

    // Hold the window for a few seconds
    delay(5000); // Display for 5 seconds

    closegraph(); // Close the graphics window
    return 0;
}
