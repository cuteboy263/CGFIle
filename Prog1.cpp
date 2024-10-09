#include <graphics.h>
#include <conio.h>
int main()
{
    int poly[14] = {400, 200, 450, 225, 450, 275, 400, 300, 350, 275, 350,
                    225, 400, 200};
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    // Initialize the graphics system
    initgraph(&gd, &gm, (char *)data);
    // 1. Draw a circle
    setcolor(RED);
    circle(100, 100, 50);
    // 2. Draw a line
    setcolor(GREEN);
    line(200, 50, 300, 150);
    // 3. Draw a rectangle
    setcolor(YELLOW);
    rectangle(350, 50, 450, 150);
    // 4. Draw an arc
    setcolor(MAGENTA);
    arc(100, 250, 0, 180, 50);
    // 5. Draw an ellipse
    setcolor(CYAN);
    ellipse(250, 250, 0, 360, 75, 25);
    // 6. Draw a polygon (hexagon)
    setcolor(WHITE);
    drawpoly(7, poly);
     outtextxy(100, 20, (char *)"Himanshu Joshi , BCA 5 Evening , 02421402022");
    getch();
    closegraph();
    return 0;
}