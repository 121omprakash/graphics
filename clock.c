#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <dos.h>

#define PI 3.14159265358979323846

void clockLayout();
void secHand();
void minHand();
void hrHand();
int maxx, maxy;

void main() {
    int gdriver = DETECT, gmode, error;

    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    error = graphresult();
    if (error != grOk) {
        printf("Error in graphics, code= %s", grapherrormsg(error));
        exit(0);
    }

    while (1) {
        clockLayout();
        secHand();
        minHand();
        hrHand();
        delay(1000);
        cleardevice();
    }
}

void clockLayout() {
    int i, x, y, r;
    float angle;

    maxx = getmaxx();
    maxy = getmaxy();

    setcolor(YELLOW);
    for (i = 1; i < 5; i++) {
        circle(maxx / 2, maxy / 2, 120 - i);
    }

    pieslice(maxx / 2, maxy / 2, 0, 360, 5);

    x = maxx / 2 + 100;
    y = maxy / 2;
    r = 100;

    setcolor(BLUE);
    for (angle = PI / 6; angle <= (2 * PI); angle += (PI / 6)) {
        pieslice(x, y, 0, 360, 4);
        x = (maxx / 2) + r * cos(angle);
        y = (maxy / 2) + r * sin(angle);
    }

    x = maxx / 2 + 100;
    y = maxy / 2;

    setcolor(RED);
    for (angle = PI / 30; angle <= (2 * PI); angle += (PI / 30)) {
        pieslice(x, y, 0, 360, 2);
        x = (maxx / 2) + r * cos(angle);
        y = (maxy / 2) + r * sin(angle);
    }
}

void secHand() {
    struct time t;
    int r = 80, x = maxx / 2, y = maxy / 2, sec;
    float angle;

    gettime(&t);
    sec = t.ti_sec;
    angle = sec * (PI / 30) - (PI / 2);

    setcolor(YELLOW);
    line(x, y, x + r * cos(angle), y + r * sin(angle));
}

void minHand() {
    struct time t;
    int r = 60, min;
    float angle;
    int x = maxx / 2, y = maxy / 2;

    gettime(&t);
    min = t.ti_min;
    angle = min * (PI / 30) - (PI / 2);

    setcolor(RED);
    line(x, y, x + r * cos(angle), y + r * sin(angle));
}

void hrHand() {
    struct time t;
    int r = 50, hr, min;
    float angle;
    int x = maxx / 2, y = maxy / 2;

    gettime(&t);
    hr = t.ti_hour;
    min = t.ti_min;

    if (hr > 12)
        hr -= 12;

    angle = (hr * (PI / 6) - (PI / 2)) + ((min / 60.0) * (PI / 6));

    setcolor(BLUE);
    line(x, y, x + r * cos(angle), y + r * sin(angle));
}
