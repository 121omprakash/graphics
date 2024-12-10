#include <stdio.h>

#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

const int x_max = 10;
const int y_max = 8;
const int x_min = 4;
const int y_min = 4;

int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < x_min)  // To the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // To the right of rectangle
        code |= RIGHT;

    if (y < y_min)  // Below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // Above the rectangle
        code |= TOP;

    return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {  // Trivially accepted
            accept = 1;
            break;
        } else if (code1 & code2) {  // Trivially rejected
            break;
        } else {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept)
        printf("Line accepted from %.2f, %.2f to %.2f, %.2f\n", x1, y1, x2, y2);
    else
        printf("Line rejected\n");
}

int main() {
    cohenSutherlandClip(5, 5, 7, 7);
    cohenSutherlandClip(7, 9, 11, 4);
    cohenSutherlandClip(1, 5, 4, 1);

    return 0;
}
