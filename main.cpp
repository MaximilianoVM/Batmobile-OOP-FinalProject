#include "Conductor.h"
#include "Obstaculos.h"
#include <time.h>

int main(){
    srand(time(NULL)); 

    OcultarCursor();

    Conductor C(9,25, 3, 3);
    C.pintar();
    C.imprimirSalud();

    list<Obstaculos*> Obs;
    list<Obstaculos*>::iterator itO;


    for(int i=0 ; i< 5 ; i++){
        Obs.push_back( new Obstaculos() );
        /*
        una lista de OBSTACULOS pero en new voy a poner un rand para diferentes 
        newOBSTACULO1 , newOBSTACULO2 , etc 
        polimorfismo va a salir de usar elementos de Obs con distintos resultados
        */
    }
    

    bool gameOver = false;

    while(gameOver == false){
        OcultarCursor(); //parece que no sirve
        PintarCarriles();

        for(itO=Obs.begin() ; itO !=Obs.end() ; itO++){ 
            (*itO)->mover();
        }

        C.morir();
        C.mover();
        Sleep(50);

    }

}