#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    int dx, dy, steps;
    float xIncrement, yIncrement, x, y;

    // Calculate the differences in the x and y coordinates
    dx = x2 - x1;
    dy = y2 - y1;

    // Find the steps required for drawing the line
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    // Calculate the increments for each step
    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    // Initialize the starting point
    x = x1;
    y = y1;

    // Plot the points one by one
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);  // Draw pixel at (x, y)
        x += xIncrement;  // Increment x by xIncrement
        y += yIncrement;  // Increment y by yIncrement
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "");

    // Input points for the line
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the line using DDA algorithm
    DDA(x1, y1, x2, y2);

    // Wait for user input to close the window
    getch();
    closegraph();

    return 0;
}
