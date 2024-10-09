#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include<math.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846


#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265358979323846  // Define PI value

void drawFlagPole(int x, int y, int height)
{
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    
    // Draw the flag pole
    rectangle(x, y, x + 10, y + height);
    floodfill(x + 1, y + 1, BROWN);
    
    // Draw the top ball on the flagpole
    circle(x + 5, y - 5, 7);
    floodfill(x + 5, y - 5, BROWN);
}

void drawFlag(int x, int y)
{
    // Saffron stripe
    setcolor(WHITE);
    rectangle(x, y, x + 80, y + 20); // Saffron rectangle
    setfillstyle(SOLID_FILL, COLOR(255, 153, 51));  // Saffron color
    floodfill(x + 1, y + 1, WHITE);
    
    // White stripe
    rectangle(x, y + 20, x + 80, y + 40); // White rectangle
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 1, y + 21, WHITE);

    // Green stripe
    rectangle(x, y + 40, x + 80, y + 60); // Green rectangle
    setfillstyle(SOLID_FILL, COLOR(19, 136, 8));  // Green color
    floodfill(x + 1, y + 41, WHITE);

    // Ashoka Chakra
    setcolor(BLUE);
    circle(x + 40, y + 30, 10);  // Center the Chakra
    for (int angle = 0; angle < 360; angle += 15) {
        int lineX = x + 40 + 10 * cos(angle * PI / 180);  // Use cos from math.h
        int lineY = y + 30 + 10 * sin(angle * PI / 180);  // Use sin from math.h
        line(x + 40, y + 30, lineX, lineY);
    }
}

void drawBase(int x, int y)
{
    // Draw the base of the flagpole
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    
    // Draw the steps of the base
    for (int i = 0; i < 3; i++) {
        rectangle(x - i * 15, y + i * 15, x + 60 + i * 15, y + 15 + i * 15);
        floodfill(x - i * 14, y + i * 16, BROWN);
    }
}

void drawText(int x, int y)
{
    setcolor(COLOR(255, 153, 51));  // Saffron color
    outtextxy(x, y, (char *)"I");
    
    setcolor(BLUE);  // Blue for "LOVE"
    outtextxy(x + 10, y, (char *)"LOVE");

    setcolor(COLOR(19, 136, 8));  // Green color for "MY"
    outtextxy(x + 50, y, (char *)"MY");

    setcolor(COLOR(19, 136, 8));  // Green for "INDIA"
    outtextxy(x + 80, y, (char *)"INDIA");
}

int main()
{
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);

    // Coordinates for the flag
    int poleX = 300, poleY = 200;
    int flagHeight = 150;

    // Draw flagpole, flag, base, and text
    drawFlagPole(poleX, poleY, flagHeight);       // Draw the flagpole
    drawFlag(poleX + 10, poleY);                  // Draw the flag next to the pole
    drawBase(poleX - 20, poleY + flagHeight);     // Draw the base
    drawText(poleX - 40, poleY + flagHeight + 50);  // Draw text
    outtextxy(100, 20, (char *)"Naman Singh , BCA 5 Evening , 02121402022");
    getch();
    closegraph();
    return 0;
}
