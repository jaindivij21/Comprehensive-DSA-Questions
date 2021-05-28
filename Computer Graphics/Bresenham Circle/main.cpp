
// Bressenham Circle Program

#include<iostream>
#include <graphics.h>

using namespace std;

// Applying 8 way symmetry with each showcasing different color
void EightWaySymmetricPlot(int xc, int yc, int x, int y) {
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, 12);
    putpixel(y + xc, -x + yc, 14);
    putpixel(-y + xc, -x + yc, 15);
    putpixel(-y + xc, x + yc, 6);
}

// main function
void BresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r, d = 3 - (2 * r);
    EightWaySymmetricPlot(xc, yc, x, y);

    while (x <= y) {
        if (d <= 0) {
            d = d + (4 * x) + 6;
        } else {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        EightWaySymmetricPlot(xc, yc, x, y);
    }
}

int main() {

    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver,&gmode,data);

    error = graphresult();

    int xc, yc, r;

    if (error != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(error));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }

    // input the circle coordinates
    cout<<"Enter the values of xc and yc :"<<endl;
    cin >> xc >> yc;
    cout<<"Enter the value of radius  :"<<endl;
    cin>>r;

    // main function
    BresenhamCircle(xc, yc, r);

    getch();

    closegraph();

    return 0;
}
