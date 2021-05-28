// Mid Point Circle Program

#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int x,int y,int r)
{
    int x2,y2,p;
    x2=0;
    y2=r;
    p=1-r;

    do{
        putpixel(x+x2,y+y2,WHITE);
        putpixel(x+x2,y-y2,WHITE);
        putpixel(x-x2,y+y2,WHITE);
        putpixel(x-x2,y+y2,WHITE);
        putpixel(x+y2,y+x2,WHITE);
        putpixel(x+y2,y-x2,WHITE);
        putpixel(x-y2,y+x2,WHITE);
        putpixel(x-y2,y-x2,WHITE);
        
        // the 2 cases for next value of points
        if(p<0){
            x2++;
            y2=y2;
            p=p+2*x2+2;
        }
        else{
            x2=x2+1;
            y2=y2-1;
            p=p+2*x2+1-2*y2;


        }
    }while(x<y);

    
    closegraph();
    
}

int main()
{   
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
	char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver,&gmode,data);
    
    // input the coordinates
    int x,y,r;
    cout<<"Enter co-ordinates of the centre: ";
	cin>>x>>y;
    cout<<"Enter the radius: ";
	cin>>r;

    // make circle
    circle(x,y,r);

    getch();
    return 0;
    
}