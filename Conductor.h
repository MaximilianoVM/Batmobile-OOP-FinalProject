#ifndef HEADERFILE_Conductor
#define HEADERFILE_Conductor

#include "Gotoxy.h"

class Conductor{
    private: 
    int x, y;
    int corazones; 
    int vidas;

    public:
    Conductor(int _x, int _y, int _corazones, int _vidas);
    void pintar();
    void borrar();
    void mover();  

    void imprimirSalud();
    void morir();

    int getx(){return x;}
    int gety(){return y;}
    int getVidas(){return vidas;}
    void COR(){corazones--;}

};

Conductor::Conductor(int _x, int _y, int _corazones, int _vidas){
    corazones = _corazones;
    vidas     = _vidas;
    x = _x; 
    y = _y;
}

void Conductor::pintar(){
    gotoxy(x,y);   printf("%c%c %c%c",205,205,205,205);
    gotoxy(x,y+1); printf("%c%c %c%c",223,223,223,223);
    gotoxy(x,y+2); printf("%c%c %c%c",30,223,223,30);
    gotoxy(x,y+3); printf("%c%c %c%c",219,178,178,219);
}

void Conductor::borrar(){
    gotoxy(x,y);   printf("       ");
    gotoxy(x,y+1); printf("       ");
    gotoxy(x,y+2); printf("       ");
    gotoxy(x,y+3); printf("       ");

}

void Conductor::mover(){

    if( kbhit() ){ //si se ha presionado una tecla

            char tecla = getch(); //se recibe la tecla

            borrar();

            if(tecla == IZQUIERDA && x   > 10 ){ x-=17; }
            if(tecla == DERECHA   && x+6 < 60){ x+=17; }
            if(tecla == ARRIBA    && y   > 5 ){ y-=5; }
            if(tecla == ABAJO     && y+3 < 40){ y+=5; }

            if(tecla == 'e') { corazones--;} //prueba

            pintar();
            imprimirSalud();
        }

}

void Conductor::imprimirSalud(){

    gotoxy(50,2); printf("VIDAS %d", vidas);
    gotoxy(64, 2); printf("Salud");
    gotoxy(70, 2); printf("      ");

    for(int i=0 ; i< corazones ; i++){
        gotoxy(70+i, 2); printf("%c",3);
    }
}

void Conductor::morir(){
    if(corazones == 0){
        borrar();
        gotoxy(x,y);   printf("   **   "); //animacion muerte
        gotoxy(x,y+1); printf("  ****  ");
        gotoxy(x,y+2); printf(" * ** * ");
        gotoxy(x,y+3); printf("  * *   ");
        Sleep(300); //milisegundos
        borrar();
        
        gotoxy(x,y);   printf(" * ** * ");
        gotoxy(x,y+1); printf("  * **  ");
        gotoxy(x,y+2); printf(" * ** * ");
        gotoxy(x,y+3); printf("  ** *  ");
        Sleep(300);
        borrar();

        vidas--;
        corazones =3; 
        imprimirSalud();
        pintar();

    }
}

#endif