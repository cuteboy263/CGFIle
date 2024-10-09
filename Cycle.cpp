#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void drawStickman(int x, int y)
{
    circle(x, y - 40, 10);           // Head
    line(x, y - 30, x, y);           // Body
    line(x, y - 20, x - 10, y - 10); // Left arm
    line(x, y - 20, x + 10, y - 10); // Right arm
    line(x, y, x - 10, y + 15);      // Left leg
    line(x, y, x + 10, y + 15);      // Right leg
}
int main()
{
    int i, j;
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);
    for (i = 0; i < 500; i++)
    {
        // Bicycle animation
        circle(200 + i, 300, 30);
        circle(350 + i, 300, 30);
        arc(200 + i, 300, 0, 180, 34);
        arc(350 + i, 300, 30, 195, 34);
        line(200 + i, 300, 270 + i, 300);
        line(200 + i, 240, 200 + i, 300);
        line(200 + i, 250, 270 + i, 300);
        line(270 + i, 300, 350 + i, 250);
        line(200 + i, 250, 350 + i, 250);
        line(350 + i, 300, 350 + i, 220);
        line(340 + i, 210, 360 + i, 230);
        line(265 + i, 280, 275 + i, 320);
        line(190 + i, 240, 220 + i, 240);
        // Add a flower
        setcolor(YELLOW);
        circle(180 + i, 230, 5); // Flower center
        setcolor(LIGHTRED);
        for (j = 0; j < 360; j += 45)
        {
            line(180 + i, 230,
                 180 + i + 10 * cos(j * 3.14159 / 180),
                 230 + 10 * sin(j * 3.14159 / 180));
        }
        // Add stickman using function
        setcolor(WHITE);
        drawStickman(205 + i, 218); // Position stickman on the seat
        // Draw ground
        line(0, 330, 650, 330);
        delay(10);
        cleardevice();
        // Re-display your name after screen clear
        outtextxy(100, 20, (char *)"Himanshu Joshi , BCA 5 Evening , 02421402022");
    }
    closegraph();
    return 0;
}
