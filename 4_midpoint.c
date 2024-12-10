#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int gd = DETECT, gm;
    int xc = 320, yc = 240, r, x, y, p;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter radius of the circle: ");
    scanf("%d", &r);

    x = 0;
    y = r;
    p = 1 - r;

    do {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p < 0) {
            p = p + (2 * x) + 3;
        } else {
            y--;
            p = p + (2 * (x - y)) + 5;
        }
        x++;
    } while (x <= y);

    getch();
    closegraph();
}
