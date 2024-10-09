#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>  // Include cmath for sqrt

using namespace std;

// Function to draw a line using Bresenham's Algorithm
void drawLineBresenham(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to draw an equilateral triangle
void drawEquilateralTriangle(int x, int y, int sideLength) {
    int height = static_cast<int>((sqrt(3) / 2) * sideLength); // Height of the equilateral triangle
    drawLineBresenham(x, y, x + sideLength, y); // Base of the triangle
    drawLineBresenham(x + sideLength, y, x + (sideLength / 2), y - height); // Right side
    drawLineBresenham(x + (sideLength / 2), y - height, x, y); // Left side
}

// Function to draw an isosceles triangle
void drawIsoscelesTriangle(int x, int y, int baseLength, int height) {
    drawLineBresenham(x, y, x + baseLength, y); // Base
    drawLineBresenham(x + baseLength, y, x + (baseLength / 2), y - height); // Right side
    drawLineBresenham(x + (baseLength / 2), y - height, x, y); // Left side
}

// Function to draw a scalene triangle
void drawScaleneTriangle(int x, int y) {
    drawLineBresenham(x, y, x + 100, y); // Base
    drawLineBresenham(x + 100, y, x + 70, y - 80); // Right side
    drawLineBresenham(x + 70, y - 80, x, y); // Left side
}

int main() {
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    int choice;
    do {
        // Display student information on every iteration
        setcolor(WHITE);
        outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

        // Display menu options
        cout << "Menu:\n";
        cout << "1. Draw Equilateral Triangle\n";
        cout << "2. Draw Isosceles Triangle\n";
        cout << "3. Draw Scalene Triangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the screen before drawing each triangle
        cleardevice();

        // Redraw the name after clearing the device
        setcolor(WHITE);
        outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

        switch (choice) {
            case 1:
                drawEquilateralTriangle(200, 300, 200); // Draw equilateral triangle
                break;
            case 2:
                drawIsoscelesTriangle(200, 300, 200, 150); // Draw isosceles triangle
                break;
            case 3:
                drawScaleneTriangle(200, 300); // Draw scalene triangle
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        delay(1000); // Delay to view the triangle
    } while (choice != 4);

    closegraph();
    return 0;
}
