#include <iostream>
#include <windows.h>
#include <conio.h>
#include "mapas.h"
#include "personagem.h"

using namespace std;

// bool podeMover(int novoX, int novoY, int mapa[10][10]){
//     if(novoX >= 0 && novoX < 10 && novoY >= 0 && novoY < 10){
//         if(mapa[novoX][novoY] == 0){
//             return true;
//         }
//     }
//     return false;
// }

// void moverPersonagem(int &x, int &y, int direcao, int mapa[10][10]){
//     int novoX = x;
//     int novoY = y;

//     switch (direcao){
//         case 0: novoX = x - 1; break;
//         case 1: novoX = x + 1; break;
//         case 2: novoY = y - 1; break;
//         case 3: novoY = y + 1; break;
//     }

//     if(podeMover(novoX, novoY, mapa)){
//         x = novoX;
//         y = novoY;
//     }
// }

int main(){
        ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        //INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    int mapa[10][10] = {1,1,1,1,1,1,1,1,1,1,
                        0,0,0,0,1,0,0,1,1,1,
                        0,0,0,0,1,0,0,1,1,1,
                        0,0,0,0,1,0,0,1,1,1,
                        0,0,0,0,0,0,0,1,1,1,
                        0,0,0,0,0,0,0,1,1,1,
                        0,0,0,0,1,0,0,1,1,1,
                        0,0,0,0,0,0,0,1,1,1,
                        0,0,0,0,0,0,0,1,1,1,
                        1,1,1,1,1,1,1,1,1,1}; 
    
    int x = 2;
    int y = 2;

    while(true){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for(int i=0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i == x && j == y){
                    cout << char(64);
                } else {
                    switch(mapa[i][j]){
                        case 0: cout << " "; break;
                        case 1: cout << char(219);
                    }
                }
            }
            cout << "\n";
        }

        char tecla;
        if(_kbhit()){
            tecla = getch();
            switch(tecla)
            {
                case 'w': moverPersonagem(x, y, 0, mapa); break;
                case 's': moverPersonagem(x, y, 1, mapa); break;
                case 'a': moverPersonagem(x, y, 2, mapa); break;
                case 'd': moverPersonagem(x, y, 3, mapa); break;
            }
        }
    }                      
}