#ifndef HEADERFILE_Obstaculos
#define HEADERFILE_Obstaculos

#include "Gotoxy.h"

#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
using namespace std;

class Obstaculos{
    private: 
    int x,y;
    
    public: 
    Obstaculos(int _x, int _y); //si quiero que salgan en un lugar especifico
    Obstaculos(); // random 
    void pintar();
    void mover();

    int getx(){return x;}
    int gety(){return y;}

};

Obstaculos::Obstaculos(int _x, int _y){
    x = _x; 
    y = _y;
}

Obstaculos::Obstaculos(){ //x random (en medio de los carriles)
    
    y = rand()%4+1; 

    int aux = rand()%4+1 ; 

    switch (aux)
    {
    case 1:
        x = 9; break;
    case 2:
        x = 26; break;
    case 3:
        x = 43; break;
    case 4:
        x = 60; break;
    
    default:
        break;
    }
}

void Obstaculos::pintar(){
    gotoxy(x,y); printf("?"); //printf("%c",219);

}
void Obstaculos::mover(){
    gotoxy(x,y); printf(" ");
    y++;        //cayendo
    if(y>32){

        y = rand()%4+1;

        int aux = rand()%4+1 ; 

        switch (aux)
        {
        case 1:
            x = 9; break;
        case 2:
            x = 26; break;
        case 3:
            x = 43; break;
        case 4:
            x = 60; break;
    
        default:
            break;
        }

    }
    pintar();
}



#endif