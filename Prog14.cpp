#include <graphics.h>
#include <conio.h>
#include <direct.h> // For delay function

// Function to draw the bouncing ball
void drawBouncingBall(int x, int y, int radius) {
    setcolor(RED); // Ball color
    circle(x, y, radius); // Draw the ball
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED); // Fill the ball with color
}

// Function to clear the ball
void clearBall(int x, int y, int radius) {
    setcolor(WHITE); // Background color
    circle(x, y, radius); // Draw a white circle to erase the ball
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x, y, WHITE); // Fill the area with white
}

int main() {
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    initgraph(&gd, &gm, (char *)data);

    // Rectangle dimensions
    int rectX1 = 100, rectY1 = 100, rectX2 = 500, rectY2 = 400;

    // Draw the rectangle box
    setcolor(WHITE);
    rectangle(rectX1, rectY1, rectX2, rectY2);

    // Ball parameters
    int radius = 20;
    int x = 200, y = 200; // Initial position of the ball
    int xSpeed = 5; // Horizontal speed
    int ySpeed = 3; // Vertical speed

    // Display your name on the screen
    setcolor(WHITE);
     outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

    while (true) {
        clearBall(x, y, radius); // Clear the current position of the ball

        // Update ball position
        x += xSpeed;
        y += ySpeed;

        // Check for collision with the rectangle boundaries
        if (x + radius > rectX2 || x - radius < rectX1) {
            xSpeed = -xSpeed; // Reverse direction on horizontal collision
        }
        if (y + radius > rectY2 || y - radius < rectY1) {
            ySpeed = -ySpeed; // Reverse direction on vertical collision
        }

        drawBouncingBall(x, y, radius); // Draw the ball at the new position

        delay(30); // Control the speed of the animation
    }

    closegraph();
    return 0;
}
