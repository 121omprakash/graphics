#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int p1, p2;
    float dx, dy;

    // Initial decision parameter for region 1
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    while ((2 * ry * ry * x) < (2 * rx * rx * y)) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0) {
            x++;
            p1 = p1 + (2 * ry * ry * x) + (ry * ry);
        } else {
            x++;
            y--;
            p1 = p1 + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
    }

    // Decision parameter for region 2
    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0) {
            y--;
            p2 = p2 - (2 * rx * rx * y) + (rx * rx);
        } else {
            y--;
            x++;
            p2 = p2 + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
    }
}

void main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter center of ellipse (xc, yc): ");
    scanf("%d%d", &xc, &yc);
    printf("Enter x-radius and y-radius (rx, ry): ");
    scanf("%d%d", &rx, &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
}
