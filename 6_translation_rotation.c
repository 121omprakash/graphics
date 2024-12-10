#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main() {
    int gm, gd = DETECT, midx, midy, c;
    float x1, x2, x3, y1, y2, y3, x11, x22, x33, y11, y22, y33, sfx, sfy, tpx, tpy;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    line(midx, 0, midx, getmaxy());
    line(0, midy, getmaxx(), midy);

    printf("2D Translation and Scaling of a Triangle\n");
    printf("Enter the points (x1, y1), (x2, y2) and (x3, y3) of the triangle:\n");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    setcolor(WHITE);
    line(midx + x1, midy - y1, midx + x2, midy - y2);
    line(midx + x2, midy - y2, midx + x3, midy - y3);
    line(midx + x3, midy - y3, midx + x1, midy - y1);

    while (1) {
        printf("\n1. Translation\n2. Scaling\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter the translation factors (tpx, tpy): ");
                scanf("%f%f", &tpx, &tpy);

                x11 = x1 + tpx;
                y11 = y1 + tpy;
                x22 = x2 + tpx;
                y22 = y2 + tpy;
                x33 = x3 + tpx;
                y33 = y3 + tpy;

                setcolor(RED);
                line(midx + x11, midy - y11, midx + x22, midy - y22);
                line(midx + x22, midy - y22, midx + x33, midy - y33);
                line(midx + x33, midy - y33, midx + x11, midy - y11);
                break;

            case 2:
                printf("Enter the scaling factors (sfx, sfy): ");
                scanf("%f%f", &sfx, &sfy);

                x11 = x1 * sfx;
                y11 = y1 * sfy;
                x22 = x2 * sfx;
                y22 = y2 * sfy;
                x33 = x3 * sfx;
                y33 = y3 * sfy;

                setcolor(YELLOW);
                line(midx + x11, midy - y11, midx + x22, midy - y22);
                line(midx + x22, midy - y22, midx + x33, midy - y33);
                line(midx + x33, midy - y33, midx + x11, midy - y11);
                break;

            case 3:
                closegraph();
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    getch();
}
