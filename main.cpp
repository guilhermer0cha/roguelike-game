#include <iostream>
#include <windows.h>
#include <conio.h>
#include "mapas.h"
#include "personagem.h"

using namespace std;

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

    auto mapaAtual = mapa1;

    int x = 2;
    int y = 2;

    while(true){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        for(int i=0; i < 10; i++){
            for(int j = 0; j < 20; j++){
                if(i == x && j == y){
                    cout << char(64);
                } else {
                    switch(mapaAtual[i][j]){
                        case 0: cout << " "; break;
                        case 1: cout << char(219); break;
                        case 2: cout << "A"; break;
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
                case 'w': moverPersonagem(x, y, 0, mapaAtual); break;
                case 's': moverPersonagem(x, y, 1, mapaAtual); break;
                case 'a': moverPersonagem(x, y, 2, mapaAtual); break;
                case 'd': moverPersonagem(x, y, 3, mapaAtual); break;
            }
        }
    }                      
}