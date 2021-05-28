#include<iostream>
#include<graphics.h>

using namespace std;

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;

	p=2*dy-dx;

	// draw the line
	while(x<x1)
	{
        putpixel(x,y,RED);
        x++;
		if(p>=0)
		{
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			p=p+2*dy;
		}
		
	}
}

int main()
{
	int gdriver=DETECT, gmode, error;
	char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gdriver,&gmode,data);

	int x1, y1, x2, y2;
	
	// Input values
	cout<<"Enter co-ordinates of first point: ";
	cin>>x1>>y1;

	cout<<"Enter co-ordinates of second point: ";
	cin>>x2>>y2;

	drawline(x1, y1, x2, y2);

    getch();

	return 0;
}