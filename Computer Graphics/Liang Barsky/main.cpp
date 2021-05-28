#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main() {
    // basic
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);

    /// inputs
    int x1, y1, x2, y2, xmin, xmax, ymin, ymax, dx, dy;

    // coordinates of the line
    x1 = 20;
    y1 = 70;
    x2 = 450;
    y2 = 450;

    // coordinates of the window
    xmin = 100;
    ymin = 100;
    xmax = 200;
    ymax = 200;

    // draw the rectangle window
    rectangle(xmin, ymin, xmax, ymax);

    // cal the delta x and delta y
    dx = x2 - x1;
    dy = y2 - y1;

    // assigning parameters their values
    float p[4], q[4];
    p[0] = float(-dx);
    p[1] = float(dx);
    p[2] = float(-dy);
    p[3] = float(dy);

    q[0] = float(x1 - xmin);
    q[1] = float(xmax - x1);
    q[2] = float(y1 - ymin);
    q[3] = float(ymax - y1);

    // check for all values of p and q array
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            // parallel line
            cout << "Line is parallel to the boundary of the Rectangle" << endl;
            if (q[i] < 0)
                cout << "Line is outside" << endl;
            else
                cout << "Line is inside" << endl;
        }
    }

    // initialize the values
    float t1, t2, temp;

    t1 = 0;
    t2 = 1;

    // for all the parameters
    for (int i = 0; i < 4; i++) {
        temp = q[i] / p[i];

        if (p[i] < 0) {
            t1 = max(t1, temp);
        } else {
            t2 = min(t2, temp);
        }
    }

    // final clipping
    int xx1, xx2, yy1, yy2;
    if (t1 < t2) {
        // x = x1 + tdeltax
        // y = y1 + tdeltay
        xx1 = x1 + t1 * dx;
        yy1 = y1 + t1 * dy;
        xx2 = x1 + t2 * dx;
        yy2 = y1 + t2 * dy;
        line(xx1, yy1, xx2, yy2);
    } else {
        cout << "Line lies completely oustide" << endl;
    }

    getch();
    closegraph();

    return 0;
}