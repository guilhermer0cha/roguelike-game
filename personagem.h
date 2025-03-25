#ifndef PERSONAGEM_H
#define PERSONAGEM_H

bool podeMover(int novoX, int novoY, int mapa[10][10]){
    if(novoX >= 0 && novoX < 10 && novoY >= 0 && novoY < 10){
        if(mapa[novoX][novoY] == 0){
            return true;
        }
    }
    return false;
}

void moverPersonagem(int &x, int &y, int direcao, int mapa[10][10]){
    int novoX = x;
    int novoY = y;

    switch (direcao){
        case 0: novoX = x - 1; break;
        case 1: novoX = x + 1; break;
        case 2: novoY = y - 1; break;
        case 3: novoY = y + 1; break;
    }

    if(podeMover(novoX, novoY, mapa)){
        x = novoX;
        y = novoY;
    }
}

#endif