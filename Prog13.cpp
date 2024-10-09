#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <ctime>

#define PI 3.14159265

void drawClockFace(int xc, int yc, int radius) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(xc, yc, WHITE);  // Fill the clock face

    // Draw the outer circle
    setcolor(BLACK);
    circle(xc, yc, radius);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(xc, yc, BLACK); // Fill the outer area to make it stand out

    // Draw the hour markers
    for (int i = 0; i < 12; i++) {
        int x1 = xc + radius * 0.8 * cos(i * PI / 6);
        int y1 = yc - radius * 0.8 * sin(i * PI / 6);
        int x2 = xc + radius * 0.9 * cos(i * PI / 6);
        int y2 = yc - radius * 0.9 * sin(i * PI / 6);
        setcolor(WHITE);
        line(x1, y1, x2, y2); // Draw hour markers
    }
}

void drawClockHands(int xc, int yc, int hour, int minute, int second) {
    // Draw hour hand
    float hourAngle = (hour % 12 + minute / 60.0) * 30; // 30 degrees for each hour
    int xHour = xc + 60 * cos(hourAngle * PI / 180 - PI / 2);
    int yHour = yc + 60 * sin(hourAngle * PI / 180 - PI / 2);
    setcolor(WHITE);
    line(xc, yc, xHour, yHour); // Draw hour hand

    // Draw minute hand
    float minuteAngle = (minute + second / 60.0) * 6; // 6 degrees for each minute
    int xMinute = xc + 90 * cos(minuteAngle * PI / 180 - PI / 2);
    int yMinute = yc + 90 * sin(minuteAngle * PI / 180 - PI / 2);
    setcolor(WHITE);
    line(xc, yc, xMinute, yMinute); // Draw minute hand

    // Draw second hand
    float secondAngle = second * 6; // 6 degrees for each second
    int xSecond = xc + 100 * cos(secondAngle * PI / 180 - PI / 2);
    int ySecond = yc + 100 * sin(secondAngle * PI / 180 - PI / 2);
    setcolor(RED);
    line(xc, yc, xSecond, ySecond); // Draw second hand
}

int main() {
    int gd = DETECT, gm;
    const char *data = "C:\\MinGW\\lib\\libbgi.a"; // Path to your BGI file
    initgraph(&gd, &gm, (char *)data);

    int xc = 400, yc = 300; // Center of the clock
    int radius = 150; // Radius of the clock face

    while (true) {
        // Clear previous hands
        cleardevice();
        
        // Draw clock face
        drawClockFace(xc, yc, radius);

        // Get current time
        time_t t = time(0);
        struct tm *now = localtime(&t);
        int hour = now->tm_hour;
        int minute = now->tm_min;
        int second = now->tm_sec;

        // Draw clock hands
        drawClockHands(xc, yc, hour, minute, second);

        // Display text
        setcolor(WHITE);
        outtextxy(100, 20, (char *)"Ayush Garg, 03121402022");

        delay(1000); // Update every second
    }

    closegraph();
    return 0;
}
