#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void drawBuilding(int x, int y)
{
    int i, j;
    setcolor(DARKGRAY);
    rectangle(x, y, x + 100, y + 150); // Draw building

    // Draw windows
    setcolor(YELLOW);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            rectangle(x + 10 + i * 30, y + 20 + j * 30, x + 25 + i * 30, y + 35 + j * 30);
        }
    }
}

void drawTree(int x, int y)
{
    // Draw the tree trunk
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x, y, x + 10, y + 40);
    floodfill(x + 5, y + 20, BROWN);

    // Draw the leaves as circles
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    fillellipse(x + 5, y - 10, 20, 20);
    fillellipse(x - 10, y - 20, 20, 20);
    fillellipse(x + 20, y - 20, 20, 20);
}

void drawMoon()
{
    // Draw a moon in the top right corner
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(getmaxx() - 50, 50, 30, 30);

    // Add a darker portion to create a crescent effect
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(getmaxx() - 35, 50, 30, 30);
}

int main()
{
    int gd = DETECT, gm;
    int i, x, y;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);
    while (!kbhit())
    {
        cleardevice();

        // Draw two buildings
        drawBuilding(100, 300); // First building
        drawBuilding(250, 300); // Second building

        // Draw trees
        drawTree(80, 380);  // Tree next to the first building
        drawTree(220, 380); // Tree between the buildings
        drawTree(370, 380); // Tree next to the second building

        // Draw the moon
        drawMoon();

        // Draw stars
        setcolor(WHITE);
        for (i = 0; i <= 500; i++)
        {
            x = rand() % getmaxx();
            y = rand() % getmaxy();
            putpixel(x, y, WHITE);
        }
        // Display text
        setcolor(WHITE);
        outtextxy(10, 10, (char *)"THE NIGHT SKY");
        outtextxy(100, 20, (char *)"Naman Singh , BCA 5 Evening , 02121402022");
        delay(500);
    }
    getch();
    closegraph();
    return 0;
}
