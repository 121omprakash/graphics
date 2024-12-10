#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main() {
    int x, y, x1, y1, x2, y2, dx, dy, p, end;

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    printf("Enter 1st end point of line (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter 2nd end point of line (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    p = 2 * dy - dx;

    if (x1 > x2) {
        x = x2;
        y = y2;
        end = x1;
    } else {
        x = x1;
        y = y1;
        end = x2;
    }

    putpixel(x, y, WHITE);

    while (x < end) {
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            y++;
            p = p + 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
}
