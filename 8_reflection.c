#include <conio.h>
#include <graphics.h>
#include <stdio.h>

void main() {
    int gm, gd = DETECT;
    int x1 = 100, x2 = 100, x3 = 200;
    int y1 = 100, y2 = 200, y3 = 100;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();

    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

    printf("Before Reflection Object in 2nd Quadrant\n");

    setcolor(14);  // Yellow color
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();

    printf("\nAfter Reflection\n");

    setcolor(4);  // Red color
    line(getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2);
    line(getmaxx() - x2, getmaxy() - y2, getmaxx() - x3, getmaxy() - y3);
    line(getmaxx() - x3, getmaxy() - y3, getmaxx() - x1, getmaxy() - y1);

    setcolor(3);  // Cyan color
    line(getmaxx() - x1, y1, getmaxx() - x2, y2);
    line(getmaxx() - x2, y2, getmaxx() - x3, y3);
    line(getmaxx() - x3, y3, getmaxx() - x1, y1);

    setcolor(2);  // Green color
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    line(x2, getmaxy() - y2, x3, getmaxy() - y3);
    line(x3, getmaxy() - y3, x1, getmaxy() - y1);

    getch();
    closegraph();
}
