#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

typedef struct coordinate {
    int x, y;
    char code[4];
} PT;

void drawWindow();
void drawLine(PT p1, PT p2);
PT setCode(PT p);
int visibility(PT p1, PT p2);
PT resetEndpt(PT p1, PT p2);

void main() {
    int gd = DETECT, gm, visibilityFlag;
    PT p1, p2, p3, p4;

    printf("Enter x1 and y1: ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter x2 and y2: ");
    scanf("%d %d", &p2.x, &p2.y);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawWindow();

    delay(500);
    drawLine(p1, p2);
    delay(500);

    p1 = setCode(p1);
    p2 = setCode(p2);

    visibilityFlag = visibility(p1, p2);

    switch (visibilityFlag) {
        case 0:  // Fully visible
            drawWindow();
            delay(500);
            drawLine(p1, p2);
            break;

        case 1:  // Fully invisible
            drawWindow();
            break;

        case 2:  // Partially visible
            p3 = resetEndpt(p1, p2);
            p4 = resetEndpt(p2, p1);
            drawWindow();
            delay(500);
            drawLine(p3, p4);
            break;
    }

    delay(5000);
    closegraph();
}

void drawWindow() {
    rectangle(150, 100, 450, 350);
}

void drawLine(PT p1, PT p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

PT setCode(PT p) {
    PT temp = p;

    temp.code[0] = (p.y < 100) ? '1' : '0';  // Top
    temp.code[1] = (p.y > 350) ? '1' : '0';  // Bottom
    temp.code[2] = (p.x > 450) ? '1' : '0';  // Right
    temp.code[3] = (p.x < 150) ? '1' : '0';  // Left

    return temp;
}

int visibility(PT p1, PT p2) {
    int i, flag = 0;

    for (i = 0; i < 4; i++) {
        if ((p1.code[i] != '0') || (p2.code[i] != '0'))
            flag = 1;
    }

    if (flag == 0)
        return 0;  // Fully visible

    for (i = 0; i < 4; i++) {
        if ((p1.code[i] == '1') && (p2.code[i] == '1'))
            return 1;  // Fully invisible
    }

    return 2;  // Partially visible
}

PT resetEndpt(PT p1, PT p2) {
    PT temp;
    int x, y;
    float m;

    if (p1.code[3] == '1')  // Left
        x = 150;
    else if (p1.code[2] == '1')  // Right
        x = 450;
    else
        x = p1.x;

    if (x != p1.x) {
        m = (float)(p2.y - p1.y) / (p2.x - p1.x);
        y = p1.y + (x - p1.x) * m;
        temp.x = x;
        temp.y = y;
    } else {
        if (p1.code[0] == '1')  // Top
            y = 100;
        else if (p1.code[1] == '1')  // Bottom
            y = 350;
        else
            y = p1.y;

        if (y != p1.y) {
            m = (float)(p2.x - p1.x) / (p2.y - p1.y);
            x = p1.x + (y - p1.y) * m;
            temp.x = x;
            temp.y = y;
        }
    }

    return temp;
}
