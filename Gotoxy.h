#ifndef HEADERFILE_Gotoxy
#define HEADERFILE_Gotoxy

#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
using namespace std;

#define ARRIBA 72 
#define IZQUIERDA 75 
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y){
    HANDLE hCon; 
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; 
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

void OcultarCursor(){
    HANDLE hCon; 
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 0;
    cci.bVisible = FALSE;


    SetConsoleCursorInfo(hCon, &cci);
}

void PintarCarriles(){
    for(int i=4 ; i<45 ; i++){
        gotoxy(2,i);  printf("%c",186);

        gotoxy(19,i);  printf("%c",186);

        gotoxy(36,i);  printf("%c",186);

        gotoxy(53,i); printf("%c",186);

        gotoxy(70,i); printf("%c",186);
    }

}



#endif