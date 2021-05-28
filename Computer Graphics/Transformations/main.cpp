
#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

// ORIGINAL
int x, y, x2, y2;

// ROTATION
int x3, y3;

// SCALING
int x4, y4;

// function to translate line
void translateLine() {
    cout << "Enter the translation vector:";
    int tx, ty;
    cin >> tx >> ty;
    setcolor(RED);
    x = x + tx;
    y = y + ty;
    x2 = x2 + tx;
    y2 = y2 + ty;
    line(x, y, x2, y2);
}

void rotateLine() {
    cout << "Enter the angle:";
    int degree, radian;
    cin >> degree;
    radian = (degree * 3.14) / 180;
    setcolor(GREEN);
    x3 = x2 - (((x2 - x) * cos(radian)) - ((y2 - y) + sin(radian)));
    y3 = y2 - (((x2 - x) * sin(radian)) + ((y2 - y) * cos(radian)));
    line(x2, y2, x3, y3);
    x = x2;
    y = y2;
    x2 = x3;
    y2 = y3;
}

void scaleLine() {
    cout << "Enter the scaling factor:";
    int sx, sy;
    cin >> sx >> sy;
    setcolor(BLUE);
    x = x * sx;
    y = y * sy;
    x2 = x2 * sx;
    y2 = y2 * sy;
    line(x, y, x2, y2);
}

int main() {
    int gdriver = DETECT, gmode, error;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver, &gmode, data);


    cout << "Enter line coordinates" << endl;
    cin >> x >> y >> x2 >> y2;
    line(x, y, x2, y2);

    while (true) {
        cout << "Enter option: 1) translation 2)rotation 3)scaling 4)exit" << endl;
        int n;
        cin >> n;
        if (n == 4)
            break;
        if (n == 1)
            translateLine();
        if (n == 2)
            rotateLine();
        if (n == 3)
            scaleLine();
    }
    closegraph();
    return 0;
}
