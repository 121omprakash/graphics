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
    p = 3 - (2 * r);

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
            p = p + (4 * x) + 6;
        } else {
            y--;
            p = p + (4 * (x - y)) + 10;
        }
        x++;
    } while (x <= y);

    getch();
    closegraph();
}
