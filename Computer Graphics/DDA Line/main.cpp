// DDA Line Algo 

#include<iostream>
#include<graphics.h>
using namespace std;

// modulas :: absolute value
int abs (int n){
     return ( (n>0) ? n : ( n * (-1)));
}

int main(){
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
        
    initgraph(&gd, &gm, data);

    // Input points
    int x1,y1,x2,y2;
    int dx,dy;

        cout<<"Enter co-ordinates of first point: ";
	    cin>>x1>>y1;
	    cout<<"Enter co-ordinates of second point: ";
	    cin>>x2>>y2;


    dx = float(x2 - x1);
    dy = float(y2 - y1);

    // slope
    float steps = abs((dx)) > abs((dy)) ? abs((dx)) : abs((dy));
    float Xinc = dx/steps;
    float Yinc = dy/steps;

    float X = x1;
    float Y = y1;

    // Draw the line
    for(int i = 1; i <= steps; i++)
        {   
            putpixel (X,Y,RED);
            X += Xinc;
            Y += Yinc;
            delay(100);
        }

    getch();

    closegraph();

    getch();
    
    return 0;
}