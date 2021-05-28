#include <cstdio>
#include <iostream>
#include <conio.h>
#include "defs.h"

using namespace std;

int main(){
    cout<<"\n";
    cout<<"---------------Welcome to the game of Chess---------------"<<endl;
    cout<<"\n\n";
    string name1, name2;
    char p1Color, p2Color;

    cout<<"Enter player 1 name & Colour (W/B) (e.g. 'Divij W')"<<endl;
    cin>>name1>>p1Color;
    cout<<"Enter player 2 name (e.g. 'Deepak')"<<endl;
    cin>>name2;
    p2Color = (p1Color=='W')?'B':'W';

    cout<<"\n\n\n";

    playGame(name1, name2, p1Color, p2Color);
    getch();
}
