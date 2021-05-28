// Midpoint Line Algo Program

#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

// main function
void midPoint(int X1, int Y1, int X2, int Y2) {
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    
    // case 1 
    if (dy <= dx) {
        int d = dy - (dx / 2);
        int x = X1, y = Y1;

        putpixel (x,y,RED);

        while (x < X2) {
            x++;
            if (d < 0)
                d = d + dy;
            else {
                d += (dy - dx);
                y++;
            }
            putpixel (x,y,RED);
        }
    }
    // case 2 
    else {
        int d = dx - (dy / 2);
        int x = X1, y = Y1;

        putpixel (x,y,RED);

        while (y < Y2) {
            y++;

            if (d < 0)
                d = d + dx;
            else {
                d += (dx - dy);
                x++;
            }
            putpixel (x,y,RED);
        }
    }
}


int main() {
    int gdriver=DETECT, gmode, error;
	char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver,&gmode,data);
    
    // take input
    int x1,y1,x2,y2;
    cout<<"Enter co-ordinates of first point: ";
    cin>>x1>>y1;
    cout<<"Enter co-ordinates of second point: ";
    cin>>x2>>y2;
    
    midPoint(x1, y1, x2, y2);
    
    getch();

    return 0;
}
