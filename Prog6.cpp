#include <graphics.h>
#include <conio.h>
#include <cmath>

void drawLineDDA(int x0, int y0, int x1, int y1) {
    // Calculate the difference in coordinates
    int dx = x1 - x0;
    int dy = y1 - y0;

    // Determine the number of steps needed based on the greater difference
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increments in x and y for each step
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    // Initialize starting point
    float x = x0;
    float y = y0;

    // Loop through and plot each point along the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Plot the point
        x += xIncrement;                       // Increment x
        y += yIncrement;                       // Increment y
    }
}

int main() {
    int gd = DETECT, gm;  // Graphics drivers

   const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    // Define coordinates for the line endpoints
    int x0 = 100, y0 = 100;  // Starting point of the line
    int x1 = 400, y1 = 300;  // Ending point of the line

    // Draw the line using the DDA algorithm
    drawLineDDA(x0, y0, x1, y1);
    setcolor(WHITE);
    outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

    // Hold the window to view the result
    getch();

    // Close the graphics window
    closegraph();
    return 0;
}
